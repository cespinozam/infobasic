#ifndef ECHOCLIENT_H
#define ECHOCLIENT_H

#include <QWidget>
#include "IForm.h"

namespace Ui {
    class EchoClient;
}

class EchoClient : public QWidget, public IForm
{
    Q_OBJECT

public:
    explicit EchoClient(QWidget *parent = 0);
    virtual ~EchoClient();

    static const quint16 PORT_MIN;
    static const quint16 PORT_MAX;
    static const quint16 PORT_DEFAULT;

protected:
    virtual void putTexts();
    virtual void setuid();

public slots:
    void onClickSend();

private:
    Ui::EchoClient *ui;
};

#endif // ECHOCLIENT_H
