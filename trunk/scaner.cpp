#include "scaner.h"
#include "ui_scaner.h"

scaner::scaner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scaner)
{
    ui->setupUi(this);
}

scaner::~scaner()
{
    delete ui;
}

virtual void putTexts();
virtual void setuid();
