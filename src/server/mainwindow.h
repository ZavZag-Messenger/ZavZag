#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#ifndef SRV_SERVER_H
#   include "srv_server.h"
#endif

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

public slots:
    void onStart();
	void onStop( );

private:
	Ui::CMainWindowClass ui;
	srv::CServer* m_pServer;
};

#endif // MAINWINDOW_H
