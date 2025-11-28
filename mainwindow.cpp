#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // Mostrar login al inicio
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->buttonLogIn, &QPushButton::clicked, this, &MainWindow::onLogInClicked);

    connect(ui->pushButtonVolver, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->perfil, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->salirPerfil, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLogInClicked()
{
    QString nickname = ui->enter_nickname->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();

    if (nickname.isEmpty()|| password.isEmpty()) {
        ui->stackedWidget->setCurrentIndex(0); // Que no pueda pasar al siguiente paso si no se ha logeado bien
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }
    ui->stackedWidget->setCurrentIndex(1); // Si lo ha hecho bien, adelante

    // QModelIndex selectedIndex = ui->listView->currentIndex();
    // if (selectedIndex.isValid() && (selectedIndex.row() != -1)) {
    //     // Modificar el elemento seleccionado
    //     listModelS->setData(selectedIndex, fullName);

    // } else {
    //     // Añadir nuevo elemento
    //     QStandardItem *item = new QStandardItem(fullName);
    //     listModelS->appendRow(item);
    // }

    // QPixmap avatar;
    // switch(avatarIndex){
    // case 0:
    //     avatar = QPixmap(":/resources/images/Lloroso.png");
    //     break;
    // case 1:
    //     avatar = QPixmap(":/resources/images/Pregunta.png");
    //     break;
    // case 2:
    //     avatar = QPixmap(":/resources/images/Sonriente.png");
    //     break;
    // }

    // ui->listView->clearSelection();
    // ui->listView->selectionModel()->clearCurrentIndex();

    // // Limpiar campos después de añadir o modificar
    // clearFields();
}
