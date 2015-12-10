#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//////////////////////////////////////////////////
//	includes
//////////////////////////////////////////////////
#include <QMainWindow>
#include <QStatusBar>
#include "loginpage.h"
#include "connection.h"
#include "zz_utility.h"


namespace zz_cl
{






//////////////////////////////////////////////////
//	This is main window
//////////////////////////////////////////////////
class CMainWindow : public QMainWindow
{
    Q_OBJECT
public:
	//
	//	construector
	//
	CMainWindow( QWidget* pParent = nullptr );
	//
	//	destructor
	//
    ~CMainWindow();

public slots: // maybe private slots:
	//
	//	open LogIn page slot 
	//
    void openLogInPage();
	//
	//	open maine page slot
	//
	void openMainPage( zz::CUserInfo* pUser );
	//
	//	open loading bar
	//
	void makeStatusBar();

public:
	//
	//	connect to server
	//
	void connect();

private:
	//
	//	set connections
	//
	void setConnections();

private:
	//
	//	members
	//
	CConnection* m_pConnection;
	CLogInPage* m_pLoginPage;
	QStatusBar* m_pStatusBar;

};


} // namespace zz_cl


#endif // MAINWINDOW_H
//	end of file