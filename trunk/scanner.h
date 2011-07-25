#ifndef SCANNER_H
#define SCANNER_H

#include "IForm.h"
#include <QWidget>

namespace Ui {
    class Scanner;
}

class Scanner : public QWidget
{
    Q_OBJECT

public:
    explicit Scanner(QWidget *parent = 0);
    virtual ~Scanner();

protected:
    virtual void putTexts();
    virtual void setuid();

private:
    Ui::Scanner *ui;
};

#endif // SCANNER_H
