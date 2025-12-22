#include "compassitem.h"

#define DBG qDebug().noquote() << "[COMPASS]"


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

    // --------------------------------------------------
    // Puntas reales en coordenadas de escena
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
    } else if (m_mode == RotatingLeft) {
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

            // Corrección del salto 360°
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
    } else if (m_mode == RotatingRight) {
        QLineF line(pivotScene, pos);
        qreal deltaAngle = line.angle() - mouseInitialAngle;
        legRight->setRotation(legRightInitialAngle - deltaAngle);

        // No dibuja arco
    }

    event->accept();
}

void CompassItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mode = None;
    currentArc = nullptr;
    event->accept();
}
