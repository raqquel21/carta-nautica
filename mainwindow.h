#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include<QStringListModel>
#include <QItemSelection>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDate>
#include <QRegularExpression>

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

private slots:
    void onLogInClicked();
    //void completeProfile();
    //void enlace_reg();
    void onRegisterClicked();
};
#endif // MAINWINDOW_H
