#include "message.h"


CMessage::CMessage( const QString & sText, bool bSent, QWidget *pParent )
			: QTextEdit( pParent ),
			  m_bSent( bSent )
{
	setReadOnly( true );

	setPlainText( sText );

	if ( bSent )
	{
		setStyleSheet( "background: blue; color: white" );
		setAlignment( Qt::AlignLeft | Qt::AlignVCenter );
	}
	else
	{
		setStyleSheet( "background: green; color: white" );
		setAlignment( Qt::AlignLeft | Qt::AlignVCenter );
	}
}