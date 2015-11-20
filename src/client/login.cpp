#include "login.h"
#include "register.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSplitter>


CLogIn::CLogIn(QWidget *pParent) : QWidget(pParent)
{
    QHBoxLayout *pLayout = new QHBoxLayout(this);
    setLayout(pLayout);

    makePageLeftSide(pLayout);

}

void CLogIn::makePageLeftSide(QLayout *pLayout)
{
    QVBoxLayout *pLeftSideLayout = new QVBoxLayout();
    pLayout->addItem(pLeftSideLayout);

    QHBoxLayout *pLoginLayout = new QHBoxLayout();
    pLeftSideLayout->addItem(pLoginLayout);

    makeLogIn(pLoginLayout);
    makePassword(pLoginLayout);
    makeLogInButton(pLoginLayout);
    makeRegister(pLeftSideLayout);
}


void CLogIn::makeLogIn(QLayout *pLayout)
{
    QVBoxLayout *pLoginLayout = new QVBoxLayout();
    pLayout->addItem(pLoginLayout);

    QLabel *pTitle = new QLabel("Log In", this);
    pLoginLayout->addWidget(pTitle);

    m_pLogin = new QLineEdit(this);
    m_pLogin->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pLogin->setMaxLength(8);

    pLoginLayout->addWidget(m_pLogin);
}


void CLogIn::makePassword(QLayout *pLayout)
{
    QVBoxLayout *pPasswordLayout = new QVBoxLayout();
    pLayout->addItem(pPasswordLayout);

    QLabel *pTitle = new QLabel("Password", this);
    pPasswordLayout->addWidget(pTitle);

    m_pPassword = new QLineEdit(this);
    m_pPassword->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pPassword->setMaxLength(8);
    m_pPassword->setEchoMode(QLineEdit::Password);

    pPasswordLayout->addWidget(m_pPassword);
}


void CLogIn::makeLogInButton(QLayout *pLayout)
{   
    QVBoxLayout *pLoginButtonLayout = new QVBoxLayout();
    pLayout->addItem(pLoginButtonLayout);

    QSplitter *pSpliter = new QSplitter(this);
    pLoginButtonLayout->addWidget(pSpliter);

    m_pLoginButton = new QPushButton("Log in", this);
    m_pLoginButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pLoginButtonLayout->addWidget(m_pLoginButton);

    QObject::connect(m_pLoginButton, SIGNAL(clicked(bool)), this, SLOT(loginRequest()));
}


void CLogIn::makeRegister(QLayout *pLayout)
{
    QGroupBox *pRegister = new CRegister("Register", this);
    pLayout->addWidget(pRegister);

    QObject::connect(pRegister, SIGNAL(registerClicked()), this, SLOT(registerRequest()));
}


void CLogIn::loginRequest()
{
    emit loginClicked();
}


void CLogIn::registerRequest()
{
    emit registerClicked();
}




