#ifndef CLOGIN_H
#define CLOGIN_H

#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>

class CLogIn : public QWidget
{
    Q_OBJECT
public:
    explicit CLogIn(QWidget *pParent = 0);

signals:
    void registerClicked();
    void loginClicked();

public slots:
    void registerRequest();
    void loginRequest();

private:
    void makePageLeftSide(QLayout *pLayout);
    void makeLogIn(QLayout *pLayout);
    void makePassword(QLayout *pLayout);
    void makeLogInButton(QLayout *pLayout);
    void makeRegister(QLayout *pLayout);

private:
    QLineEdit *m_pLogin;
    QLineEdit *m_pPassword;
    QPushButton *m_pLoginButton;

};

#endif // CLOGIN_H
