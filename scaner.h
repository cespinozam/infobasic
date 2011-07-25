#ifndef SCANER_H
#define SCANER_H

#include "IForm.h"
#include <QWidget>

namespace Ui {
    class scaner;
}

class scaner : public QWidget
{
    Q_OBJECT

public:
    explicit scaner(QWidget *parent = 0);
    virtual ~scaner();

protected:
    virtual void putTexts();
    virtual void setuid();

private:
    Ui::scaner *ui;
};

#endif // SCANER_H
