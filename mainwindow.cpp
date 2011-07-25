#include "mainwindow.h"
#include "echoclient.h"
#include "echoserver.h"
#include "aboutdialog.h"
#include "scanner.h"
#include "ui_mainwindow.h"

const char* MainWindow::APP_NAME = "Infobasic";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    putTexts();
    setuid();
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug("Delete MainWindow");
}

void MainWindow::onClickExit()
{
    qDebug("onClickExit");
    close();
}

void MainWindow::onClickClientEcho()
{
    qDebug("onClickClientEcho");
    QWidget *client =  new EchoClient();
    ui->mdiArea->addSubWindow(client);
    ui->mdiArea->showMaximized();
    client->show();
}

void MainWindow::onClickServerEcho()
{
    qDebug("onClickServerEcho");
    QWidget *server =  new EchoServer();
    ui->mdiArea->addSubWindow(server);
    ui->mdiArea->showMaximized();
    server->show();
}

void MainWindow::onClickAbout()
{
    qDebug("onClickAbout");
    QWidget *about =  new AboutDialog();
    ui->mdiArea->addSubWindow(about);
    ui->mdiArea->showMaximized();
    about->show();
}

void MainWindow::onClickScan()
{
    qDebug("onClickScan");

    QWidget *scanner =  new Scanner();
    ui->mdiArea->addSubWindow(scanner);
    ui->mdiArea->showMaximized();
    scanner->show();
}

void MainWindow::putTexts()
{
    setWindowTitle(APP_NAME);
}

void MainWindow::setuid()
{
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(onClickExit()));
    connect(ui->actionEchoClient, SIGNAL(triggered()), SLOT(onClickClientEcho()));
    connect(ui->actionEchoServer, SIGNAL(triggered()), SLOT(onClickServerEcho()));
    connect(ui->actionAbout, SIGNAL(triggered()), SLOT(onClickAbout()));
    connect(ui->actionScan, SIGNAL(triggered()), SLOT(onClickScan()));
    setCentralWidget(ui->mdiArea);
}
