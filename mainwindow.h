#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
private slots:
    void onLogInClicked();
    void zoomInS();
    void zoomOutS();
    void setupMap();

    //void completeProfile();
    //void enlace_reg();
    void onRegisterClicked();

};
#endif // MAINWINDOW_H
