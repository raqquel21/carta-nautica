#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Mostrar login al inicio
    ui->stackedWidget->setCurrentIndex(0);

    // CONECTAR botones YA EXISTENTES en tu .ui
    connect(ui->buttonLogIn, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->pushButtonVolver, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
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

    if (nickname.isEmpty()
        || password.isEmpty()) { // FALTARÍA AÑADIR LA VERIFICACION DE SI ESTÁ YA REGISTRADO
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }

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
