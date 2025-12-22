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

    // --- Coordenadas locales ---
    QPointF localLeft = legLeft->mapFromScene(scenePos);
    QPointF localRight = legRight->mapFromScene(scenePos);

    QRectF rectLeft = legLeft->boundingRect();
    QRectF rectRight = legRight->boundingRect();

    qreal hLeft = rectLeft.height();
    qreal hRight = rectRight.height();

    // Zona de rotación = 45% inferior
    qreal splitLeft = hLeft * 0.45;
    qreal splitRight = hRight * 0.45;

    // Margen lateral para descartar clics muy lejos de la pata
    qreal marginX = 10.0; // pixels

    bool clickedLeft = rectLeft.adjusted(-marginX, 0, marginX, 0).contains(localLeft);
    bool clickedRight = rectRight.adjusted(-marginX, 0, marginX, 0).contains(localRight);

    QString zoneLeft = (localLeft.y() >= hLeft - splitLeft) ? "BOTTOM" : "TOP";
    QString zoneRight = (localRight.y() >= hRight - splitRight) ? "BOTTOM" : "TOP";

    DBG << "[COMPASS] CLICK scene:" << scenePos;
    DBG << "[COMPASS]  LEFT:  contains=" << clickedLeft << "localY=" << localLeft.y()
        << "height=" << hLeft << "split=" << splitLeft << "zone=" << zoneLeft;
    DBG << "[COMPASS]  RIGHT: contains=" << clickedRight << "localY=" << localRight.y()
        << "height=" << hRight << "split=" << splitRight << "zone=" << zoneRight;

    // --------------------------------------------------
    // Lógica
    // --------------------------------------------------
    m_mode = None;
    currentArc = nullptr;

    if (clickedLeft && zoneLeft == "BOTTOM") {
        DBG << "[COMPASS] ? ACTION: ROTATE LEFT + DRAW";
        m_mode = RotatingLeft;

        pivotScene = legRight->mapToScene(legRight->transformOriginPoint());
        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        legLeftInitialAngle = legLeft->rotation();

        startAngle = mouseInitialAngle;
        lastAngle = startAngle;
        accumulatedSpan = 0.0;

        currentArc = new QGraphicsPathItem();
        currentArc->setPen(QPen(Qt::blue, 2));
        scene()->addItem(currentArc);
    } else if (clickedRight && zoneRight == "BOTTOM") {
        DBG << "[COMPASS] ? ACTION: ROTATE RIGHT";
        m_mode = RotatingRight;

        pivotScene = legLeft->mapToScene(legLeft->transformOriginPoint());
        mouseInitialAngle = QLineF(pivotScene, scenePos).angle();
        legRightInitialAngle = legRight->rotation();
    } else {
        DBG << "[COMPASS] ? ACTION: MOVE";
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
