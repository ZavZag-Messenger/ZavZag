#include "mainwindow.h"

#include "login.h"
#include "mainpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{  
    setFixedSize(sizeHint());
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    openLogInPage();

}


MainWindow::~MainWindow()
{
}


void MainWindow::openLogInPage()
{
    CLogIn *pLoginPage = new CLogIn(this);
    setCentralWidget(pLoginPage);

    QObject::connect(pLoginPage, SIGNAL(loginClicked()), this, SLOT(openMainPage()));
}


void MainWindow::openMainPage()
{
    centralWidget()->deleteLater();

    CMainPage *pMainPage = new CMainPage(createUser(), this);
    pMainPage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setFixedSize(sizeHint());

    setCentralWidget(pMainPage);
}


CUser* MainWindow::createUser()
{
    CUser *pUser = new CUser("Levon", "Gasparyan", true);

    CUser *pFr1 = new CUser("Aram", "Haxverdyan", true);
    pUser->addFriend(pFr1);

    return pUser;
}

