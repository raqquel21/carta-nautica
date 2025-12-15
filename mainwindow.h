#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QItemSelection>
#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QString>
#include <QStringListModel>
#include <QtMath>
#include "navigation.h"
#include "navtypes.h"
#include "qradiobutton.h"

#include <QDate>
#include <QRegularExpression>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPathItem>
#include <QGraphicsTextItem>

#include <QPropertyAnimation>

#include <QGraphicsSvgItem> // Asegúrate de que este include esté aquí
#include <QPointF> // Necesario para QPointF
#include <QtMath> // Necesario para qRadiansToDegrees y atan2
#include <QGraphicsSceneMouseEvent> // Necesario para mouse events


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class RotatableSvgItem : public QGraphicsSvgItem {
public:
    RotatableSvgItem(const QString &fileName, QGraphicsItem *parent = nullptr)
        : QGraphicsSvgItem(fileName, parent) {
        // Habilitar movimiento y selección por el framework
        setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges);
    }

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override {
        // Solo rotamos si se presiona la tecla Control (Ctrl)
        if (event->modifiers() & Qt::ControlModifier) {

            QPointF currentPos = event->pos();
            QPointF center = boundingRect().center();

            // Calcular el ángulo usando atan2
            qreal angle = atan2(currentPos.y() - center.y(), currentPos.x() - center.x());
            qreal newAngle = qRadiansToDegrees(angle);

            // Establecer el centro de rotación y aplicar la rotación
            setTransformOriginPoint(center);
            // El desplazamiento de 90 grados es común si el SVG de la regla es horizontal por defecto
            setRotation(newAngle + 90);

            event->accept();
        } else {
            // Si no hay tecla modificadora, permite el movimiento normal
            QGraphicsSvgItem::mouseMoveEvent(event);
        }
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsView *view;

    QGraphicsPixmapItem *mapItem = nullptr;

    double scale = 1;
    void applyZoom(double factor);
    bool drawingMode = false;
    bool erasingMode = false;
    bool markingMode = false;
    bool measuringMode = false;
    // --- 3.10 Marcar extremos del punto --- rakitraki
    bool eyeActive = false;
    void hidePointExtremes();
    void showPointExtremes(QGraphicsItem *point);

    QPointF lastPoint;
    QPointF rulerStartPoint;

    QGraphicsLineItem *currentRulerLine = nullptr;
    QGraphicsPathItem *currentPathItem = nullptr;
    // --- 3.10 Marcar extremos del punto --- rakitraki
    QGraphicsItemGroup *eyeProjectionGroup = nullptr;

    QPainterPath currentPath;

    QPropertyAnimation *sidebarAnimation;
    bool sidebarVisible;

    int preg_actual = 1;
    QVector<Problem> problemas;
    QVector<QRadioButton *> respbotones;

    Navigation &nav = Navigation::instance();

    RotatableSvgItem *rulerSvgItem = nullptr; // Puntero al objeto SVG
    bool svgRulerActive = false;
private slots:
    void zoomInS();
    void zoomOutS();
    void setupMap();

    //void completeProfile();
    //void enlace_reg();
    void onLogInClicked();
    void onRegisterClicked();

    void toggleSidebar();

    void showNextQuestion();

    void togglePencil();
    void toggleCursor();
    void toggleRubber();
    void placeMark();
    void toggleSvgRuler();

    // rakitraki
    void togglePointExtremes();

    void clearAllDrawings();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};


#endif // MAINWINDOW_H
