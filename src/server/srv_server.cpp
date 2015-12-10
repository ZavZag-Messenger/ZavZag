/*
File:
	srv_server.cpp
Abstract:
	Implementation file for the server stuff
*/

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#include "srv_server.h"
#include "zz_socket.h"
//	Qt includes

////////////////////////////////////////////////////////////////////////////////



//
//	class CSwe
//
//! Destructor
srv::CServer::~CServer()
{}


// onStart 
void srv::CServer::onStart()
{
	if (!Base::listen( QHostAddress::Any, zz::g_nPort ))
	{
		QString sErrMsg = Base::errorString();
		throw zz::CException( zz::qtr( "Unable Start Server: %1" ).arg( sErrMsg ) );
	}
}

// onStop
void srv::CServer::onStop()
{
	Base::close();
}

// incomingConnection
void srv::CServer::incomingConnection( qintptr nSocketDescriptor ) 
{
	zz::CSocket* pSocket = new zz::CSocket();
	pSocket->setSocketDescriptor( nSocketDescriptor );
	CServerEngin* pEngine = getSutableEngine();
	pEngine->addSession( pSocket );
}

srv::CServerEngin* srv::CServer::getSutableEngine()
{
	// Shoud be developed so that it will provide task distribution
	return m_lstEngines.first();
}

/*end of file*/
