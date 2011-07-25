#ifndef ECHOSERVER_H
#define ECHOSERVER_H

#include "IForm.h"
#include <QWidget>
#include <QUdpSocket>

namespace Ui {
    class EchoServer;
}

class EchoServer : public QWidget
{
    Q_OBJECT

public:
    explicit EchoServer(QWidget *parent = 0);
    virtual ~EchoServer();
    static const quint16 PORT_MIN;
    static const quint16 PORT_MAX;
    static const quint16 PORT_DEFAULT;

protected:
    QUdpSocket *udpServer;

    virtual void putTexts();
    virtual void setuid();

    static const QString START;
    static const QString STOP;

public slots:
    void onClickStart();
    void readPendingDatagrams();

private:
    Ui::EchoServer *ui;
    bool started;

};

#endif // ECHOSERVER_H
