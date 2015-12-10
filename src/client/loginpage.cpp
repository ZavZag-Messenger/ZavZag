#include "loginpage.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>


namespace zz_cl
{


CLogInPage::CLogInPage(QWidget* pParent) 
			: QWidget( pParent )
{
	QHBoxLayout* pLayout = new QHBoxLayout( this );
	setLayout( pLayout );

	makePageLeftSide( pLayout );

	setConnections();
}


void CLogInPage::makePageLeftSide( QHBoxLayout* pLayout )
{
    QVBoxLayout* pLeftSideLayout = new QVBoxLayout;
	pLayout->addItem( pLeftSideLayout );

	makeLogIn( pLeftSideLayout );
	makeRegister( pLeftSideLayout );
}


void CLogInPage::makeLogIn( QVBoxLayout* pLayout )
{
	m_pLogin = new CLogIn( this );
	pLayout->addWidget( m_pLogin, 0, Qt::AlignTop );
}


void CLogInPage::makeRegister( QVBoxLayout* pLayout )
{
	m_pRegisterModeButton = new QRadioButton( "Ragister", this );
	pLayout->addWidget( m_pRegisterModeButton, 0, Qt::AlignTop );

	m_pRegister = new zz_cl::CRegister( "Register", this );
	pLayout->addWidget( m_pRegister, 0, Qt::AlignTop );
	m_pRegister->setHidden( true );
	m_pRegister->setEnabled( false );
}


void CLogInPage::setConnections()
{
	QObject::connect( m_pRegister, SIGNAL( registerClicked() ), this, SIGNAL( registerRequest() ) );
	QObject::connect( m_pRegisterModeButton, SIGNAL( clicked() ), this, SLOT( registerClicled() ) );
	QObject::connect( m_pLogin, SIGNAL( loginClicked() ), this, SIGNAL( loginRequest() ) );
}


void CLogInPage::openRegister()
{
	m_pRegister->setEnabled( true );
	m_pLogin->setDisabled( true );
	m_pRegister->setHidden( false );
}


void CLogInPage::closeRegister()
{
	m_pLogin->setEnabled( true );
	m_pRegister->setDisabled( true );
	m_pRegister->setHidden( true );
}


void CLogInPage::registerClicled()
{
	if ( m_pRegister->isEnabled() )
	{
		closeRegister();
	}
	else
	{
		openRegister();
	}
}


} // nemespece zz_cl

// end of file