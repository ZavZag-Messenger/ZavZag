#include "connection.h"
#include <QByteArray>
#include <QHostInfo>


namespace zz_cl
{


CConnector::CConnector( QObject* pParent )
	: QObject( pParent )
{
}


void CConnector::tryToConnect( zz::CSocket* pSocket, QString const&, int nPort )
{
	if ( !pSocket )
		return;

	do
	{
		pSocket->connectToHost( QString( "10.116.88.155" ), nPort, QIODevice::ReadWrite );
	}
	while ( !pSocket->waitForConnected() );

	emit sigConnected();
}


///////////////////////////////////////////////////////////////////////////////////////////////////


CConnection::CConnection( QObject* pParent )
			: QObject( pParent )
{
	m_pSocket = new zz::CSocket( this );
	m_pConnectionThread = new QThread();
	m_pConnector = new CConnector();
	m_pConnector->moveToThread( m_pConnectionThread );

	ZZ_ASSERT( QObject::connect( this, SIGNAL( sigTryToConnect( zz::CSocket*, QString const&, int ) ), 
		       m_pConnector, SLOT( tryToConnect( zz::CSocket*, QString const&, int ) ) ) );

	ZZ_ASSERT( QObject::connect( m_pConnector, SIGNAL( sigConnected() ), this, SLOT( connected() ) ) );
	//QObject::connect( m_pSocket, SIGNAL( connected() ), this, SIGNAL( sigConnected() ) );
	QObject::connect( m_pSocket, SIGNAL( sigNewRequest( zz::CRequest* ) ), this, SLOT( getResponse( zz::CRequest* ) ) );
}


CConnection::~CConnection()
{
	if ( m_pConnectionThread )
	{
		m_pConnectionThread->quit();
		ZZ_ASSERT( m_pConnectionThread->wait() );
		m_pConnectionThread->deleteLater();
	}
}


void CConnection::connected()
{
	if ( m_pConnectionThread )
	{
		m_pConnectionThread->quit();
		ZZ_ASSERT( m_pConnectionThread->wait() );
	}
	emit sigConnected();
}

CConnection* CConnection::ms_pInstance = nullptr;


CConnection* CConnection::getInstance()
{
	if ( ms_pInstance == nullptr )
	{
		ms_pInstance = new CConnection();
	}

	return ms_pInstance;
}


void CConnection::connect()
{
	QHostInfo oHostInfo = QHostInfo::fromName( "aramamv.ddns.net" );
	QList<QHostAddress> lstAddresses = oHostInfo.addresses();

	if ( lstAddresses.isEmpty() )
		return;

	QString sHost = lstAddresses.at( 0 ).toString();
	int nPort = 5476;
	m_pConnectionThread->start();
	emit sigTryToConnect( m_pSocket, sHost, nPort );
}


void CConnection::disconnect()
{
	if ( m_pSocket->waitForDisconnected() )
		m_pSocket->disconnectFromHost();

	QObject::disconnect( m_pSocket, SIGNAL( sigNewRequest( zz::CRequest* ) ), this, SLOT( getResponse( zz::CRequest* ) ) );
}


void CConnection::sendRequest( zz::CRequest* pRequest )
{
	if ( pRequest != nullptr && pRequest->isValid() && !pRequest->isEmpty() )
	{
		m_pSocket->sendRequest( pRequest );
	}
}


void CConnection::getResponse( zz::CRequest* pRequest )
{
	if ( pRequest == nullptr || !pRequest->isValid() || pRequest->isEmpty() )
	{
		return;
	}

	switch ( pRequest->getType() )
	{
	case zz::ERequestType::Login:
	{
//		emit login( );
		break;
	}
	case zz::ERequestType::ShowMessaging:
	{
		//emit showMessaging();
		break;
	}
	default:
		break;
	}
}


} // namespace zz_cl


// end of file