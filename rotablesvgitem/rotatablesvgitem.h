#ifndef ROTATABLESVGITEM_H
#define ROTATABLESVGITEM_H

#include <QString>
#include <QGraphicsSceneMouseEvent> // Necesario para mouse events
#include <QGraphicsSvgItem>         // Asegúrate de que este include esté aquí
#include <QPointF>                  // Necesario para QPointF
#include <QtMath>                   // Necesario para qRadiansToDegrees y atan2
#include <QGraphicsSceneMouseEvent>
#include <QLineF>
#include <QCursor>


class RotatableSvgItem : public QGraphicsSvgItem
{
public:
    explicit RotatableSvgItem(const QString &fileName, QGraphicsItem *parent = nullptr);

protected:
    // Declaramos las funciones que hemos implementado en el .cpp
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    // Variables internas para controlar el movimiento y rotación
    enum Mode { None, Moving, Rotating };
    Mode m_mode;
    QPointF m_lastMousePos;
    QPointF m_pivotPoint;
};


#endif // ROTATABLESVGITEM_H
