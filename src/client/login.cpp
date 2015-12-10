#include "login.h"
#include "zz_utility.h"
#include <QLabel>
#include <QSplitter>


namespace zz_cl
{


CLogIn::CLogIn( QWidget* pParent )
		: QWidget( pParent )
{
	QHBoxLayout *pLayout = new QHBoxLayout( this );
	setLayout( pLayout );

	makeUserName( pLayout );
	makePassword( pLayout );
	makeLogInButton( pLayout );

	setConnections();

	setFixedSize( sizeHint() );
}


void CLogIn::makeUserName( QLayout* pLayout )
{
	QVBoxLayout *pLoginLayout = new QVBoxLayout;
	pLayout->addItem( pLoginLayout );

	QLabel *pTitle = new QLabel( "Log In", this );
	pLoginLayout->addWidget( pTitle );

	m_pUserName = new QLineEdit( this );
	m_pUserName->setFixedSize( m_pUserName->sizeHint() );
	m_pUserName->setMaxLength( 8 );

	pLoginLayout->addWidget( m_pUserName );
}


void CLogIn::makePassword( QLayout* pLayout )
{
	QVBoxLayout *pPasswordLayout = new QVBoxLayout;
	pLayout->addItem( pPasswordLayout );

	QLabel *pTitle = new QLabel( "Password", this );
	pPasswordLayout->addWidget( pTitle );

	m_pPassword = new QLineEdit( this );
	m_pPassword->setFixedSize( m_pPassword->sizeHint() );
	m_pPassword->setMaxLength( 8 );
	m_pPassword->setEchoMode( QLineEdit::Password );

	pPasswordLayout->addWidget( m_pPassword );
}


void CLogIn::makeLogInButton( QLayout* pLayout )
{
	QVBoxLayout *pLoginButtonLayout = new QVBoxLayout();
	pLayout->addItem( pLoginButtonLayout );

	QSplitter *pSpliter = new QSplitter( this );
	pLoginButtonLayout->addWidget( pSpliter );

	m_pLoginButton = new QPushButton( "Log in", this );
	m_pLoginButton->setFixedSize( m_pLoginButton->sizeHint() );

	pLoginButtonLayout->addWidget( m_pLoginButton );
}



void CLogIn::setConnections()
{
	QObject::connect( m_pLoginButton, SIGNAL( clicked( bool ) ), this, SLOT( loginRequest() ) );
}


void CLogIn::sendRequest()
{
	if ( !isValid() )
	{
		return;
	}

	zz::CUserInfo userInfo;
	userInfo.setUsername( m_pUserName->text() );
	userInfo.setPassword( m_pPassword->text() );

	zz::CRequest* pRequest = new zz::CRequest( zz::ERequestType::Login, userInfo.toRequestData() );

	CConnection* pConnection = CConnection::getInstance();
	pConnection->sendRequest( pRequest );
}


bool CLogIn::isValid() const
{
	bool bUserName = !m_pUserName->text().isEmpty();
	bool bPassword = !m_pPassword->text().isEmpty();

	return (bUserName && bPassword);
}


} // namespace zz_cl

// end of file