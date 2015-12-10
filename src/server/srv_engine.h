/*
File:
	srv_engin.h
Abstract:
	Defines the server engine class which performes request execution
*/

#ifndef SRV_ENGINE_H
#define SRV_ENGINE_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef ZZ_CORE_H
#   include "zz_core.h"
#endif

#ifndef ZZ_SOCKET_H
#	include "zz_socket.h"
#endif

#ifndef SRV_DATA_MANAGER_H
#	include "srv_datamanager.h"
#endif

//	Qt includes
#include <QMutex>
// STD
#include <memory>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace srv { // Server
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	class CServerEngin
//!	The Main class which performes request execution
class CServerEngin : public QObject
{
	Q_OBJECT
	// Type Redefinitions
	typedef QObject Base;
	typedef QSharedPointer<zz::CSocket>      t_SocketPtr;
	typedef QHash<zz::CSocket*, t_SocketPtr> t_SocketHash;
	typedef QScopedPointer<CDataManager>     t_DataManagerPtr;

public:
	//! Default Constructor
	inline CServerEngin( QObject* pParent = nullptr );
	//! Destructor
	virtual ~CServerEngin();

public:
	//
	//	Main Interface
	//
	void addSession( zz::CSocket* pSocket );

public slots:
	//
	//	Public Slots
	//
    //! Proceses current request and sends response back 
    void onNewRequest( zz::CRequest* pRequest );
	void onRequestWasSent();
	void onDisconnected();
	void onError();

private:
	//
	//	Content
	//
	QMutex m_oMutex;
	//t_SocketList m_lstSockets;
	t_SocketHash     m_hshSockets;
	t_DataManagerPtr m_pDataManager;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

//! Constructor
inline CServerEngin::CServerEngin( QObject* pParent )
	: Base( pParent )
{
	m_pDataManager.reset( new CDataManager() );
}

////////////////////////////////////////////////////////////////////////////////
} // namespace srv
////////////////////////////////////////////////////////////////////////////////

#endif // SRV_ENGINE_H
/* end of file */
