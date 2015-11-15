/********************************************************************************
** Form generated from reading UI file 'cl_mainwindow.ui'
**
** Created: Sun Nov 15 22:17:44 2015
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CL_MAINWINDOW_H
#define UI_CL_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMainWindowClass)
    {
        if (CMainWindowClass->objectName().isEmpty())
            CMainWindowClass->setObjectName(QString::fromUtf8("CMainWindowClass"));
        CMainWindowClass->resize(600, 400);
        menuBar = new QMenuBar(CMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CMainWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CMainWindowClass->setStatusBar(statusBar);

        retranslateUi(CMainWindowClass);

        QMetaObject::connectSlotsByName(CMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowClass)
    {
        CMainWindowClass->setWindowTitle(QApplication::translate("CMainWindowClass", "CMainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowClass: public Ui_CMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CL_MAINWINDOW_H
