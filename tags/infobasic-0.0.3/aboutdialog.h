#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "IForm.h"
#include <QDialog>

namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog, public IForm
{
    Q_OBJECT

public:
    static const char* HREF;
    static const char* HREF2;
    static const char* TITLE;
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

    virtual void putTexts();
    virtual void setuid();

public slots:
    void onClickLink();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
