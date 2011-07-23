#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "IForm.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public IForm
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onClickExit();
    void onClickClientEcho();
    void onClickServerEcho();
    void onClickAbout();

public:
    virtual void putTexts();
    virtual void setuid();

public:
     static const char* APP_NAME;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
