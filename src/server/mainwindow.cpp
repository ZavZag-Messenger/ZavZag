#include "mainwindow.h"
#include <QMessageBox>

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_pServer = new srv::CServer( this );
	ZZ_ASSERT( connect( ui.btnStart, SIGNAL( clicked() ), 
		       m_pServer, SLOT( onStart() ) )
			 );
	ZZ_ASSERT( connect( ui.btnStop, SIGNAL( clicked( ) ),
		m_pServer, SLOT( onStop() ) )
		);
}

CMainWindow::~CMainWindow()
{
}


void CMainWindow::onStart()
{

}


void CMainWindow::onStop( )
{
}