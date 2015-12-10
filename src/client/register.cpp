#include "register.h"
#include "connection.h"
#include "zz_utility.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>


namespace zz_cl
{


CRegister::CRegister(const QString & title, QWidget* pParent)
           : QWidget( pParent )
{
    QVBoxLayout *pLayout = new QVBoxLayout(this);
    setLayout(pLayout);

    makeFirstNameField(pLayout);
    makeLastNameField(pLayout);
    makeUserNameField(pLayout);
    makePasswordField(pLayout);
    makeGenderField(pLayout);
    makeBirthdayField(pLayout);
    makeRegisterButton(pLayout);
}


void CRegister::makeFirstNameField(QLayout *pLayout)
{
    QLabel *pTitle = new QLabel("FirstName *", this);
    pLayout->addWidget(pTitle);

    m_pFirstNameField = new QLineEdit(this);
    m_pFirstNameField->setMaxLength(8);
    m_pFirstNameField->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pLayout->addWidget(m_pFirstNameField);
}


void CRegister::makeLastNameField(QLayout *pLayout)
{
    QLabel *pTitle = new QLabel("LastName *", this);
    pLayout->addWidget(pTitle);

    m_pLastNameField = new QLineEdit(this);
    m_pLastNameField->setMaxLength(12);
    m_pLastNameField->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pLayout->addWidget(m_pLastNameField);
}


void CRegister::makeUserNameField(QLayout *pLayout)
{
    QLabel *pTitle = new QLabel("UserName *", this);
    pLayout->addWidget(pTitle);

    m_pUserNameField = new QLineEdit(this);
    m_pUserNameField->setMaxLength(8);
    m_pUserNameField->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pLayout->addWidget(m_pUserNameField);
}


void CRegister::makePasswordField(QLayout *pLayout)
{
    QLabel *pPasswordTitle = new QLabel("Password *", this);
    pLayout->addWidget(pPasswordTitle);

    m_pPasswordField = new QLineEdit(this);
    m_pPasswordField->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    m_pPasswordField->setMaxLength(8);
    m_pPasswordField->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pLayout->addWidget(m_pPasswordField);

    QLabel *pPasswordConfirmTitle = new QLabel("Confirm password *", this);
    pLayout->addWidget(pPasswordConfirmTitle);

    m_pConfirmPasswordField = new QLineEdit(this);
    m_pConfirmPasswordField->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    m_pConfirmPasswordField->setMaxLength(m_pPasswordField->maxLength());
    m_pConfirmPasswordField->setSizePolicy(m_pPasswordField->sizePolicy());
    m_pConfirmPasswordField->setDisabled(true);

    QRegExpValidator *pValidator = new QRegExpValidator(m_pConfirmPasswordField);
    m_pConfirmPasswordField->setValidator(pValidator);

    pLayout->addWidget(m_pConfirmPasswordField);

    QObject::connect(m_pPasswordField, SIGNAL(textChanged(QString)), this, SLOT(passwordEdited()));
}


void CRegister::makeGenderField(QLayout *pLayout)
{
    QLabel *pTitle = new QLabel("Gender", this);
    pLayout->addWidget(pTitle);

    QHBoxLayout *pGendLayout = new QHBoxLayout();
    pLayout->addItem(pGendLayout);

    m_pGender = new QButtonGroup(this);

    QCheckBox *pMale = new QCheckBox("male", this);
	pMale->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
    pMale->setCheckable(true);
    pMale->setChecked(false);
    pGendLayout->addWidget(pMale);

    m_pGender->addButton(pMale);

    QCheckBox *pFeMale = new QCheckBox("female", this);
	pFeMale->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
    pFeMale->setCheckable(true);
    pFeMale->setChecked(false);
    pGendLayout->addWidget(pFeMale);

    m_pGender->addButton(pFeMale);
}


void CRegister::makeBirthdayField(QLayout *pLayout)
{
    QLabel *pTitle = new QLabel("Birthday date", this);
    pLayout->addWidget(pTitle);

    m_pBirthdayField = new QDateEdit(this);
	m_pBirthdayField->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

    pLayout->addWidget(m_pBirthdayField);
}


void CRegister::makeRegisterButton(QLayout *pLayout)
{
    m_pRegisterButton = new QPushButton("Register", this);
    m_pRegisterButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    pLayout->addWidget(m_pRegisterButton);

	QObject::connect( m_pRegisterButton, SIGNAL( clicked( bool ) ), this, SLOT( registerRequest() ) );
}


void CRegister::registerRequest()
{
	if ( !isValid() )
	{
		//
	}

	zz::CUserInfo userInfo;
	userInfo.setUsername( m_pUserNameField->text() );
	userInfo.setFirstName( m_pFirstNameField->text() );
	userInfo.setLastName( m_pLastNameField->text() );
	userInfo.setPassword( m_pPasswordField->text() );
	if ( m_pGender->checkedId() == 0 )
	{
		userInfo.setGender( zz::EGender::Male );
	}
	else if ( m_pGender->checkedId() == 1 )
	{
		userInfo.setGender( zz::EGender::Female );
	}
	else
	{
		userInfo.setGender( zz::EGender::Undefined );
	}
	userInfo.setBirthday( m_pBirthdayField->date() );


	zz::CRequest* pRequest = new zz::CRequest( zz::ERequestType::Register, userInfo.toRequestData() );
	ZZ_ASSERT( pRequest );
	
	CConnection* pConnection = CConnection::getInstance();
	pConnection->sendRequest( pRequest );
}


void CRegister::passwordEdited()
{
    if (m_pPasswordField->text().isEmpty())
    {
        m_pConfirmPasswordField->setDisabled(true);
    }
    else
    {
        m_pConfirmPasswordField->setEnabled(true);
    }

    const QValidator *pValidator = m_pConfirmPasswordField->validator();
    QRegExpValidator *pRegValid = dynamic_cast<QRegExpValidator*>(const_cast<QValidator*>(pValidator));
    pRegValid->setRegExp(QRegExp(m_pPasswordField->text()));
}


bool CRegister::isValid() const
{
	bool bUserName = !m_pUserNameField->text().isEmpty();
	bool bFirstName = !m_pFirstNameField->text().isEmpty();
	bool bLastName = !m_pLastNameField->text().isEmpty();
	bool bPassword = !m_pPasswordField->text().isEmpty();
	bool bConfirmPassword = !m_pConfirmPasswordField->text().isEmpty();

	return ( bUserName && bFirstName && bLastName && bPassword && bConfirmPassword );
}


} // namespace zz_cl

// end of file