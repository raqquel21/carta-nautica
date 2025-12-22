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

    // Reset de estado
    m_mode = None;
    currentArc = nullptr;
    pivotLeg = nullptr;
    drawingLeg = nullptr;

    // Detectar si Shift está pulsado

    bool shiftPressed = event->modifiers() & Qt::ShiftModifier;
    if (shiftPressed) {
        QPointF scenePos = event->scenePos();

        // 1. Obtener las puntas reales de las patas (bottomRight del SVG)
        QPointF leftTip  = legLeft->mapToScene(legLeft->boundingRect().bottomRight());
        QPointF rightTip = legRight->mapToScene(legRight->boundingRect().bottomRight());

        // 2. Determinar cuál es la pata fija (la más lejana al click suele ser la fija,
        // o la más cercana la que "arrastra" el dibujo)
        if (QLineF(scenePos, leftTip).length() < QLineF(scenePos, rightTip).length()) {
            drawingLeg = legLeft;
            pivotLeg   = legRight; // La derecha se queda fija
        } else {
            drawingLeg = legRight;
            pivotLeg   = legLeft;  // La izquierda se queda fija
        }

        // 3. EL CENTRO: La punta inferior de la pata fija
        pivotScene = pivotLeg->mapToScene(pivotLeg->boundingRect().bottomRight());

        // 4. Ángulo inicial desde el centro (punta fija) hacia el ratón
        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();

        // 5. Para el arco, el ángulo inicial es donde está la pata que dibuja
        QPointF drawingTip = drawingLeg->mapToScene(drawingLeg->boundingRect().bottomRight());
        startAngle = QLineF(pivotScene, drawingTip).angle();
        lastAngle = startAngle;
        accumulatedSpan = 0.0;

        currentArc = new QGraphicsPathItem();
        currentArc->setPen(QPen(Qt::blue, 2));
        scene()->addItem(currentArc);

        m_mode = CompassRotate;
        event->accept();
        return;
    }


    // if (!legLeft || !legRight || !pivotLeg) {
    //     qWarning() << "[DEBUG] puntero nulo, saltando debug";
    // } else {
    //     QPointF pivotTipScene = pivotLeg->mapToScene(pivotLeg->transformOriginPoint());
    //     QPointF leftTipScene  = legLeft->mapToScene(legLeft->boundingRect().bottomRight());
    //     QPointF rightTipScene = legRight->mapToScene(legRight->boundingRect().bottomRight());

    //     qDebug() << "[DEBUG] Shift pressed:";
    //     qDebug() << "Mouse scenePos:" << scenePos;
    //     qDebug() << "Pivot tip scene:" << pivotTipScene;
    //     qDebug() << "Left tip scene:" << leftTipScene;
    //     qDebug() << "Right tip scene:" << rightTipScene;
    //     qDebug() << "Initial group rotation:" << rotation();
    // }



    // --------------------------------------------------
    // Puntas reales en coordenadas de escena (sin shift)
    // --------------------------------------------------
    QPointF leftTipScene = legLeft->mapToScene(
        legLeft->boundingRect().bottomRight()
        );

    QPointF rightTipScene = legRight->mapToScene(
        legRight->boundingRect().bottomRight()
        );

    // Distancias del click a cada punta
    qreal distLeft  = QLineF(scenePos, leftTipScene).length();
    qreal distRight = QLineF(scenePos, rightTipScene).length();

    // Umbral de activación (ajustable)
    const qreal ROTATE_RADIUS = 20.0;

    DBG << "CLICK scene:" << scenePos;
    DBG << "  distLeft =" << distLeft;
    DBG << "  distRight=" << distRight;

    // --------------------------------------------------
    // Decisión de acción
    // --------------------------------------------------
    if (distLeft < ROTATE_RADIUS && distLeft <= distRight) {
        DBG << "? ACTION: ROTATE LEFT + DRAW";

        m_mode = RotatingLeft;

        pivotScene = legRight->mapToScene(
            legRight->transformOriginPoint()
            );

        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        legLeftInitialAngle = legLeft->rotation();

        startAngle = mouseInitialAngle;
        lastAngle = startAngle;
        accumulatedSpan = 0.0;

        currentArc = new QGraphicsPathItem();
        currentArc->setPen(QPen(Qt::blue, 2));
        scene()->addItem(currentArc);
    }
    else if (distRight < ROTATE_RADIUS) {
        DBG << "? ACTION: ROTATE RIGHT";

        m_mode = RotatingRight;

        pivotScene = legLeft->mapToScene(
            legLeft->transformOriginPoint()
            );

        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        legRightInitialAngle = legRight->rotation();
    }
    else {
        DBG << "? ACTION: MOVE";

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
            QPointF tipCurrent = legLeft->mapToScene(
                legLeft->boundingRect().bottomRight()
                );

            qreal radius = QLineF(pivotScene, tipCurrent).length();
            QRectF arcRect(
                pivotScene.x() - radius,
                pivotScene.y() - radius,
                2 * radius,
                2 * radius
                );

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
        // No dibuja arco
    }

    else if (m_mode == CompassRotate) {
        QPointF mousePos = event->scenePos();

        // 1. Calcular cuánto ha movido el usuario el ratón respecto al centro
        qreal currentMouseAngle = QLineF(pivotScene, mousePos).angle();
        qreal deltaAngle = currentMouseAngle - mouseInitialAngle;

        // Normalizar ángulo para evitar saltos de 0 a 360
        if (deltaAngle > 180)  deltaAngle -= 360;
        if (deltaAngle < -180) deltaAngle += 360;

        // 2. Rotar el compás completo alrededor de la punta fija
        // Guardamos la posición de la punta antes de rotar
        QPointF tipBefore = pivotLeg->mapToScene(pivotLeg->boundingRect().bottomRight());

        // Aplicamos rotación al grupo
        this->setRotation(this->rotation() - deltaAngle);

        // 3. CORRECCIÓN DE POSICIÓN (Crucial)
        // Tras rotar, la punta se habrá movido. La movemos de vuelta a pivotScene.
        QPointF tipAfter = pivotLeg->mapToScene(pivotLeg->boundingRect().bottomRight());
        QPointF offset = tipBefore - tipAfter;
        this->moveBy(offset.x(), offset.y());

        // 4. Actualizar estado para el siguiente frame
        mouseInitialAngle = currentMouseAngle;

        // 5. Dibujar el arco
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
    currentArc = nullptr;
    event->accept();
}

