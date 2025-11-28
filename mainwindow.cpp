#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // Notación de las ventanas
    /*
     * Log in: 0
     * Registrarse: 1
     * Ventana principal: 2
     * Perfil: 3
     *
     */

    // Mostrar login al inicio
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->buttonLogIn, &QPushButton::clicked, this, &MainWindow::onLogInClicked);
    connect(ui->buttonRegister, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);


    connect(ui->pushButtonVolver, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->perfil, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->salirPerfil, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    // Configurar link del registro
    ui->registrarse->setTextFormat(Qt::RichText);
    ui->registrarse->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->registrarse->setOpenExternalLinks(false);

    ui->registrarse->setText("Don't have an account? <a href=\"registrar\">Register</a>");

    connect(ui->registrarse, &QLabel::linkActivated, this,
            [=](const QString &link){
                //qDebug() << "Link activado:" << link;
                ui->stackedWidget->setCurrentIndex(1);  // Ir al widget 1
            });

    // Configurar link del inicio de sesion
    ui->iniciar_sesion->setTextFormat(Qt::RichText);
    ui->iniciar_sesion->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->iniciar_sesion->setOpenExternalLinks(false);

    ui->iniciar_sesion->setText("Do you already have an account? <a href=\"registrar\"> Log in</a>");

    connect(ui->iniciar_sesion, &QLabel::linkActivated, this,
            [=](const QString &link){
                //qDebug() << "Link activado:" << link;
                ui->stackedWidget->setCurrentIndex(0);  // Ir al widget 0
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
    ui->stackedWidget->setCurrentIndex(2); // Si lo ha hecho bien, adelante

    //ui->nombre->setText("Nombre: " + nickname); // ESTO FUNCIONA PERO LO QUEIRO PONER EN UNA FUNCION A PARTE

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

void MainWindow::onRegisterClicked(){

    QString nameReg = ui->enter_nickname_reg->text().trimmed();
    QString birthDate = ui->enter_birth_date->text().trimmed();
    QString mail = ui->enter_mail->text().trimmed();
    QString password1 = ui->enter_password_r1->text().trimmed();
    QString password2 = ui->enter_password_r2->text().trimmed();


    if (nameReg.isEmpty()|| password1.isEmpty() || password2.isEmpty() || password1 != password2) {
        ui->stackedWidget->setCurrentIndex(1); // Que no pueda pasar al siguiente paso si no se ha logeado bien
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }

    QDate fecha = QDate::fromString(birthDate, "dd/MM/yyyy");
    if (!fecha.isValid()) {
        QMessageBox::warning(this, "Fecha inválida",
                             "Introduce una fecha válida en formato dd/MM/yyyy.");
        return;
    }

    QRegularExpression emailRegex(R"((^[^\s@]+@[^\s@]+\.[^\s@]+$))");
    if (!emailRegex.match(mail).hasMatch()) {
        QMessageBox::warning(this, "Email inválido",
                             "Introduce un email válido (ej: usuario@dominio.com).");
        return;
    }

    ui->stackedWidget->setCurrentIndex(2); // Si lo ha hecho bien, adelante
}
