/*
	File: 
		zz_socket.cpp
	Abstract:
		Implementation CSocket class
*/

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#include "zz_socket.h"
////////////////////////////////////////////////////////////////////////////////

//
//	class CSocket
//
//! Destructor
zz::CSocket::~CSocket()
{}

// readRequest
zz::CRequest* zz::CSocket::readRequest()
{
	if( bytesAvailable() < 5 )
		return nullptr;

	QDataStream oIn(this);
	quint8  unType = 0;
	quint32 unSize = 0;
	oIn >> unType;
	oIn >> unSize;
	while ( bytesAvailable() < unSize )
		// Should be tested
		waitForReadyRead();
	QByteArray aDataBuffer = read( unSize );
	// Should be removed
	ZZ_ASSERT( aDataBuffer.size() == unSize );
	if( aDataBuffer.size() != unSize )
		// Malformed buffer
		return nullptr;
	return new CRequest( ERequestType(unType), aDataBuffer );
}

/*end of file*/
