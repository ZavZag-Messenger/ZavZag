#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"

#ifndef SRV_DATA_MANAGER_H
#   include "srv_datamanager.h"
#endif

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

public slots:
    void onCreateTables();

private:
	Ui::CMainWindowClass ui;
	QScopedPointer<srv::CDataManager> m_pDataManager;
};

#endif // MAINWINDOW_H
