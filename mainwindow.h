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

#include <QGraphicsPathItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>

#include <QPropertyAnimation>

#include <QGraphicsSceneMouseEvent> // Necesario para mouse events
#include <QGraphicsSvgItem>         // Asegúrate de que este include esté aquí
#include <QPointF>                  // Necesario para QPointF

#include <QEvent>
#include <QList>
#include <QToolButton>

#include <QLineEdit>

#include "compassitem/compassitem.h"       // compas
#include "movablesvgitem/movablesvgitem.h" //transportador
#include "usermanager/usermanager.h"
#include "rotablesvgitem/rotatablesvgitem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


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

    QList<QToolButton *> exclusiveButtons;

    void actualizarFotoBoton(QPushButton *boton, const QImage &img);
    void actualizarIconoAction(QAction *action, const QImage &img);
    void onGuardarCambiosPerfil();
    QString rutaImagenRegistro;

    double scale = 1;
    int grosorLapiz;
    QColor currentColor = Qt::red;
    void applyZoom(double factor);
    bool drawingMode = false;
    bool erasingMode = false;
    bool markingMode = false;
    bool measuringMode = false;
    bool eyeActive = false;
    bool textMode = false;

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

    int preg_actual = 0;
    QVector<Problem> problemas;
    QVector<QRadioButton *> respbotones;

    Navigation &nav = Navigation::instance();
    User *currentUser = nullptr;
    int sessionHits = 0;
    int sessionFaults = 0;
    QDateTime sessionStart;

    UserManager userManager; // gestor de usuarios

    RotatableSvgItem *rulerSvgItem = nullptr; // Puntero al objeto SVG
    bool svgRulerActive = false;

    MovableSvgItem *protractorSvgItem = nullptr;
    bool svgProtractorActive = false;

    CompassItem *compassItem = nullptr;

private slots:
    void onZoomInButtonClicked();
    void onZoomOutButtonClicked();
    void onZoomSliderChanged(int value);
    //void setupMap();

    //void completeProfile();
    //void enlace_reg();
    void onLogInClicked();
    void onRegisterClicked();

    void toggleSidebar();

    void togglePassword(QLineEdit *text, QToolButton *button);

    void listarPreguntas();
    void showNextQuestion();
    void checkQuestion();
    void onNextClicked();
    void returnToProblems();
    void mostrarHistorial();
    void filtrarHistorial();

    void SeleccionarImagenPerfil();

    void togglePencil();
    void SliderLapiz(int value);
    void cambiarColor();

    void toggleCursor();
    void toggleRubber();
    void placeMark();
    void toggleSvgRuler(bool checked);
    void toggleCompass(bool checked);
    void toggleSvgProtractor(bool checked);
    void togglePointExtremes();
    void toggleText();

    QPointF snapToRuler(QPointF originalPos);
    QPointF protractorCenter();

    void clearAllDrawings();
    void confirmAndClearAllDrawings();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // MAINWINDOW_H
