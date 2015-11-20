#ifndef CL_CMAINWINDOW_H
#define CL_CMAINWINDOW_H

#include <QMainWindow>
#include "ui_cl_mainwindow.h"

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CMainWindow(QWidget *parent = 0);
	~CMainWindow();

private:
	Ui::CMainWindowClass ui;
};

#endif // CL_CMAINWINDOW_H
