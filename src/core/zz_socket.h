/*
	File: 
		zz_socket.h
	Abstract:
		Defines convenient interface to transmit zz requests 
*/

#ifndef ZZ_SOCKET_H
#define ZZ_SOCKET_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef ZZ_CORE_H
#	include "zz_core.h"
#endif

#ifndef ZZ_REQUEST_H
#	include "zz_request.h"
#endif

// Qt includes
#include <QTcpSocket>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace zz { //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	class CSocket
//!	TCP socket class which allows request transmission
class ZZ_CORE_EXPORT CSocket : public QTcpSocket
{	
	Q_OBJECT

public:
	//!	Constructor
	inline CSocket( QObject* pParent = nullptr );
	virtual ~CSocket();

public:
	//
	//	Extended Methods
	//
	// Send Request
	inline void sendRequest( CRequest const* pRequest );

signals:
	//
	//	Signals
	//
	// Should be used to receive requests
	void sigNewRequest( zz::CRequest* );
	// Emmits when the last request was sent
	void sigRequestWasSent();

private slots:
    //
    //  Private Slots
    //
    void onReadyReed();
	void onBytesWritten( qint64 );

private:
	//
	//  Content
	//
	qint64 m_nBytesShouldBeWritten;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////
//! Constructor
inline CSocket::CSocket(QObject* pParent)
	: QTcpSocket( pParent )
{
	// Make Connections
	Q_ASSERT( QObject::connect( 
		this, 
		SIGNAL( readyRead() ), 
		SLOT( onReadyReed() ) ) );
	Q_ASSERT( QObject::connect( 
		this, 
		SIGNAL( bytesWritten( qint64 ) ), 
		SLOT( onBytesWritten( qint64 ) ) ) );
}

// sendRequest
inline void CSocket::sendRequest( CRequest const* pRequest )
{
	if(!pRequest)
		return;
	QByteArray aBuffer = pRequest->serialize();
	m_nBytesShouldBeWritten = aBuffer.size();
	write( aBuffer );
}

// onBytesWritten
inline void CSocket::onBytesWritten( qint64 nWrittenBytes )
{
	if (nWrittenBytes < m_nBytesShouldBeWritten)
		// Weit to next call
		return;
	m_nBytesShouldBeWritten = 0;
	emit sigRequestWasSent();
}

////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

#endif // ZZ_REQUEST_H
/* end of file */