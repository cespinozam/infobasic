#include "echoserver.h"
#include "ui_echoserver.h"
#include <QDateTime>

const quint16 EchoServer::PORT_MIN = 1;
const quint16 EchoServer::PORT_MAX = 65535;
const quint16 EchoServer::PORT_DEFAULT = 8888;

const QString EchoServer::START = tr("Start");
const QString EchoServer::STOP = tr("Stop");

EchoServer::EchoServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EchoServer)
{
    ui->setupUi(this);
    this->udpServer = new QUdpSocket(this);
    this->started = false;
    putTexts();
    setuid();    
}

EchoServer::~EchoServer()
{
    delete ui;
    delete this->udpServer;
    qDebug("Delete EchoServer");
}

void EchoServer::putTexts()
{
    this->setWindowTitle(tr("Servidor echo UDP"));
    ui->lbPort->setText(tr("Port"));
    ui->pbStart->setText(tr("Start"));
}

void EchoServer::setuid()
{
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->pbStart, SIGNAL(clicked()),SLOT(onClickStart()));
    connect(ui->sldPort, SIGNAL(valueChanged(int)), ui->lcdPort, SLOT(display(int)));

    ui->sldPort->setMinimum(EchoServer::PORT_MIN);
    ui->sldPort->setMaximum(EchoServer::PORT_MAX);
    ui->sldPort->setValue(EchoServer::PORT_DEFAULT);
}

void EchoServer::onClickStart()
{

    if(!this->started)
    {
        qDebug("Server started");
        quint16 port = ui->lcdPort->value();
        udpServer->bind(port, QUdpSocket::ShareAddress);
        connect(udpServer, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
        ui->pbStart->setText(STOP);
    } else
    {
        qDebug("Server stoped");
        udpServer->close();
        ui->pbStart->setText(START);
    }

    this->started = !this->started;
}

void EchoServer::readPendingDatagrams()
{
    qDebug("readPendingDatagrams");
    while (udpServer->hasPendingDatagrams())
    {
         QByteArray datagram;
         datagram.resize(udpServer->pendingDatagramSize());
         QHostAddress sender;
         quint16 senderPort;

         udpServer->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);

         QString str(datagram);
         str.append(" from " + sender.toString() + " on " + QDateTime::currentDateTime().toString()+ "\n");
         ui->textBrowser->insertPlainText(str);
         udpServer->writeDatagram(datagram, sender, senderPort);
     }
}

