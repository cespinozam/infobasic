#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QUrl>
#include <QDesktopServices>

const char* AboutDialog::HREF = "<a href='http://jferconde.blogspot.com/'>Org&iacute;a de objetos</a>";
const char* AboutDialog::HREF2 = "<a href='http://jferconde.blogspot.com/'>Thank you for visiting us.</a>";
const char* AboutDialog::TITLE = "About";

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    putTexts();
    setuid();
}

AboutDialog::~AboutDialog()
{
    delete ui;
    qDebug("Delete AboutDialog");
}

void AboutDialog::onClickLink()
{
    qDebug("onClickLink");
    QString str = ui->labelLink->text();
    int startIndex = str.indexOf(QString("'"));
    int endIndex = str.indexOf(QString("'"), ++startIndex);
    qDebug(str.mid(startIndex, endIndex).toLocal8Bit().data());
    QDesktopServices::openUrl(QUrl(str.mid(startIndex, endIndex - startIndex)));
    ui->labelLink->setText(HREF2);
}

void AboutDialog::putTexts()
{
    this->setWindowTitle(TITLE);
    ui->labelLink->setText(HREF);
    ui->labelLink->adjustSize();
}

void AboutDialog::setuid()
{
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->labelLink, SIGNAL(linkActivated(QString)), this, SLOT(onClickLink()));
}
