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

#include <QGraphicsColorizeEffect>
#include <QGraphicsLineItem>
#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QTimer>

#include <QDebug>
#include <QDir>
#include <navigation.h>

#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsView>

#include <QColor>
#include <QColorDialog>

#include <QShortcut>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    showMaximized();

    //cargar problemas
    problemas = nav.problems();

    listarPreguntas();

    respbotones.append(ui->radioButton);
    respbotones.append(ui->radioButton_2);
    respbotones.append(ui->radioButton_3);
    respbotones.append(ui->radioButton_4);

    connect(ui->sigButton, &QPushButton::clicked, this, &MainWindow::onNextClicked);
    connect(ui->verificarButton, &QPushButton::clicked, this, &MainWindow::checkQuestion);

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
    connect(ui->registrarse, &QLabel::linkActivated, this, [=](const QString &) {
        ui->stackedWidget->setCurrentIndex(1);
        ui->toolBar->hide();
    });

    ui->iniciar_sesion->setTextFormat(Qt::RichText);
    ui->iniciar_sesion->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->iniciar_sesion->setOpenExternalLinks(false);
    ui->iniciar_sesion->setText(
        "Do you already have an account? <a href=\"registrar\"> Log in</a>");
    connect(ui->iniciar_sesion, &QLabel::linkActivated, this, [=](const QString &) {
        ui->stackedWidget->setCurrentIndex(0);
        ui->toolBar->hide();
    });

    connect(ui->cerrarSesion, &QPushButton::clicked, this, [=]() {

        Session s(sessionStart, sessionHits, sessionFaults);
        nav.addSession(currentUser->nickName(), s);

        currentUser = nullptr;

        ui->nombre->clear();
        ui->nacimiento->clear();
        ui->email->clear();
        ui->contrasenya->clear();

        ui->stackedWidget->setCurrentIndex(0); // Volvemos a la pantalla de login
        ui->toolBar->hide();                    // Ocultamos la toolbar
        ui->enter_nickname->clear();
        ui->lineEdit_2->clear();
    });

    // Botones ojo (mostrar/ocultar contraseña)
    ui->pas1->setIcon(QIcon(":/images/ojoIlum.png"));
    ui->pas2->setIcon(QIcon(":/images/ojoIlum.png"));
    ui->pas3->setIcon(QIcon(":/images/ojoIlum.png"));

    connect(ui->pas1, &QToolButton::clicked, this, [=]() {
        togglePassword(ui->lineEdit_2, ui->pas1); // login
    });

    connect(ui->pas2, &QToolButton::clicked, this, [=]() {
        togglePassword(ui->enter_password_r1, ui->pas2); // registro pass 1
    });

    connect(ui->pas3, &QToolButton::clicked, this, [=]() {
        togglePassword(ui->enter_password_r2, ui->pas3); // registro pass 2
    });

    //login y registro con teclado
    connect(ui->lineEdit_2, &QLineEdit::returnPressed, ui->buttonLogIn, &QPushButton::click);

    connect(ui->enter_password_r2, &QLineEdit::returnPressed, ui->buttonRegister, &QPushButton::click);

    // Conexiones botones
    connect(ui->actionPerfil, &QAction::triggered, this, [=]() {
        ui->stackedWidget->setCurrentIndex(2);
        ui->toolBar->hide();
    });
    connect(ui->salirPerfil, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(3);
        ui->toolBar->show();
    });


    /* Map button
    bool mapaListo = false;
    connect(ui->Map, &QPushButton::clicked, this, [&]() {
        ui->stackedWidget->setCurrentIndex(4);
        if (!mapaListo) {
            setupMap();
            mapaListo = true;
        }
    });
    */

    scene = new QGraphicsScene(this);
    scene->installEventFilter(this);
    ui->graphicsView->setScene(scene);
    QPixmap pm(":/images/carta_nautica.jpg");
    mapItem = scene->addPixmap(pm);
    ui->graphicsView->scale(0.3, 0.3);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    scale = 0.2;

    connect(ui->zoomSlider, &QSlider::valueChanged, this, &MainWindow::onZoomSliderChanged);

    connect(ui->zoomIn, &QToolButton::clicked, this, &MainWindow::onZoomInButtonClicked);
    connect(ui->zoomOut, &QToolButton::clicked, this, &MainWindow::onZoomOutButtonClicked);
    ui->zoomSlider->setValue(50);
    ui->zoomSlider->setMinimum(10);

    grosorLapiz = 3;
    ui->grosorSlider->setMinimum(1);
    ui->grosorSlider->setMaximum(10);
    ui->grosorSlider->setValue(grosorLapiz);
    connect(ui->grosorSlider, &QSlider::valueChanged, this, &MainWindow::SliderLapiz);

    connect(ui->colorButton, &QToolButton::clicked, this, &MainWindow::cambiarColor);

    exclusiveButtons << ui->lapiz
                     << ui->cursor
                     << ui->goma
                     << ui->texto
                     << ui->marca;
    //<< ui->regla;


    for (QToolButton *button : exclusiveButtons) {
        button->installEventFilter(this);

        if (button == ui->lapiz) connect(button, &QToolButton::toggled, this, &MainWindow::togglePencil);
        if (button == ui->cursor) connect(button, &QToolButton::toggled, this, &MainWindow::toggleCursor);
        if (button == ui->goma) connect(button, &QToolButton::toggled, this, &MainWindow::toggleRubber);
        if (button == ui->marca) connect(button, &QToolButton::toggled, this, &MainWindow::placeMark);
        //if (button == ui->regla) connect(button, &QToolButton::toggled, this, &MainWindow::toggleSvgRuler);
        if (button == ui->texto) connect(button, &QToolButton::toggled, this, &MainWindow::toggleText);
    }

    connect(ui->regla, &QToolButton::toggled, this, &MainWindow::toggleSvgRuler);
    connect(ui->nuevaPag, &QToolButton::clicked, this, &MainWindow::clearAllDrawings);
    connect(ui->ojo, &QToolButton::clicked, this, &MainWindow::togglePointExtremes);
    ui->cursor->setChecked(true);


    auto activateToolButton = [this](QToolButton* buttonToActivate) {
        if (!buttonToActivate->isCheckable()) return;

        if (buttonToActivate->isChecked()) {
            buttonToActivate->setChecked(false);
            ui->cursor->setChecked(true); // Activa el cursor
            return;
        }

        for (QToolButton *button : exclusiveButtons) {
            if (button != buttonToActivate && button->isChecked()) {
                button->setChecked(false); // Dispara toggled(false) en los inactivos
            }
        }

        // 2. Activar el botón deseado
        if (!buttonToActivate->isChecked()) {
            buttonToActivate->setChecked(true); // Dispara toggled(true) en el botón actual
        }
    };

    // --- Atajo para Cursor (1) ---
    QShortcut *cursorShortcut = new QShortcut(QKeySequence(Qt::Key_1), this);
    connect(cursorShortcut, &QShortcut::activated, this, [=]() {
        activateToolButton(ui->cursor);
    });

    // --- Atajo para Lápiz (2) ---
    QShortcut *pencilShortcut = new QShortcut(QKeySequence(Qt::Key_2), this);
    connect(pencilShortcut, &QShortcut::activated, this, [=]() {
        activateToolButton(ui->lapiz);
    });

    // --- Atajo para Goma (3) ---
    QShortcut *rubberShortcut = new QShortcut(QKeySequence(Qt::Key_3), this);
    connect(rubberShortcut, &QShortcut::activated, this, [=]() {
        activateToolButton(ui->goma);
    });

    // --- Atajo para Texto (4) ---
    QShortcut *textShortcut = new QShortcut(QKeySequence(Qt::Key_4), this);
    connect(textShortcut, &QShortcut::activated, this, [=]() {
        activateToolButton(ui->texto);
    });

    // --- Atajo para Marca (5) ---
    QShortcut *markShortcut = new QShortcut(QKeySequence(Qt::Key_5), this);
    connect(markShortcut, &QShortcut::activated, this, [=]() {
        activateToolButton(ui->marca);
    });

    // --- Atajo para Regla (6) ---
    QShortcut *rulerShortcut = new QShortcut(QKeySequence(Qt::Key_6), this);
    connect(rulerShortcut, &QShortcut::activated, this, [=]() {
        activateToolButton(ui->regla);
    });

    QShortcut *deleteShortcut = new QShortcut(QKeySequence(Qt::Key_Delete), this);
    connect(deleteShortcut, &QShortcut::activated, this, &MainWindow::confirmAndClearAllDrawings);

    sidebarVisible = true;
    ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
    ui->sidebarButton_2->setIcon(QIcon(":/images/flechaIzq.png"));
    sidebarAnimation = new QPropertyAnimation(ui->sidebar_2, "maximumWidth", this);
    sidebarAnimation->setDuration(300);

    // 2. CONEXIÓN DEL BOTÓN
    // Asegúrate de que el nombre del objeto sea correcto (el botón dentro del sidebar)
    connect(ui->sidebarButton, &QPushButton::clicked, this, &MainWindow::toggleSidebar);
    connect(ui->sidebarButton_2, &QPushButton::clicked, this, &MainWindow::toggleSidebar);

    //conexion a un problema
    connect(ui->Problema_Random, &QPushButton::clicked, this, [=]() {
        ui->sidebar_2->setCurrentIndex(1);
    });

    rulerSvgItem = new RotatableSvgItem(":/images/ruler.svg");
    scene->addItem(rulerSvgItem);
    rulerSvgItem->setVisible(false);

    QTimer *updateTimer = new QTimer(this); //Se usa para actualizar las marcas del 'ojo'
    connect(updateTimer, &QTimer::timeout, this, [=]() {
        if (eyeActive) {
            QList<QGraphicsItem *> selected = scene->selectedItems();
            if (!selected.isEmpty()) {
                showPointExtremes(selected.first());
            }
        }
    });
    updateTimer->start(50); // cada 50 ms revisa la posición


    //HISTORIAL
    connect(ui->actionHistorial, &QAction::triggered, this, [=]{
        mostrarHistorial();

        ui->stackedWidget->setCurrentIndex(4);
        ui->toolBar->hide();
    });
}


void MainWindow::setupMap() //funcion para hacer los cambios al mapa
{}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::applyZoom(double newScale)
{
    const double minScale = 0.1;
    const double maxScale = 1.0;

    if (newScale < minScale) {
        newScale = minScale;
    } else if (newScale > maxScale) {
        newScale = maxScale;
    }

    double factor = newScale / scale;

    ui->graphicsView->scale(factor, factor);
    scale = newScale;
}

void MainWindow::onZoomInButtonClicked()
{
    int currentValue = ui->zoomSlider->value();
    ui->zoomSlider->setValue(currentValue + 5);
}

void MainWindow::onZoomOutButtonClicked()
{
    int currentValue = ui->zoomSlider->value();
    ui->zoomSlider->setValue(currentValue - 5);
}

void MainWindow::onZoomSliderChanged(int value)
{
    double newScale = (double) value / 100.0;
    applyZoom(newScale);
}

void MainWindow::SliderLapiz(int value)
{
    grosorLapiz = value;
}

void MainWindow::cambiarColor()
{
    QColor newColor = QColorDialog::getColor(currentColor, // Color inicial
                                             this,         // Padre
                                             "Selecciona el color del lápiz");

    if (newColor.isValid()) {
        currentColor = newColor;

        ui->colorButton->setStyleSheet(QString("background-color: %1;").arg(newColor.name()));
    }
}

void MainWindow::onLogInClicked()
{
    QString nickname = ui->enter_nickname->text().trimmed();
    QString password = ui->lineEdit_2->text().trimmed();

    // ESTO LO TENDREMOS QUE QUITAR
    if ((nickname == "user1") && (password == "User123!")) {
        ui->stackedWidget->setCurrentIndex(3); // pantalla principal
        ui->sidebar_2->setCurrentIndex(0);
        ui->toolBar->show();
        return;
    }

    //Users *u = userManager.authenticate(nickname, password);

    User *u = nav.authenticate(nickname, password);
    currentUser = u;

    if (!u) {
        QMessageBox::warning(this, "Login incorrecto", "Nombre o contraseña incorrectos.");
        return;
    }

    // Si login correcto, mostrar perfil o la pantalla principal
    sessionHits = 0;
    sessionFaults = 0;
    sessionStart = QDateTime::currentDateTime();

    ui->stackedWidget->setCurrentIndex(3);
    ui->sidebar_2->setCurrentIndex(0);
    ui->toolBar->show();

    // Opcional: mostrar info en perfil
    ui->nombre->setText("Nickname: " + u->nickName());
    ui->nacimiento->setText("Date birth: " + u->birthdate().toString("dd/MM/yyyy"));
    ui->email->setText("Email: " + u->email());
    ui->contrasenya->setText("Password: " + u->password());
}
void MainWindow::onRegisterClicked()
{
    QString nameReg = ui->enter_nickname_reg->text().trimmed();
    QString birthDate = ui->enter_birth_date->text().trimmed();
    QString mail = ui->enter_mail->text().trimmed();
    QString password1 = ui->enter_password_r1->text().trimmed();
    QString password2 = ui->enter_password_r2->text().trimmed();

    // Validaciones básicas
    if (nameReg.isEmpty() || password1.isEmpty() || password2.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Rellena todos los campos.");
        return;
    }

    if (password1 != password2) {
        QMessageBox::warning(this, "Advertencia", "Las contraseñas no coinciden.");
        return;
    }

    QDate fecha = QDate::fromString(birthDate, "dd/MM/yyyy");
    if (!fecha.isValid()) {
        QMessageBox::warning(this, "Fecha inválida", "Introduce una fecha válida en formato dd/MM/yyyy.");
        return;
    }

    QRegularExpression emailRegex(R"((^[^\s@]+@[^\s@]+\.[^\s@]+$))");
    if (!emailRegex.match(mail).hasMatch()) {
        QMessageBox::warning(this, "Email inválido", "Introduce un email válido (ej: usuario@dominio.com).");
        return;
    }

    // Crear usuario
    QImage avatar(":/images/userIcono.png"); // avatar por defecto

    //usuarios raquel:
    //Users newUser(nameReg, mail, password1, avatar, fecha);
    //userManager.addUser(newUser);

    //añadir a bbdd
    User u(nameReg, mail, password1, avatar, fecha);
    nav.addUser(u);

    // Mostrar info en perfil
    ui->nombre->setText("Nickname: " + u.nickName());
    ui->nacimiento->setText("Date birth: " + u.birthdate().toString("dd/MM/yyyy"));
    ui->email->setText("Email: " + u.email());
    ui->contrasenya->setText("Password: " + u.password());

    // Cambiar a la pantalla de perfil
    ui->stackedWidget->setCurrentIndex(2);
}

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
        ui->enunciadoLabel->setVisible(false);
        ui->verificarButton->setVisible(false);
        ui->sigButton->setVisible(false);
        for (int i = 0; i < respbotones.size(); ++i) {
            respbotones[i]->setVisible(false);
        }

        ui->sidebarButton->setIcon(QIcon(":/images/flechaDer.png"));
        ui->sidebarButton_2->setIcon(QIcon(":/images/flechaDer.png"));

    } else {
        startValue = closedWidth;
        endValue = fullWidth;
        sidebarVisible = true;
        ui->enunciadoLabel->setVisible(true);
        ui->verificarButton->setVisible(true);
        ui->sigButton->setVisible(true);
        for (int i = 0; i < respbotones.size(); ++i) {
            respbotones[i]->setVisible(true);
        }

        ui->sidebarButton->setIcon(QIcon(":/images/flechaIzq.png"));
        ui->sidebarButton_2->setIcon(QIcon(":/images/flechaIzq.png"));
    }

    // Iniciar Animación
    sidebarAnimation->setStartValue(startValue);
    sidebarAnimation->setEndValue(endValue);
    sidebarAnimation->start();
}

void MainWindow::listarPreguntas()
{
    for (int i = 0; i < problemas.size(); i++) {
        QPushButton *butt = new QPushButton(this);

        butt->setText(QString("Pregunta %1").arg(i + 1));
        butt->setProperty("indice", i);

        connect(butt, &QPushButton::clicked, this, [=]() {
            preg_actual = butt->property("indice").toInt();
            ui->sidebar_2->setCurrentIndex(1);
            showNextQuestion();
        });

        ui->Elegir_problema->layout()->addWidget(butt);
    }
}

void MainWindow::onNextClicked()
{
    preg_actual++;
    showNextQuestion();
}

void MainWindow::showNextQuestion()
{

    ui->res1->setText("");
    ui->res2->setText("");
    ui->res3->setText("");
    ui->res4->setText("");
    ui->verificarButton->setEnabled(true);

    if (preg_actual >= problemas.size())
        preg_actual = 0; // reiniciar si llegamos al final

    const Problem &p = problemas[preg_actual];

    ui->enunciadoLabel->setText(p.text());

    // actualizar radiobuttons
    for (int i = 0; i < respbotones.size(); ++i) {
        if (i < p.answers().size()) {
            respbotones[i]->setText(p.answers()[i].text());
            respbotones[i]->setVisible(true);
            respbotones[i]->setChecked(false);
            respbotones[i]->setStyleSheet(""); // resetear color
        } else {
            respbotones[i]->setVisible(false);
        }
    }
}

void MainWindow::togglePassword(QLineEdit *text, QToolButton *button){
    if (text->echoMode() == QLineEdit::Password) {
        text->setEchoMode(QLineEdit::Normal);
        button->setIcon(QIcon(":/images/ojoIlum.png"));
    } else {
        text->setEchoMode(QLineEdit::Password);
        button->setIcon(QIcon(":/images/ojo.png"));
    }
}

void MainWindow::checkQuestion()
{
    Problem &p = problemas[preg_actual];

    int seleccionada = -1;
    for (int i = 0; i < respbotones.size(); ++i) {
        if (respbotones[i]->isChecked()) {
            seleccionada = i;
            break;
        }
    }

    if (seleccionada == -1)
        return;

    QLabel* labels[] = {ui->res1, ui->res2, ui->res3, ui->res4};

    for (int i = 0; i < p.answers().size(); ++i) {

        if (p.answers()[i].validity()) {
            respbotones[i]->setStyleSheet("color: green; font-weight: bold;");
            labels[i]->setText("✓");
            labels[i]->setStyleSheet("color: green; font-size: 18px; font-weight: bold;");
        }
        else if (i == seleccionada) {
            respbotones[i]->setStyleSheet("color: red; font-weight: bold;");
            labels[i]->setText("✗");
            labels[i]->setStyleSheet("color: red; font-size: 18px; font-weight: bold;");
        }
    }

    if (p.answers()[seleccionada].validity()) {
        sessionHits++;
    } else {
        sessionFaults++;
    }


    ui->verificarButton->setEnabled(false);
}

void MainWindow::mostrarHistorial(){
    ui->tableHistorial->clearContents();
    ui->tableHistorial->setRowCount(0);

    ui->tableHistorial->setColumnCount(3);
    ui->tableHistorial->setHorizontalHeaderLabels(
        {"FECHA", "ACIERTOS", "FALLOS"}
        );

    if (!currentUser)
        return;

    const QVector<Session> &sessions = currentUser->sessions();

    ui->tableHistorial->setRowCount(sessions.size());

    for (int i = 0; i < sessions.size(); ++i) {
        const Session &s = sessions[i];

        QTableWidgetItem *fecha =
            new QTableWidgetItem(s.timeStamp().toString("dd/MM/yyyy hh:mm"));

        QTableWidgetItem *aciertos =
            new QTableWidgetItem(QString::number(s.hits()));

        QTableWidgetItem *fallos =
            new QTableWidgetItem(QString::number(s.faults()));

        fecha->setTextAlignment(Qt::AlignCenter);
        aciertos->setTextAlignment(Qt::AlignCenter);
        fallos->setTextAlignment(Qt::AlignCenter);

        ui->tableHistorial->setItem(i, 0, fecha);
        ui->tableHistorial->setItem(i, 1, aciertos);
        ui->tableHistorial->setItem(i, 2, fallos);
    }

    // Ajustes visuales bonitos
    ui->tableHistorial->horizontalHeader()->setStretchLastSection(true);
    ui->tableHistorial->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableHistorial->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableHistorial->setSelectionMode(QAbstractItemView::NoSelection);
}


void MainWindow::togglePencil()
{
    drawingMode = true;
    erasingMode = false;
    markingMode = false;
    measuringMode = false;
    textMode = false;

    // Desactivamos el arrastre del mapa para que no se mueva mientras pintamos
    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);

    // Cambiamos el cursor visualmente para que sepa que va a pintar
    QPixmap customPixmap(":/images/lapiz.png");
    customPixmap = customPixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QCursor Cursor(customPixmap, 1, 28);
    ui->graphicsView->setCursor(Cursor);
}

void MainWindow::toggleRubber() // <--- NUEVA IMPLEMENTACIÓN
{
    drawingMode = false;
    erasingMode = true;
    markingMode = false;
    measuringMode = false;
    textMode = false;

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag); // No queremos arrastrar mapa
    QPixmap customPixmap(":/images/goma.png");
    customPixmap = customPixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QCursor Cursor(customPixmap, 1, 28);
    ui->graphicsView->setCursor(Cursor);
}

void MainWindow::toggleCursor()
{
    drawingMode = false;
    erasingMode = false;
    markingMode = false;
    measuringMode = false;
    textMode = false;

    if (rulerSvgItem) {
        rulerSvgItem->setVisible(false);
        rulerSvgItem->setSelected(false);
        svgRulerActive = false;
    }
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    // Restauramos el cursor por defecto
    ui->graphicsView->setCursor(Qt::ArrowCursor);
}

void MainWindow::clearAllDrawings()
{
    for (QGraphicsItem *item : scene->items()) {
        // Si el objeto NO es el mapa, lo borramos
        if (item != mapItem
            && (item->type() == QGraphicsPathItem::Type || item->type() == QGraphicsPixmapItem::Type
                ||                                         // Chinchetas
                item->type() == QGraphicsLineItem::Type || // Reglas
                item->type() == QGraphicsTextItem::Type
                || item->type() == QGraphicsItemGroup::Type)) { // Textos

            scene->removeItem(item);
            delete item;
        }
    }
}

void MainWindow::confirmAndClearAllDrawings()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirmación de Borrado");
    msgBox.setText("¿Estás seguro de que deseas borrar TODAS las anotaciones en la carta náutica?");
    msgBox.setIcon(QMessageBox::Warning); // Icono de advertencia

    // Configuración de los botones
    QPushButton *yesButton = msgBox.addButton("Sí, borrar todo", QMessageBox::YesRole);
    msgBox.addButton("No, cancelar", QMessageBox::NoRole);

    msgBox.exec(); // Muestra la caja de diálogo y espera la respuesta


    if (msgBox.clickedButton() == yesButton) {

        clearAllDrawings();
        ui->cursor->setChecked(true);
    }
}

void MainWindow::placeMark()
{
    drawingMode = false;
    erasingMode = false;
    measuringMode = false;
    markingMode = true; // Activamos modo marca
    textMode = false;

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    // Usamos un cursor que parezca que va a señalar algo
    ui->graphicsView->setCursor(Qt::PointingHandCursor);
}

void MainWindow::toggleSvgRuler(bool checked){
    // 1. Controlar la visibilidad y seleccionabilidad del ítem SVG
    if (rulerSvgItem) {
        rulerSvgItem->setVisible(checked);
        rulerSvgItem->setSelected(checked);
    }

    // Sincronizar la variable de estado
    svgRulerActive = checked;

    // 2. Comprobar si el Lápiz o un modo de dibujo está activo
    bool drawingModeIsActive = drawingMode || erasingMode || markingMode || textMode || measuringMode;

    if (checked) {
        // --- REGLA ACTIVADA ---

        // Si el Lápiz está activo, lo dejamos en checked=true
        // La lógica del QEventFilter nos garantiza que solo uno de los exclusivos esté activo.

        // Permitimos mover la Regla SVG
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);


        // Si no hay modo de dibujo activo, ponemos cursor de arrastre de objeto (Regla SVG)
        if (!drawingModeIsActive) {
            ui->graphicsView->setCursor(Qt::OpenHandCursor);
        }

    } else {
        // --- REGLA DESACTIVADA ---

        // Si la herramienta Lápiz estaba activa antes de usar la Regla SVG:
        if (ui->lapiz->isChecked()) {
            togglePencil();

        } else if (drawingModeIsActive) {
            // Si cualquier otro modo de dibujo estaba activo, lo restauramos
            // (esto incluye Goma, Marca, etc.)
            if (erasingMode) toggleRubber();
            else if (markingMode) placeMark();
            else if (textMode) toggleText();
            else toggleCursor(); // Si no era modo de dibujo, vamos al cursor normal.
        }
        else {
            // Si no había NINGÚN modo de dibujo activo, volvemos al modo cursor normal.
            toggleCursor();
        }
    }
}

RotatableSvgItem::RotatableSvgItem(const QString &fileName, QGraphicsItem *parent)
    : QGraphicsSvgItem(fileName, parent), m_mode(None)
{
    // Quitamos ItemIsMovable para moverlo manualmente solo desde el centro
    // Habilitamos Hover para cambiar el cursor al pasar por encima
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges);
    setAcceptHoverEvents(true);
}

void RotatableSvgItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QRectF bounds = boundingRect();
    QPointF pos = event->pos();
    qreal width = bounds.width();
    qreal zoneSize = width * 0.15; // 15% para las zonas de rotación

    m_lastMousePos = event->scenePos();

    // Función auxiliar lambda para cambiar el pivote sin que la regla salte
    auto setPivotSmart = [&](QPointF newPivotLocal) {
        // 1. Guardamos dónde está ese punto visualmente AHORA MISMO en la escena
        QPointF anchorSceneBefore = mapToScene(newPivotLocal);

        // 2. Cambiamos el punto de origen de la transformación
        setTransformOriginPoint(newPivotLocal);

        // 3. Vemos dónde ha ido a parar ese punto tras el cambio (aquí ocurre el salto)
        QPointF anchorSceneAfter = mapToScene(newPivotLocal);

        // 4. Calculamos la diferencia y movemos la regla para compensar el salto
        QPointF diff = anchorSceneBefore - anchorSceneAfter;
        setPos(this->pos() + diff);

        // 5. Guardamos este punto como el pivote fijo para la rotación
        m_pivotPoint = anchorSceneBefore;
    };

    if (pos.x() < zoneSize) {
        // --- Clic en IZQUIERDA -> Pivote en DERECHA ---
        m_mode = Rotating;
        setPivotSmart(QPointF(width, bounds.height() / 2));

    } else if (pos.x() > width - zoneSize) {
        // --- Clic en DERECHA -> Pivote en IZQUIERDA ---
        m_mode = Rotating;
        setPivotSmart(QPointF(0, bounds.height() / 2));

    } else {
        // --- Clic en CENTRO -> MOVER ---
        m_mode = Moving;
        setCursor(Qt::ClosedHandCursor);
    }

    event->accept();
}

void RotatableSvgItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_mode == Moving) {
        // Mover manualmente sumando la diferencia
        QPointF delta = event->scenePos() - m_lastMousePos;
        setPos(pos() + delta);
        m_lastMousePos = event->scenePos();
    }
    else if (m_mode == Rotating) {
        // Calcular ángulo absoluto entre el pivote y el ratón
        QLineF line(m_pivotPoint, event->scenePos());
        double angle = -line.angle();

        // Corregir orientación si estamos pivotando sobre el lado derecho
        // (porque la regla "mira" hacia la izquierda en ese caso)
        if (transformOriginPoint().x() > 0) {
            angle += 180;
        }

        setRotation(angle);
    }
}

void RotatableSvgItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_mode = None;
    hoverMoveEvent(nullptr); // Restaurar el cursor correcto
    QGraphicsSvgItem::mouseReleaseEvent(event);
}

void RotatableSvgItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QPointF pos = (event) ? event->pos() : mapFromScene(QCursor::pos());
    qreal width = boundingRect().width();
    qreal zoneSize = width * 0.15;

    if (pos.x() < zoneSize || pos.x() > width - zoneSize) {
        setCursor(Qt::SizeHorCursor);
    } else {
        setCursor(Qt::OpenHandCursor);
    }

    if(event) QGraphicsSvgItem::hoverMoveEvent(event);
}

void MainWindow::hidePointExtremes()
{
    if (eyeProjectionGroup) {
        scene->removeItem(eyeProjectionGroup);
        delete eyeProjectionGroup;
        eyeProjectionGroup = nullptr;
    }
}

void MainWindow::showPointExtremes(QGraphicsItem *point)
{
    if (!point || !mapItem)
        return;

    // Borrar si existían
    hidePointExtremes();

    eyeProjectionGroup = new QGraphicsItemGroup();

    // --- NUEVO: MARCAMOS EL GRUPO PARA QUE NO SE PUEDA BORRAR ---
    // Usamos Qt::UserRole con un valor específico (ej. "no_borrar")
    eyeProjectionGroup->setData(Qt::UserRole, "locked_helper");
    // -------------------------------------------------------------

    QPointF p = point->scenePos();

    QRectF mapRect = mapItem->boundingRect();
    QPointF topLeft = mapItem->mapToScene(mapRect.topLeft());
    QPointF bottomRight = mapItem->mapToScene(mapRect.bottomRight());

    // Se ha puesto asi para que se visualice "destacando" estas marcas
    // De color verde porque de color rojo se podría malinterpretar con que se ha hecho "mal"
    QPen pen(Qt::darkGreen, 1, Qt::DashLine);

    // Proyección vertical
    QGraphicsLineItem *vertical = new QGraphicsLineItem(
        QLineF(p.x(), topLeft.y(), p.x(), bottomRight.y()));
    vertical->setPen(pen);

    // Proyección horizontal
    QGraphicsLineItem *horizontal = new QGraphicsLineItem(
        QLineF(topLeft.x(), p.y(), bottomRight.x(), p.y()));
    horizontal->setPen(pen);

    eyeProjectionGroup->addToGroup(vertical);
    eyeProjectionGroup->addToGroup(horizontal);

    scene->addItem(eyeProjectionGroup);
}

void MainWindow::togglePointExtremes()
{
    QList<QGraphicsItem *> selected = scene->selectedItems();

    // Validación básica
    if (selected.isEmpty()) {
        QMessageBox::information(this,
                                 "Marcar extremos",
                                 "Selecciona primero un punto en la carta.");
        return;
    }

    QGraphicsItem *item = selected.first();

    // Si ya está activo → ocultar
    if (eyeActive) {
        hidePointExtremes();
        eyeActive = false;
        return;
    }

    // Si no está activo → mostrar
    showPointExtremes(item);
    eyeActive = true;
}

void MainWindow::toggleText()
{
    drawingMode = false;
    erasingMode = false;
    markingMode = false;
    measuringMode = false;
    textMode = true;

    ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    ui->graphicsView->setCursor(Qt::IBeamCursor);
}

QPointF MainWindow::snapToRuler(QPointF scenePos)
{
    // Si la regla no existe o está oculta, devolvemos el punto normal
    if (!rulerSvgItem || !rulerSvgItem->isVisible()) {
        return scenePos;
    }

    // 1. Convertir la posición del ratón (Escena) a coordenadas locales de la regla
    QPointF localPos = rulerSvgItem->mapFromScene(scenePos);
    QRectF rect = rulerSvgItem->boundingRect();

    // Definimos un umbral de atracción (ej: 30 píxeles)
    double threshold = 60.0;

    // Calculamos distancias a los bordes superior e inferior (en local)
    double distTop = qAbs(localPos.y() - rect.top());
    double distBottom = qAbs(localPos.y() - rect.bottom());

    // 2. Comprobar si debemos activar el "imán"
    bool snapped = false;

    // Opcional: Si quieres que solo pinte SI ESTÁ DENTRO del largo de la regla:
    // if (localPos.x() >= rect.left() - threshold && localPos.x() <= rect.right() + threshold) { ... }

    // Lógica de imán:
    if (distTop < threshold) {
        localPos.setY(rect.top()); // Fijar al borde superior
        snapped = true;
    } else if (distBottom < threshold) {
        localPos.setY(rect.bottom()); // Fijar al borde inferior
        snapped = true;
    }

    // 3. Devolver la posición corregida (o la original)
    if (snapped) {
        return rulerSvgItem->mapToScene(localPos);
    } else {
        return scenePos;
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && qobject_cast<QToolButton*>(watched))
    {
        QToolButton *clickedButton = qobject_cast<QToolButton*>(watched);

        if (exclusiveButtons.contains(clickedButton))
        {

            if (clickedButton->isChecked()) {

                clickedButton->setChecked(false);
                ui->cursor->setChecked(true);

                return true;
            }
            // Desactivar todos los demás botones del grupo ANTES de que el clic active el actual.
            for (QToolButton *button : exclusiveButtons)
            {
                if (button != clickedButton && button->isCheckable())
                {
                    button->setChecked(false);
                }
            }
        }
    }

    if (watched == scene) {
        QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(event);

        // ---------------------------------------------------------
        // MODO 1: LÁPIZ
        // ---------------------------------------------------------
        if (drawingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                currentPath = QPainterPath();

                // CAMBIO AQUÍ: Usamos snapToRuler
                QPointF startPoint = snapToRuler(mouseEvent->scenePos());

                currentPath.moveTo(startPoint);

                QPen pen(currentColor, grosorLapiz, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
                currentPathItem = scene->addPath(currentPath, pen);
                return true;
            } else if (event->type() == QEvent::GraphicsSceneMouseMove
                       && (mouseEvent->buttons() & Qt::LeftButton)) {
                if (currentPathItem) {
                    // CAMBIO AQUÍ: Usamos snapToRuler
                    QPointF nextPoint = snapToRuler(mouseEvent->scenePos());

                    currentPath.lineTo(nextPoint);
                    currentPathItem->setPath(currentPath);
                }
                return true;
            } else if (event->type() == QEvent::GraphicsSceneMouseRelease) {
                currentPathItem = nullptr;
                return true;
            }
        }

        // ---------------------------------------------------------
        // MODO 2: GOMA
        // ---------------------------------------------------------
        else if (erasingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress
                || (event->type() == QEvent::GraphicsSceneMouseMove
                    && (mouseEvent->buttons() & Qt::LeftButton))) {
                QGraphicsItem *item = scene->itemAt(mouseEvent->scenePos(), QTransform());
                if (item && item->group()) {
                    item = item->group();
                }
                // AÑADIMOS "item != mapItem" A LA CONDICIÓN

                // --- NUEVA COMPROBACIÓN ---
                // Si el item tiene la marca "locked_helper", LO IGNORAMOS y no borramos
                if (item && item->data(Qt::UserRole).toString() == "locked_helper") {
                    return true;
                }
                // --------------------------

                // Condición original de borrado
                if (item && item != mapItem
                    && (item->type() == QGraphicsPathItem::Type
                        || item->type() == QGraphicsPixmapItem::Type
                        || item->type() == QGraphicsLineItem::Type
                        || item->type() == QGraphicsTextItem::Type
                        || item->type() == QGraphicsItemGroup::Type)) {
                    scene->removeItem(item);
                    delete item;
                    return true;
                }
            }
        }

        // ---------------------------------------------------------
        // MODO 3: MARCA (NUEVO)
        // ---------------------------------------------------------
        else if (markingMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                // 1. Cargamos la imagen (Asegúrate de tener un icono llamado pin.png o similar en tus recursos)
                // Si no tienes imagen, usa ":/images/flechaIzq.png" temporalmente para probar
                QPixmap pixmap(":/images/iconoChincheta.png");

                // Redimensionamos si es muy grande (opcional)
                pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);

                // 2. Añadimos el objeto al mapa
                QGraphicsPixmapItem *marker = scene->addPixmap(pixmap);

                // 3. Centramos la imagen en el clic (si no, el clic queda en la esquina superior izq de la imagen)
                marker->setOffset(-pixmap.width() / 2, -pixmap.height() / 2);
                marker->setPos(mouseEvent->scenePos());

                // Opcional: Hacer que la marca se pueda mover después
                marker->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
                return true;
            } else if (event->type() == QEvent::GraphicsSceneMouseMove
                       && eyeActive) { // actualizar las posiciones de la chincheta
                // Recalcular las líneas de los extremos del item seleccionado
                QList<QGraphicsItem *> selected = scene->selectedItems();
                if (!selected.isEmpty()) {
                    showPointExtremes(selected.first());
                }
                return true;
            }
        }

        // ---------------------------------------------------------
        // MODO 4: REGLA (NUEVO)
        // ---------------------------------------------------------
        else if (measuringMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                // Guardamos el punto de inicio
                rulerStartPoint = mouseEvent->scenePos();

                // Creamos una línea azul para diferenciar del lápiz
                QPen rulerPen(Qt::blue, 2, Qt::DashLine);
                currentRulerLine = scene->addLine(QLineF(rulerStartPoint, rulerStartPoint),
                                                  rulerPen);
                return true;
            } else if (event->type() == QEvent::GraphicsSceneMouseMove
                       && (mouseEvent->buttons() & Qt::LeftButton)) {
                if (currentRulerLine) {
                    // Actualizamos el final de la línea mientras arrastras
                    QLineF newLine(rulerStartPoint, mouseEvent->scenePos());
                    currentRulerLine->setLine(newLine);
                }
                return true;
            } else if (event->type() == QEvent::GraphicsSceneMouseRelease) {
                if (currentRulerLine) {
                    // Calculamos la distancia (en píxeles)
                    QLineF line = currentRulerLine->line();
                    qreal distance = line.length();

                    // Ponemos un texto con la distancia en el punto medio de la línea
                    QGraphicsTextItem *text = scene->addText(QString("%1 px").arg(int(distance)));
                    text->setDefaultTextColor(Qt::blue);
                    text->setPos((line.p1() + line.p2()) / 2); // Punto medio

                    // Ya no editamos más esta línea
                    currentRulerLine = nullptr;
                }
                return true;
            }
        }
        // ---------------------------------------------------------
        // MODO 5: TEXTO (POST-IT)
        // ---------------------------------------------------------
        // Me falta añadir el ajuste del fondo blanco según el tamaño del texto a introducir - raq
        else if (textMode) {
            if (event->type() == QEvent::GraphicsSceneMousePress) {
                QGraphicsSceneMouseEvent *mouseEvent = static_cast<QGraphicsSceneMouseEvent *>(
                    event);

                QPointF pos = mouseEvent->scenePos();

                // 1. Crear el texto
                QGraphicsTextItem *textItem = new QGraphicsTextItem();
                textItem->setPlainText("");
                textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
                textItem->setDefaultTextColor(Qt::black);
                textItem->setFlag(QGraphicsItem::ItemIsFocusable, true);

                QFont font;
                font.setPointSize(10);
                textItem->setFont(font);

                // 2. Crear fondo (rectángulo)
                QGraphicsRectItem *background = new QGraphicsRectItem();
                background->setBrush(Qt::white);
                background->setPen(QPen(Qt::black));

                // 3. Crear grupo
                QGraphicsItemGroup *group = new QGraphicsItemGroup();
                group->addToGroup(background);
                group->addToGroup(textItem);
                group->setHandlesChildEvents(false); // MUY IMPORTANTE

                group->setPos(pos);
                group->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

                scene->addItem(group);

                // 4. Ajuste dinámico del fondo según el texto
                const qreal margin = 2.5;

                auto updateBackground = [=]() {
                    QRectF textRect = textItem->boundingRect();

                    background->setRect(textRect.adjusted(-margin, -margin, margin, margin));

                    textItem->setPos(margin, margin);
                };

                QObject::connect(textItem->document(),
                                 &QTextDocument::contentsChanged,
                                 scene,
                                 updateBackground);

                // Ajuste inicial
                updateBackground();

                // 5. Dar foco al texto para escribir inmediatamente
                scene->setFocusItem(textItem);
                textItem->setFocus();

                return true;
            }
        }
    }
    return QMainWindow::eventFilter(watched, event);
}
