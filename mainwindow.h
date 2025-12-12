#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QItemSelection>
#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QString>
#include <QStringListModel>
#include "navigation.h"
#include "navtypes.h"
#include "qradiobutton.h"

#include <QDate>
#include <QRegularExpression>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPathItem>

#include <QPropertyAnimation>

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

    double scale = 1;
    void applyZoom(double factor);
    bool drawingMode = false;
    bool erasingMode = false;
    QPointF lastPoint;

    QGraphicsPathItem *currentPathItem = nullptr;
    QPainterPath currentPath;

    QPropertyAnimation *sidebarAnimation;
    bool sidebarVisible;

    int preg_actual = 1;
    QVector<Problem> problemas;
    QVector<QRadioButton *> respbotones;

    Navigation &nav = Navigation::instance();
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
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};
#endif // MAINWINDOW_H
