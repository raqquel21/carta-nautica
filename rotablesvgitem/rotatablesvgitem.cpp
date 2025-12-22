#include "rotatablesvgitem.h"

RotatableSvgItem::RotatableSvgItem(const QString &fileName, QGraphicsItem *parent)
    : QGraphicsSvgItem(fileName, parent)
    , m_mode(None)
{
    // Quitamos ItemIsMovable para moverlo manualmente solo desde el centro
    // Habilitamos Hover para cambiar el cursor al pasar por encima
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

void RotatableSvgItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QRectF bounds = boundingRect();
    QPointF pos = event->pos();
    qreal width = bounds.width();
    qreal zoneSize = width * 0.15; // 15% para las zonas de rotación

    m_lastMousePos = event->scenePos();

    // Función auxiliar lambda para cambiar el pivote sin que la regla salte
    auto setPivotSmart = [&](QPointF newPivotLocal) {
        // 1. Guardamos dónde está ese punto visualmente AHORA MISMO en la escena
        QPointF anchorSceneBefore = mapToScene(newPivotLocal);

        // 2. Cambiamos el punto de origen de la transformación
        setTransformOriginPoint(newPivotLocal);

        // 3. Vemos dónde ha ido a parar ese punto tras el cambio (aquí ocurre el salto)
        QPointF anchorSceneAfter = mapToScene(newPivotLocal);

        // 4. Calculamos la diferencia y movemos la regla para compensar el salto
        QPointF diff = anchorSceneBefore - anchorSceneAfter;
        setPos(this->pos() + diff);

        // 5. Guardamos este punto como el pivote fijo para la rotación
        m_pivotPoint = anchorSceneBefore;
    };

    if (pos.x() < zoneSize) {
        // --- Clic en IZQUIERDA -> Pivote en DERECHA ---
        m_mode = Rotating;
        setPivotSmart(QPointF(width, bounds.height() / 2));

    } else if (pos.x() > width - zoneSize) {
        // --- Clic en DERECHA -> Pivote en IZQUIERDA ---
        m_mode = Rotating;
        setPivotSmart(QPointF(0, bounds.height() / 2));

    } else {
        // --- Clic en CENTRO -> MOVER ---
        m_mode = Moving;
        setCursor(Qt::ClosedHandCursor);
    }

    event->accept();
}

void RotatableSvgItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_mode == Moving) {
        // Mover manualmente sumando la diferencia
        QPointF delta = event->scenePos() - m_lastMousePos;
        setPos(pos() + delta);
        m_lastMousePos = event->scenePos();
    } else if (m_mode == Rotating) {
        // Calcular ángulo absoluto entre el pivote y el ratón
        QLineF line(m_pivotPoint, event->scenePos());
        double angle = -line.angle();

        // Corregir orientación si estamos pivotando sobre el lado derecho
        // (porque la regla "mira" hacia la izquierda en ese caso)
        if (transformOriginPoint().x() > 0) {
            angle += 180;
        }

        setRotation(angle);
    }
}

void RotatableSvgItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mode = None;
    hoverMoveEvent(nullptr); // Restaurar el cursor correcto
    QGraphicsSvgItem::mouseReleaseEvent(event);
}

void RotatableSvgItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QPointF pos = (event) ? event->pos() : mapFromScene(QCursor::pos());
    qreal width = boundingRect().width();
    qreal zoneSize = width * 0.15;

    if (pos.x() < zoneSize || pos.x() > width - zoneSize) {
        setCursor(Qt::SizeHorCursor);
    } else {
        setCursor(Qt::OpenHandCursor);
    }

    if (event)
        QGraphicsSvgItem::hoverMoveEvent(event);
}
