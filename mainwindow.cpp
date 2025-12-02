#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * Me falta por añadir:
 *  - Que cuando le des al tabulador del registro se use bien la navegacion en los campos
 *  - Poner el logo del ojo al lado de la barra de password para tener la opcion de ver la contraseña (importante) !
 *  - Poner la bbdd para comprobar el usuario
 *
 *  atte: la rakitraki
 */

#include <QPixmap>
#include <QGraphicsPixmapItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Login passwords
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->enter_password_r1->setEchoMode(QLineEdit::Password);
    ui->enter_password_r2->setEchoMode(QLineEdit::Password);

    // Mostrar login al inicio
    ui->stackedWidget->setCurrentIndex(0); ui->toolBar->setVisible(false);

    // Conexiones login/register
    connect(ui->buttonLogIn, &QPushButton::clicked, this, &MainWindow::onLogInClicked);
    connect(ui->buttonRegister, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);

    // Links del registro y login
    ui->registrarse->setTextFormat(Qt::RichText);
    ui->registrarse->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->registrarse->setOpenExternalLinks(false);
    ui->registrarse->setText("Don't have an account? <a href=\"registrar\">Register</a>");
    connect(ui->registrarse, &QLabel::linkActivated, this, [=](const QString &){ ui->stackedWidget->setCurrentIndex(1); ui->toolBar->setVisible(false);});

    ui->iniciar_sesion->setTextFormat(Qt::RichText);
    ui->iniciar_sesion->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->iniciar_sesion->setOpenExternalLinks(false);
    ui->iniciar_sesion->setText("Do you already have an account? <a href=\"registrar\"> Log in</a>");
    connect(ui->iniciar_sesion, &QLabel::linkActivated, this, [=](const QString &){ ui->stackedWidget->setCurrentIndex(0); ui->toolBar->setVisible(false); });

    // Conexiones botones
    connect(ui->pushButtonVolver, &QPushButton::clicked, this, [=](){ ui->stackedWidget->setCurrentIndex(0); ui->toolBar->setVisible(false); });
    connect(ui->perfil, &QPushButton::clicked, this, [=](){ ui->stackedWidget->setCurrentIndex(3); ui->toolBar->setVisible(false); });
    connect(ui->salirPerfil, &QPushButton::clicked, this, [=](){ ui->stackedWidget->setCurrentIndex(2); ui->toolBar->setVisible(false); });

    // Map button
    bool mapaListo = false;
    connect(ui->Map, &QPushButton::clicked, this, [&](){
        ui->stackedWidget->setCurrentIndex(4);
        if (!mapaListo) {
            setupMap();
            mapaListo = true;
        }
        ui->toolBar->setVisible(true);
    });


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    QPixmap pm(":/images/carta_nautica.jpg");
    scene->addPixmap(pm);
    ui->graphicsView->scale(0.3, 0.3);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    scale = 0.2;

    connect(ui->zoomIn,&QAction::triggered,this,&MainWindow::zoomInS);
    connect(ui->zoomOut,&QAction::triggered,this,&MainWindow::zoomOutS);

    sidebarVisible = true;
    ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
    sidebarAnimation = new QPropertyAnimation(ui->sidebar_2, "maximumWidth", this);
    sidebarAnimation->setDuration(300);

    // 2. CONEXIÓN DEL BOTÓN
    // Asegúrate de que el nombre del objeto sea correcto (el botón dentro del sidebar)
    connect(ui->sidebarButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
}


void MainWindow::setupMap() //funcion para hacer los cambios al mapa
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::zoomInS(){

    applyZoom(1.15);
}

void MainWindow::zoomOutS(){

    applyZoom(1.0/1.15);
}

void MainWindow::applyZoom(double factor){


    double newScale = scale * factor;

    const double minScale = 0.01;
    const double maxScale = 1;

    if (newScale < minScale){

        factor = minScale / scale;
        newScale = minScale;



    }else if (newScale > maxScale){

        factor = maxScale / scale;
        newScale = maxScale;

    }
    ui->graphicsView->scale(factor,factor);
    scale = newScale;

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

    //Ponerlo en el perfil
    ui->nombre->setText("Nickname: " + nameReg);
    ui->nacimiento->setText("Date birth: " + birthDate);
    ui->email->setText("Email: " + mail);
    ui->contrasenya->setText("Password: " + password1);

    ui->stackedWidget->setCurrentIndex(2); // Si lo ha hecho bien, adelante
}

// ... la misma implementación ...

// mainwindow.cpp

void MainWindow::toggleSidebar()
{
    const int fullWidth = 300;
    const int closedWidth = 60; // O 30, si quieres que el botón quede parcialmente visible

    int startValue;
    int endValue;

    if (sidebarVisible) {

        startValue = fullWidth;
        endValue = closedWidth;
        sidebarVisible = false;


        ui->sidebarButton->setIcon(QIcon(":/images/flechaDer.png"));


    } else {
        startValue = closedWidth;
        endValue = fullWidth;
        sidebarVisible = true;


        ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));

    }

    // Iniciar Animación
    sidebarAnimation->setStartValue(startValue);
    sidebarAnimation->setEndValue(endValue);
    sidebarAnimation->start();
}
