#include "mainwindow.h"

//#include "loginpage.h"
#include "mainpage.h"


namespace zz_cl
{


CMainWindow::CMainWindow( QWidget* pParent )
    : QMainWindow( pParent )
{  
	m_pConnection = CConnection::getInstance();
	makeStatusBar();

//    openLogInPage();

	setConnections();
}


CMainWindow::~CMainWindow()
{
	m_pConnection->disconnect();
}


void CMainWindow::connect()
{
	if ( m_pConnection )
		m_pConnection->connect();
}


void CMainWindow::openLogInPage()
{
	m_pLoginPage = new CLogInPage( this );
	setCentralWidget( m_pLoginPage );

	setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
}


void CMainWindow::openMainPage( zz::CUserInfo* pUser )
{
    centralWidget()->deleteLater();

	CMainPage *pMainPage = new CMainPage( pUser, this );
	setCentralWidget( pMainPage );

	setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
}


void CMainWindow::makeStatusBar()
{
	m_pStatusBar = new QStatusBar( this );
	m_pStatusBar->setEnabled( true );
	m_pStatusBar->showMessage( tr("connecting") );
	setStatusBar( m_pStatusBar );
}


void CMainWindow::setConnections( )
{
	QObject::connect( m_pConnection, SIGNAL( sigConnected() ), this, SLOT( openLogInPage() ) );
	QObject::connect( m_pConnection, SIGNAL( sigConnected() ), m_pStatusBar, SLOT( clearMessage() ) );
	QObject::connect( m_pConnection, SIGNAL( login( CUser* ) ), this, SLOT( openMainPage( CUser* ) ) );
}


} // namespace zz_cl

// end of file