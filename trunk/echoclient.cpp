#include "echoclient.h"
#include "ui_echoclient.h"
#include "qtudpclient.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QHostInfo>
#include <QMessageBox>
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
    this->setWindowTitle(tr("UDP echo client"));
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

    QHostInfo info = QHostInfo::fromName(ui->leServerName->text());
    if (!info.addresses().isEmpty())
    {
        QHostAddress address = info.addresses().first();
        QByteArray ba = ui->leText->text().toLocal8Bit();
        const char *txt = ba.data();
        qint16 len = ui->leText->text().length();
        qint16 port = ui->sldPort->value();

        QUdpSocket *udp =new QUdpSocket(this);
        udp->writeDatagram(txt, len, address,  port);
        delete udp;
    } else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Error"));
        msgBox.setText(tr("Error host not found"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    }
}
