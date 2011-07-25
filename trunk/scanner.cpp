#include "scanner.h"
#include "ui_scanner.h"

Scanner::Scanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scanner)
{
    ui->setupUi(this);
    putTexts();
    setuid();
}

Scanner::~Scanner()
{
    delete ui;
}

void Scanner::putTexts()
{
    this->setWindowTitle(tr("Scanner"));
    this->ui->lbIp->setText(tr("Ip"));
    this->ui->lbSubnet->setText(tr("Subnet"));
    this->ui->lbGateway->setText(tr("Gateway"));
}

void Scanner::setuid()
{

}
