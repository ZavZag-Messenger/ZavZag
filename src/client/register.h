#ifndef CREGISTER_H
#define CREGISTER_H

#include <QWidget>
#include <QGroupBox>
#include <QLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QButtonGroup>
#include <QPushButton>


class CRegister : public QGroupBox
{
    Q_OBJECT
public:
    explicit CRegister(const QString & title, QWidget *parent = 0);

private:
    void makeFirstNameField(QLayout *pLayout);
    void makeLastNameField(QLayout *pLayout);
    void makeUserNameField(QLayout *pLayout);
    void makePasswordField(QLayout *pLayout);
    void makeGenderField(QLayout *pLayout);
    void makeBirthdayField(QLayout *pLayout);
    void makeRegisterButton(QLayout *pLayout);

signals:
    void registerClicked();

public slots:
    void registerRequest();
    void passwordEdited();

private:
    QLineEdit *m_pFirstNameField;
    QLineEdit *m_pLastNameField;
    QLineEdit *m_pUserNameField;
    QLineEdit *m_pPasswordField;
    QLineEdit *m_pConfirmPasswordField;
    QDateEdit *m_pBirthdayField;
    QButtonGroup *m_pGender;
    QPushButton *m_pRegisterButton;

};


#endif // CREGISTER_H
