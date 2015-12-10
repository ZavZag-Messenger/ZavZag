/*
File:
	srv_server.h
Abstract:
	Defines the main stuff to serves to the zz clients 
*/

#ifndef SRV_SERVER_H
#define SRV_SERVER_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef SRV_ENGINE_H
#   include "srv_engine.h"
#endif

//	Qt includes
#include <QTcpServer>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace srv { // Server
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	class CServer
//!	The Main class which listen predefined port and serves to the zz clients
class CServer : public QTcpServer
{
	Q_OBJECT
	typedef QTcpServer Base;
	typedef QList<CServerEngin*> t_EngineList;
public:
	// Request data definition
	//typedef

public:
	//! Default Constructor
	inline CServer( QObject* pParent = nullptr );
	//! Destructor
	virtual ~CServer();

public:
	//
	//	Main Interface
	//

public slots:
	//
	//	Public Slots
	//
	void onStart();
	void onStop();

public:
	//
	//	QTcpServer Interface
	//
	void incomingConnection( qintptr socketDescriptor ) override;

private:
	//
	//	Helper Methods
	//
	// 
	// Returns the engin that is most sutable to take sessions 
	// in currently and protectes task distribution lgistics
	CServerEngin* getSutableEngine();

private:
	//
	//	Content
	//
	t_EngineList m_lstEngines;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

//! Constructor
inline CServer::CServer( QObject* pParent )
	: Base( pParent )
{
	CServerEngin* pEngin = new CServerEngin( this );
	m_lstEngines.append( pEngin );
}

////////////////////////////////////////////////////////////////////////////////
} // namespace srv
////////////////////////////////////////////////////////////////////////////////

#endif // SRV_SERVER_H
/* end of file */
