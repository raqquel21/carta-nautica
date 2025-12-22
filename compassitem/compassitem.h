#ifndef COMPASSITEM_H
#define COMPASSITEM_H

#include <QItemSelection>
#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QString>
#include <QStringListModel>
#include <QtMath>

#include <QDate>
#include <QRegularExpression>

#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>

#include <QPropertyAnimation>

#include <QGraphicsSceneMouseEvent> // Necesario para mouse events
#include <QGraphicsSvgItem>         // Asegúrate de que este include esté aquí
#include <QPointF>                  // Necesario para QPointF
#include <QtMath>                   // Necesario para qRadiansToDegrees y atan2

#include <QEvent>
#include <QList>
#include <QToolButton>

#include <QLineEdit>

class CompassItem : public QGraphicsItemGroup
{
public:
    explicit CompassItem(QGraphicsItem *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    bool isInTipZone(QGraphicsItem *leg,
                     const QPointF &scenePos,
                     const QPointF &pivotScene);

private:
    QGraphicsSvgItem *legLeft;
    QGraphicsSvgItem *legRight;

    enum Mode { None, Moving, RotatingRight, RotatingLeft};
    Mode m_mode = None;
    bool rotatingLeft = false;

    QPointF lastMousePos;
    QPointF pivotScenePoint;
    QPointF dragStartScene;

    qreal legLeftInitialAngle;
    qreal legRightInitialAngle;
    qreal mouseInitialAngle;

    bool rotatingRight;
    QGraphicsPathItem *currentArc;
    QPointF pivotScene;       // Centro del arco
    qreal startAngle = 0;         // Ángulo inicial en grados
    qreal radius = 0;             // Radio del arco
    QGraphicsPathItem *arcItem;
    QPointF tipStart;
    QPointF dragOffset;
    QPointF calculateOptimalPivot(QPointF fixedPivot, QPointF movingPoint);

    qreal lastAngle = 0.0;
    qreal totalAngle = 0.0;
    bool arcStarted = false;
    QPainterPath arcPath;

    static qreal normalizeAngleDelta(qreal delta);


};


#endif // COMPASSITEM_H
