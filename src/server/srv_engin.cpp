/*
File:
	srv_engin.cpp
Abstract:
	Implementation file for the server engin class
*/

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#include "srv_engine.h"
//	Qt includes

////////////////////////////////////////////////////////////////////////////////



//
//	class CServerEngin
//
//! Destructor
srv::CServerEngin::~CServerEngin( )
{}

// addSession
void srv::CServerEngin::addSession( zz::CSocket* pSocket )
{
	if (!pSocket || !pSocket->isValid())
		return;
	t_SocketPtr spSocket( pSocket );

	m_oMutex.lock();  // Lock
	m_hshSockets.insert( pSocket, spSocket );
	// Make Connections
	QObject::connect( pSocket, SIGNAL( sigNewRequest(zz::CRequest*) ),
					  this, SLOT( onNewRequest(zz::CRequest*) ) );
	QObject::connect( pSocket, SIGNAL( sigRequestWasSent() ),
					  this, SLOT( onRequestWasSent() ) );
	QObject::connect( pSocket, SIGNAL( disconnected() ),
					  this, SLOT( onDisconnected() ) );
	QObject::connect( pSocket, SIGNAL( error() ),
					  this, SLOT( onError() ) );
	m_oMutex.unlock(); // Unlock
}

//
//	Slots
//

// 
void srv::CServerEngin::onNewRequest( zz::CRequest* pRequest )
{
	if (!pRequest)
		return;
	zz::ERequestType eType = pRequest->getType();

	// Main Switch
	switch ( eType )
	{
	case zz::ERequestType::Register:

		break;
	default:
		break;
	}
}

// 
void srv::CServerEngin::onRequestWasSent()
{

}

// 
void srv::CServerEngin::onDisconnected()
{
	zz::CSocket* pSocket = dynamic_cast<zz::CSocket*>(QObject::sender( ));
	if (!pSocket)
		return;
	m_oMutex.lock();   // Lock
	m_hshSockets.remove( pSocket );
	m_oMutex.unlock(); // Unlock
}

// 
void srv::CServerEngin::onError()
{
	zz::CSocket* pSocket = dynamic_cast<zz::CSocket*>(QObject::sender( ));
	if (!pSocket)
		return;
	QString sErrMsg = pSocket->errorString();
	pSocket->disconnect();
}



/*end of file*/
