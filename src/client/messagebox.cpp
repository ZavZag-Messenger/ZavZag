#include "messagebox.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
//#include <QSpacerItem>


namespace zz_cl
{


CMessageBox::CMessageBox(QWidget *pParent)
    : QWidget(pParent)
{
	m_pConnection = CConnection::getInstance();

    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
	setLayout( pVBoxLayout );

	makeMessageStory( pVBoxLayout );
	makeMessageRedactor( pVBoxLayout );
		 
	QObject::connect( m_pSendMessageButton, SIGNAL( pressed() ), this, SLOT( sendMessage() ) );
	QObject::connect( m_pConnection, SIGNAL( newMessage( QString ) ), this, SLOT( reciveMessage( QString ) ) );
}


void CMessageBox::makeMessageStory( QVBoxLayout *pLayout )
{
	m_pScrollArea = new QScrollArea( this );
	m_pScrollArea->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );
	pLayout->addWidget( m_pScrollArea );
	pLayout->setStretchFactor( m_pScrollArea, 10 );

	m_pScrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
	m_pScrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	m_pScrollArea->setUpdatesEnabled( true );
	m_pScrollArea->verticalScrollBar()->setSliderDown( true );
//	m_pScrollArea->verticalScrollBar()->setTracking( true );
		 
	QWidget *pScrollWidget = new QWidget;
	m_pScrollWidgetLayout = new QGridLayout;
	m_pScrollWidgetLayout->setColumnStretch( 0, 10 );
	m_pScrollWidgetLayout->setColumnStretch( 2, 10 );
	m_pScrollWidgetLayout->setSpacing( 10 );
	m_pScrollWidgetLayout->setMargin( 10 );
	pScrollWidget->setStyleSheet( "background: grey" );
	pScrollWidget->setLayout( m_pScrollWidgetLayout );
	m_pScrollArea->setWidget( pScrollWidget );
	m_pScrollArea->setWidgetResizable( true );

}


void CMessageBox::makeMessageRedactor( QVBoxLayout *pLayout )
{
    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    pLayout->addItem(pVBoxLayout);
	pLayout->setStretchFactor( pVBoxLayout, 1 );

    m_pMessageRedactor = new QTextEdit(this);
	m_pMessageRedactor->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::Minimum );

	m_pMessageRedactor->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
	m_pMessageRedactor->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    pVBoxLayout->addWidget(m_pMessageRedactor);
	
    m_pSendMessageButton = new QPushButton("send", this);
    m_pSendMessageButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    pVBoxLayout->addWidget(m_pSendMessageButton);

//		FOR DEBUG
	//QPushButton* pReciveMessage = new QPushButton("recive", this);
	//pReciveMessage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	//pHBoxLayout->addWidget(pReciveMessage);
	//QObject::connect( pReciveMessage, SIGNAL( pressed() ), this, SLOT( reciveMessage() ) );
}


void CMessageBox::appendMessage(QString sMessage, bool bMyMessage)
{
	if (sMessage.isEmpty())
		return;

	CMessage* pMsg = new CMessage(sMessage, bMyMessage);
	int nRow = m_pScrollWidgetLayout->rowCount();
	if ( bMyMessage )
    {
		m_pScrollWidgetLayout->addWidget( pMsg, nRow, 1, 1, 2, Qt::AlignTop );
    }
    else
    {
		m_pScrollWidgetLayout->addWidget( pMsg, nRow, 0, 1, 2, Qt::AlignTop );
    }


	QWidget* pSpacer = new QWidget();
	m_pScrollWidgetLayout->addWidget( pSpacer, nRow + 1, 0, 1, 3 );
	m_pScrollWidgetLayout->setRowStretch( nRow, 1 );
	m_pScrollWidgetLayout->setRowStretch( nRow + 1, 10 );

//	m_pScrollArea->verticalScrollBar()->setSliderPosition( INT_MAX );
}


void CMessageBox::sendMessage()
{
	QString sMessage = m_pMessageRedactor->toPlainText();
    appendMessage(sMessage, true);

	zz::CRequest* pRequest = new zz::CRequest( zz::ERequestType::SendMessage, sMessage.toUtf8() );
	m_pConnection->sendRequest( pRequest );

    m_pMessageRedactor->clear();
}


void CMessageBox::reciveMessage( QString sMessage)
{
	appendMessage( sMessage, false );
}


void CMessageBox::showMessaging( QWidgetItem* pItem )
{
	CFriendWidget* pFriend = dynamic_cast<CFriendWidget*>(pItem);
	if ( pFriend )
	{
		zz::CRequest* pRequest = new zz::CRequest( zz::ERequestType::ShowMessaging );
		m_pConnection->sendRequest( pRequest );
	}
}


} // namespace zz_cl
// end of file
