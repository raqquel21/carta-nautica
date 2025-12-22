#ifndef COMPASSITEM_H
#define COMPASSITEM_H

#include <QPen>
#include <QString>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent> // Necesario para mouse events
#include <QGraphicsSvgItem>         // Asegúrate de que este include esté aquí
#include <QPointF>                  // Necesario para QPointF
#include <QtMath>                   // Necesario para qRadiansToDegrees y atan2
#include <QGraphicsScene>


class CompassItem : public QGraphicsItemGroup
{
public:
    explicit CompassItem(QGraphicsItem *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:
    QGraphicsSvgItem *legLeft;
    QGraphicsSvgItem *legRight;

    enum Mode { None, Moving, RotatingRight, RotatingLeft, CompassRotate};
    Mode m_mode = None;

    qreal legLeftInitialAngle;
    qreal legRightInitialAngle;

    qreal mouseInitialAngle;
    QPointF dragStartScene;

    QGraphicsPathItem *currentArc;
    QPointF pivotScene;       // Centro del arco
    qreal startAngle = 0;         // Ángulo inicial en grados
    QPointF dragOffset;
    QPointF calculateOptimalPivot(QPointF fixedPivot, QPointF movingPoint);

    qreal lastAngle = 0.0;
    qreal accumulatedSpan = 0.0;

    // Modo shift:
    QGraphicsSvgItem* pivotLeg = nullptr;
    QGraphicsSvgItem* drawingLeg = nullptr;

    qreal drawingLegInitialAngle = 0.0;
    qreal initialGroupRotation = 0.0;

};


#endif // COMPASSITEM_H
