#ifndef MOVABLESVGITEM_H
#define MOVABLESVGITEM_H

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

class MovableSvgItem : public QGraphicsSvgItem
{
public:
    explicit MovableSvgItem(const QString &fileName, QGraphicsItem *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    QPointF m_lastMousePos;

};

#endif // MOVABLESVGITEM_H
