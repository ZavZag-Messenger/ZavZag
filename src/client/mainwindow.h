#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "user.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openLogInPage();
    void openMainPage();

private:
    CUser* createUser();

};

#endif // MAINWINDOW_H
