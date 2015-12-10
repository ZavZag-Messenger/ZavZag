#ifndef CCONNECTION_H
#define CCONNECTION_H

#include <QObject>
#include <QThread>
#include "user.h"
#include "message.h"
#include "zz_socket.h"


namespace zz_cl
{


class CConnector : public QObject
{
	Q_OBJECT
public:
	CConnector( QObject* pParent = nullptr );

public slots:
	void tryToConnect( zz::CSocket* pSocket, QString const&, int nPort );

signals:
	void sigConnected();

};


class CConnection : public QObject
{
	Q_OBJECT

private:
	CConnection( QObject* pParent = nullptr );

public:
	~CConnection();


public:
	static CConnection* getInstance();

public:
	//
	//
	//
	void connect();
	//
	//
	//
	void disconnect();

signals:
	//
	//
	//
	void sigConnected();
	void sigTryToConnect( zz::CSocket*, QString const&, int );

public slots:
	//
	//
	//
	void sendRequest( zz::CRequest* pRequest );
	void connected();

private slots:
	//
	void getResponse( zz::CRequest* pRequest );

signals:
	void login( CUser* );
	void registered();
	void showMessaging( QList<CMessage*> );
	void newMessage( QString );

private:
	static CConnection* ms_pInstance;

private:
	//
	//
	//
	zz::CSocket* m_pSocket;
	CConnector*  m_pConnector;
	QThread*     m_pConnectionThread;

};


} // namespace zz_cl


#endif // CCONNECTION_H
// end of file