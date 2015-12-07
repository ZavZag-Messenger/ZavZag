#include "mainwindow.h"
#include <QMessageBox>

CMainWindow::CMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	connect( ui.pushButton, SIGNAL( clicked() ), SLOT( onCreateTables() ) );
}

CMainWindow::~CMainWindow()
{

}


void CMainWindow::onCreateTables()
{
	uint nHash = qHash( QString( "Aramamv@mail.ru" ) );
	try
	{
		m_pDataManager.reset( new srv::CDataManager( ) );
	}
	catch (zz::CException const& oErr)
	{
		QMessageBox::critical( 0, "Error", oErr.what() );
		return;
	}
	catch (std::exception const& oErr)
	{
		QMessageBox::critical( 0, "Error", oErr.what( ) );
		return;
	}
}