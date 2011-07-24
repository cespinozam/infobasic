#include "echoclient.h"
#include "ui_echoclient.h"
#include "qtudpclient.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <iostream>

const quint16 EchoClient::PORT_MIN = 1;
const quint16 EchoClient::PORT_MAX = 65535;
const quint16 EchoClient::PORT_DEFAULT = 8888;

EchoClient::EchoClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EchoClient)
{
    ui->setupUi(this);
    putTexts();
    setuid();
}

EchoClient::~EchoClient()
{
    delete ui;
    qDebug("Delete EchoClient");
}

void EchoClient::putTexts()
{
    ui->lbServerName->setText(tr("Server Name"));
    ui->lbText->setText(tr("Text"));
    ui->lbPort->setText(tr("Port"));
    ui->leServerName->setText("localhost");
    ui->pbSend->setText(tr("Send"));

}

void EchoClient::setuid()
{
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->pbSend, SIGNAL(clicked()),SLOT(onClickSend()));
    connect(ui->sldPort, SIGNAL(valueChanged(int)), ui->lcdPort, SLOT(display(int)));

    ui->sldPort->setMinimum(EchoClient::PORT_MIN);
    ui->sldPort->setMaximum(EchoClient::PORT_MAX);
    ui->sldPort->setValue(EchoClient::PORT_DEFAULT);
}

void EchoClient::onClickSend()
{
    qDebug("onClickSend");
    QUdpSocket *udp =new QUdpSocket(this);
    const QHostAddress *host = new QHostAddress(ui->leServerName->text());

    QByteArray ba = ui->leText->text().toLocal8Bit();
    const char *txt = ba.data();
    qint16 len = ui->leText->text().length();
    qint16 port = ui->sldPort->value();
    udp->writeDatagram(txt, len, QHostAddress::LocalHost,  port);
    qDebug(ui->leServerName->text().toStdString().c_str());
    delete host;
    delete udp;
}
