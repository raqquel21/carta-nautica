#include "compassitem.h"

#define DBG qDebug().noquote() << "[COMPASS]"


// Cada pata se mueve de manera independiente (una dibuja y otra no)
// porque así se puede usar para medir las distancias
// Se mueve el compás desde la parte superior

// Si clickas shift y clickas al compás, rota sobre su punto de apoyo (la pata que no dibuja)

CompassItem::CompassItem(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent)
{
    setPos(70,0);
    legLeft = new QGraphicsSvgItem(":/images/compass_leg.svg");
    legRight = new QGraphicsSvgItem(":/images/compass_leg.svg");

    addToGroup(legLeft);
    addToGroup(legRight);

    legLeft->setPos(0, 0);
    legRight->setPos(0, 0);

    QRectF r = legLeft->boundingRect();
    //qDebug() << "BoundingRect:" << r;

    QPointF pivot(0, r.height() / 2.0);

    legLeft->setTransformOriginPoint(pivot);
    legRight->setTransformOriginPoint(pivot);

    legLeft->setRotation(90 - 15);
    legRight->setRotation(90 + 15);

    legLeft->setAcceptHoverEvents(true);
    legRight->setAcceptHoverEvents(true);

    setHandlesChildEvents(true);
    setFlags(QGraphicsItem::ItemIsSelectable);

    double scaleFactor = 2;
    setScale(scaleFactor);
    setZValue(1000);

    setData(Qt::UserRole, "tool_compass");
}

QPointF CompassItem::calculateOptimalPivot(QPointF fixedPivot, QPointF movingPoint)
{
    // Vector desde pivote fijo a la punta móvil
    QPointF vec = movingPoint - fixedPivot;

    // Queremos que la punta móvil esté "arriba" (y negativo en Y es hacia arriba en Qt)
    if (vec.y() > 0) {
        // Invertimos la apertura para mantener la punta arriba
        vec.setY(-vec.y());
    }

    return fixedPivot + vec;
}

void CompassItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton) {
        event->ignore();
        return;
    }

    QPointF scenePos = event->scenePos();
    m_mode = None;
    currentArc = nullptr;
    pivotLeg = nullptr;
    drawingLeg = nullptr;

    bool shiftPressed = event->modifiers() & Qt::ShiftModifier;

    // --- CASO 1: ROTACIÓN CON SHIFT (Dibuja arco) ---
    if (shiftPressed) {
        QPointF leftTip  = legLeft->mapToScene(legLeft->boundingRect().bottomRight());
        QPointF rightTip = legRight->mapToScene(legRight->boundingRect().bottomRight());

        if (QLineF(scenePos, leftTip).length() < QLineF(scenePos, rightTip).length()) {
            drawingLeg = legLeft;
            pivotLeg   = legRight;
        } else {
            drawingLeg = legRight;
            pivotLeg   = legLeft;
        }

        pivotScene = pivotLeg->mapToScene(pivotLeg->boundingRect().bottomRight());
        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        QPointF drawingTip = drawingLeg->mapToScene(drawingLeg->boundingRect().bottomRight());
        startAngle = QLineF(pivotScene, drawingTip).angle();
        lastAngle = startAngle;
        accumulatedSpan = 0.0;

        currentArc = new QGraphicsPathItem();
        currentArc->setPen(QPen(Qt::blue, 2));

        // AÑADIDO: Hacer el arco seleccionable
        currentArc->setFlags(QGraphicsItem::ItemIsSelectable);

        scene()->addItem(currentArc);

        m_mode = CompassRotate;
        event->accept();
        return;
    }

    QPointF leftTipScene = legLeft->mapToScene(legLeft->boundingRect().bottomRight());
    QPointF rightTipScene = legRight->mapToScene(legRight->boundingRect().bottomRight());

    qreal distLeft  = QLineF(scenePos, leftTipScene).length();
    qreal distRight = QLineF(scenePos, rightTipScene).length();
    const qreal ROTATE_RADIUS = 20.0;

    // --- CASO 2: ROTAR PATA IZQUIERDA (Dibuja arco) ---
    if (distLeft < ROTATE_RADIUS && distLeft <= distRight) {
        m_mode = RotatingLeft;
        pivotScene = legRight->mapToScene(legRight->transformOriginPoint());
        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        legLeftInitialAngle = legLeft->rotation();
        startAngle = mouseInitialAngle;
        lastAngle = startAngle;
        accumulatedSpan = 0.0;

        currentArc = new QGraphicsPathItem();
        currentArc->setPen(QPen(Qt::blue, 2));

        // AÑADIDO: Hacer el arco seleccionable
        currentArc->setFlags(QGraphicsItem::ItemIsSelectable);

        scene()->addItem(currentArc);
    }
    // --- CASO 3: ROTAR PATA DERECHA (No dibuja arco) ---
    else if (distRight < ROTATE_RADIUS) {
        m_mode = RotatingRight;
        pivotScene = legLeft->mapToScene(legLeft->transformOriginPoint());
        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        legRightInitialAngle = legRight->rotation();
    }
    // --- CASO 4: MOVER COMPÁS ---
    else {
        m_mode = Moving;
        dragStartScene = scenePos;
        dragOffset = scenePos - pos();
    }

    event->accept();
}

void CompassItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos();

    if (m_mode == Moving) {
        setPos(pos - dragOffset);
    }
    else if (m_mode == RotatingLeft) {
        QLineF line(pivotScene, pos);
        qreal deltaAngle = line.angle() - mouseInitialAngle;
        legLeft->setRotation(legLeftInitialAngle - deltaAngle);

        if (currentArc) {
            QPointF tipCurrent = legLeft->mapToScene(legLeft->boundingRect().bottomRight());
            qreal radius = QLineF(pivotScene, tipCurrent).length();
            QRectF arcRect(pivotScene.x() - radius, pivotScene.y() - radius, 2 * radius, 2 * radius);
            qreal currentAngle = QLineF(pivotScene, tipCurrent).angle();
            qreal delta = currentAngle - lastAngle;
            if (delta > 180)  delta -= 360;
            if (delta < -180) delta += 360;
            accumulatedSpan += delta;
            lastAngle = currentAngle;

            QPainterPath path;
            path.arcMoveTo(arcRect, startAngle);
            path.arcTo(arcRect, startAngle, accumulatedSpan);
            currentArc->setPath(path);
        }
    }
    else if (m_mode == RotatingRight) {
        QLineF line(pivotScene, pos);
        qreal deltaAngle = line.angle() - mouseInitialAngle;
        legRight->setRotation(legRightInitialAngle - deltaAngle);
    }
    else if (m_mode == CompassRotate) {
        QPointF mousePos = event->scenePos();
        qreal currentMouseAngle = QLineF(pivotScene, mousePos).angle();
        qreal deltaAngle = currentMouseAngle - mouseInitialAngle;

        if (deltaAngle > 180)  deltaAngle -= 360;
        if (deltaAngle < -180) deltaAngle += 360;

        QPointF tipBefore = pivotLeg->mapToScene(pivotLeg->boundingRect().bottomRight());
        this->setRotation(this->rotation() - deltaAngle);

        QPointF tipAfter = pivotLeg->mapToScene(pivotLeg->boundingRect().bottomRight());
        QPointF offset = tipBefore - tipAfter;
        this->moveBy(offset.x(), offset.y());

        mouseInitialAngle = currentMouseAngle;

        if (currentArc && drawingLeg) {
            QPointF drawingTip = drawingLeg->mapToScene(drawingLeg->boundingRect().bottomRight());
            qreal radius = QLineF(pivotScene, drawingTip).length();
            QRectF arcRect(pivotScene.x() - radius, pivotScene.y() - radius, 2 * radius, 2 * radius);
            qreal currentDrawingAngle = QLineF(pivotScene, drawingTip).angle();
            qreal angleStep = currentDrawingAngle - lastAngle;
            if (angleStep > 180)  angleStep -= 360;
            if (angleStep < -180) angleStep += 360;
            accumulatedSpan += angleStep;
            lastAngle = currentDrawingAngle;

            QPainterPath path;
            path.arcMoveTo(arcRect, startAngle);
            path.arcTo(arcRect, startAngle, accumulatedSpan);
            currentArc->setPath(path);
        }
    }
    event->accept();
}

void CompassItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mode = None;
    pivotLeg = nullptr;
    drawingLeg = nullptr;

    // Es importante soltar la referencia pero el arco ya tiene el flag persistente
    currentArc = nullptr;
    event->accept();
}
