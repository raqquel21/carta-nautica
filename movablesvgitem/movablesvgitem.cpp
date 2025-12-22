#include "movablesvgitem.h"

MovableSvgItem::MovableSvgItem(const QString &fileName, QGraphicsItem *parent)
    : QGraphicsSvgItem(fileName, parent)
{
    setAcceptHoverEvents(true); // Habilita hover para cambiar cursor
}

void MovableSvgItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_lastMousePos = event->scenePos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
    } else {
        event->ignore();
    }
}

void MovableSvgItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF delta = event->scenePos() - m_lastMousePos;
    moveBy(delta.x(), delta.y());
    m_lastMousePos = event->scenePos();
    event->accept();
}

void MovableSvgItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    event->accept();
}

void MovableSvgItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    event->accept();
}
