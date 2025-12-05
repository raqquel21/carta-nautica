#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "navigation.h"
#include "navtypes.h"
#include "qradiobutton.h"
#include <QItemSelection>
#include <QMainWindow>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QString>
#include <QStringListModel>

#include <QDate>
#include <QRegularExpression>

#include <QGraphicsView>
#include <QGraphicsScene>

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

    QPropertyAnimation *sidebarAnimation;
    bool sidebarVisible;

    int preg_actual = 1;
    QVector<Problem> problemas;
    QVector<QRadioButton*> respbotones;

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

};
#endif // MAINWINDOW_H
