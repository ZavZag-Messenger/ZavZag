#ifndef CMESSAGEBOX_H
#define CMESSAGEBOX_H
////////////////////////////////////////////////////////////
//
//	includes
//
////////////////////////////////////////////////////////////
#include <QWidget>
#include <QTextEdit>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHash>
#include "friendwidget.h"
#include "connection.h"
#include "message.h"
//#include "messagestorylayout.h"


namespace zz_cl
{


////////////////////////////////////////////////////////////
//
//	This class is message box widget
//
////////////////////////////////////////////////////////////
class CMessageBox : public QWidget
{
    Q_OBJECT
public:
	//
	//	constructor
	//
    explicit CMessageBox(QWidget *pParent = nullptr);

private:
	//
	//	make message story wich show's messages
	//
	void makeMessageStory( QVBoxLayout *pLayout );
	//
	//  make message redactor
	//
	void makeMessageRedactor( QVBoxLayout *pLayout );

private slots: // maybe private slots:
	//
	//	append new message
	//
    void appendMessage(QString sMessage, bool bMyMessage);

public slots:
	//
	//	send message
	//
    void sendMessage();
	//
	//	recive message
	//
	void reciveMessage( QString );
	//
	//
	//
	void showMessaging( QWidgetItem* );

private:
	//
	//	members
	//
	CConnection* m_pConnection;
    QScrollArea *m_pScrollArea;
    QTextEdit *m_pMessageRedactor;
    QPushButton *m_pSendMessageButton;
	QGridLayout *m_pScrollWidgetLayout;

};


} // namespace zz_cl


#endif // CMESSAGEBOX_H
// end of file