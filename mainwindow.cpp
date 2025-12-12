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

#include <QGraphicsPixmapItem>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsLineItem>
#include <QPixmap>

#include <QDebug>
#include <QDir>
#include <navigation.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //cargar problemas
    problemas = nav.problems();

    respbotones.append(ui->radioButton);
    respbotones.append(ui->radioButton_2);
    respbotones.append(ui->radioButton_3);
    respbotones.append(ui->radioButton_4);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::showNextQuestion);

    showNextQuestion(); //para que salga la primera xd

    // Login passwords
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->enter_password_r1->setEchoMode(QLineEdit::Password);
    ui->enter_password_r2->setEchoMode(QLineEdit::Password);

    // Mostrar login al inicio
    ui->stackedWidget->setCurrentIndex(0);
    ui->toolBar->hide();

    // Conexiones login/register
    connect(ui->buttonLogIn, &QPushButton::clicked, this, &MainWindow::onLogInClicked);
    connect(ui->buttonRegister, &QPushButton::clicked, this, &MainWindow::onRegisterClicked);

    // Links del registro y login
    ui->registrarse->setTextFormat(Qt::RichText);
    ui->registrarse->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->registrarse->setOpenExternalLinks(false);
    ui->registrarse->setText("Don't have an account? <a href=\"registrar\">Register</a>");
    connect(ui->registrarse, &QLabel::linkActivated, this, [=](const QString &){ ui->stackedWidget->setCurrentIndex(1);ui->toolBar->hide();});

    ui->iniciar_sesion->setTextFormat(Qt::RichText);
    ui->iniciar_sesion->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->iniciar_sesion->setOpenExternalLinks(false);
    ui->iniciar_sesion->setText("Do you already have an account? <a href=\"registrar\"> Log in</a>");
    connect(ui->iniciar_sesion, &QLabel::linkActivated, this, [=](const QString &){ ui->stackedWidget->setCurrentIndex(0);ui->toolBar->hide();});

    // Conexiones botones
    connect(ui->pushButtonVolver, &QPushButton::clicked, this, [=](){ ui->stackedWidget->setCurrentIndex(0);ui->toolBar->hide();});
    connect(ui->actionPerfil, &QAction::triggered, this, [=](){ ui->stackedWidget->setCurrentIndex(3);ui->toolBar->hide();});
    connect(ui->salirPerfil, &QPushButton::clicked, this, [=](){ ui->stackedWidget->setCurrentIndex(4);ui->toolBar->show();});

    // Map button
    bool mapaListo = false;
    connect(ui->Map, &QPushButton::clicked, this, [&]() {
        ui->stackedWidget->setCurrentIndex(4);
        if (!mapaListo) {
            setupMap();
            mapaListo = true;
        }
    });

    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    ui->graphicsView->setScene(scene);
    QPixmap pm(":/images/carta_nautica.jpg");
    scene->addPixmap(pm);
    ui->graphicsView->scale(0.3, 0.3);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    scale = 0.2;

    connect(ui->zoomIn, &QToolButton::clicked, this, &MainWindow::zoomInS);
    connect(ui->zoomOut, &QToolButton::clicked, this, &MainWindow::zoomOutS);
    connect(ui->lapiz, &QToolButton::clicked, this, &MainWindow::togglePencil);
    connect(ui->cursor, &QToolButton::clicked, this, &MainWindow::toggleCursor);
    connect(ui->goma, &QToolButton::clicked, this, &MainWindow::toggleRubber);

    sidebarVisible = true;
    ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
    sidebarAnimation = new QPropertyAnimation(ui->sidebar_2, "maximumWidth", this);
    sidebarAnimation->setDuration(300);

    // 2. CONEXIÓN DEL BOTÓN
    // Asegúrate de que el nombre del objeto sea correcto (el botón dentro del sidebar)
    connect(ui->sidebarButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
}

void MainWindow::setupMap() //funcion para hacer los cambios al mapa
{}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::zoomInS()
{
    applyZoom(1.15);
}

void MainWindow::zoomOutS()
{
    applyZoom(1.0 / 1.15);
}

void MainWindow::applyZoom(double factor)
{
    double newScale = scale * factor;

    const double minScale = 0.01;
    const double maxScale = 1;

    if (newScale < minScale) {
        factor = minScale / scale;
        newScale = minScale;

    } else if (newScale > maxScale) {
        factor = maxScale / scale;
        newScale = maxScale;
    }
    ui->graphicsView->scale(factor, factor);
    scale = newScale;
}
void MainWindow::onLogInClicked()
{
    QString nickname = ui->enter_nickname->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();
    User *u = nav.authenticate(nickname, password);

    if (u) {
        ui->stackedWidget->setCurrentIndex(4); // Si lo ha hecho bien, adelante
        ui->toolBar->show();
    } else {
        QMessageBox::warning(this, "Incorrecto", "LOGIN INCORRECTO");
    }

    if (nickname.isEmpty() || password.isEmpty()) {
        ui->stackedWidget->setCurrentIndex(
            0); // Que no pueda pasar al siguiente paso si no se ha logeado bien
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }
}

void MainWindow::onRegisterClicked()
{
    QString nameReg = ui->enter_nickname_reg->text().trimmed();
    QString birthDate = ui->enter_birth_date->text().trimmed();
    QString mail = ui->enter_mail->text().trimmed();
    QString password1 = ui->enter_password_r1->text().trimmed();
    QString password2 = ui->enter_password_r2->text().trimmed();

    if (nameReg.isEmpty() || password1.isEmpty() || password2.isEmpty() || password1 != password2) {
        ui->stackedWidget->setCurrentIndex(
            1); // Que no pueda pasar al siguiente paso si no se ha logeado bien
        QMessageBox::warning(this,
                             "Advertencia",
                             "Por favor, introduce el nickname y/o contraseña correctos.");
        return;
    }

    QDate fecha = QDate::fromString(birthDate, "dd/MM/yyyy");
    if (!fecha.isValid()) {
        QMessageBox::warning(this,
                             "Fecha inválida",
                             "Introduce una fecha válida en formato dd/MM/yyyy.");
        return;
    }

    QRegularExpression emailRegex(R"((^[^\s@]+@[^\s@]+\.[^\s@]+$))");
    if (!emailRegex.match(mail).hasMatch()) {
        QMessageBox::warning(this,
                             "Email inválido",
                             "Introduce un email válido (ej: usuario@dominio.com).");
        return;
    }

    //crear el usuario
    QImage avatar(":/images/userIcono.png"); //foto por defecto (esto habrá que arreglarlo xd)

    User u(nameReg, mail, password1, avatar, fecha);

    nav.addUser(u);

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
    const int closedWidth = 100; // O 30, si quieres que el botón quede parcialmente visible

    int startValue;
    int endValue;

    if (sidebarVisible) {
        startValue = fullWidth;
        endValue = closedWidth;
        sidebarVisible = false;
        ui->label->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        for (int i = 0; i < respbotones.size(); ++i) {
            respbotones[i]->setVisible(false);
        }

        ui->sidebarButton->setIcon(QIcon(":/images/flechaDer.png"));

    } else {
        startValue = closedWidth;
        endValue = fullWidth;
        sidebarVisible = true;
        ui->label->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        for (int i = 0; i < respbotones.size(); ++i) {
            respbotones[i]->setVisible(true);
        }

        ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
    }

    // Iniciar Animación
    sidebarAnimation->setStartValue(startValue);
    sidebarAnimation->setEndValue(endValue);
    sidebarAnimation->start();
}

void MainWindow::showNextQuestion()
{
    if (preg_actual >= problemas.size())
        preg_actual = 0; // reiniciar si llegamos al final

    const Problem &p = problemas[preg_actual];

    ui->label->setText(p.text());

    // actualizar radiobuttons
    for (int i = 0; i < respbotones.size(); ++i) {
        if (i < p.answers().size()) {
            respbotones[i]->setText(p.answers()[i].text());
            respbotones[i]->setVisible(true);
            respbotones[i]->setChecked(false);
        } else {
            respbotones[i]->setVisible(false);
        }
    }

    preg_actual++;
}

void MainWindow::togglePencil()
{
    drawingMode = true;
    erasingMode = false;

    // Desactivamos el arrastre del mapa para que no se mueva mientras pintamos
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);

    // Cambiamos el cursor visualmente para que sepa que va a pintar
    ui->graphicsView->setCursor(Qt::CrossCursor);
}

void MainWindow::toggleRubber() // <--- NUEVA IMPLEMENTACIÓN
{
    drawingMode = false;
    erasingMode = true; // Activamos modo goma

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag); // No queremos arrastrar mapa
    ui->graphicsView->setCursor(Qt::ForbiddenCursor); // Icono de "prohibido" o goma
}

void MainWindow::toggleCursor()
{
    drawingMode = false;
    erasingMode = false;

    // Volvemos al modo de arrastrar el mapa
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    // Restauramos el cursor por defecto
    ui->graphicsView->setCursor(Qt::ArrowCursor);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == scene) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent*>(event);

        // --- MODO LÁPIZ ---
        if (drawingMode) {
            // 1. AL PULSAR (CLIC)
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                // Limpiamos el camino anterior y empezamos uno nuevo
                currentPath = QPainterPath();
                currentPath.moveTo(mouseEvent->scenePos()); // Fijamos el inicio CORRECTAMENTE

                // Configuramos el estilo del lápiz (Rojo, grosor 3, bordes redondeados)
                QPen pen(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

                // Creamos el objeto visual usando nuestro camino
                currentPathItem = scene->addPath(currentPath, pen);

                return true;
            }

            // 2. AL ARRASTRAR (MOVE)
            else if (event->type() == QEvent::GraphicsSceneMouseMove && (mouseEvent->buttons() & Qt::LeftButton)) {
                if (currentPathItem) {
                    // Añadimos la línea a NUESTRA variable (que no pierde la memoria)
                    currentPath.lineTo(mouseEvent->scenePos());

                    // Actualizamos el dibujo en pantalla
                    currentPathItem->setPath(currentPath);
                }
                return true;
            }

            // 3. AL SOLTAR
            else if (event->type() == QEvent::GraphicsSceneMouseRelease) {
                currentPathItem = nullptr; // Soltamos la referencia del objeto visual
                return true;
            }
        }

        // --- MODO GOMA ---
        else if (erasingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress ||
                (event->type() == QEvent::GraphicsSceneMouseMove && (mouseEvent->buttons() & Qt::LeftButton))) {

                QGraphicsItem *item = scene->itemAt(mouseEvent->scenePos(), QTransform());

                // Borramos solo si es un PathItem (trazo de lápiz)
                if (item && item->type() == QGraphicsPathItem::Type) {
                    scene->removeItem(item);
                    delete item;
                    return true;
                }
            }
        }
    }
    return QMainWindow::eventFilter(watched, event);
}
