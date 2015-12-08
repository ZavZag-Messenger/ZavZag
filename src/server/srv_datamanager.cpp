/*
File:
    srv_datamanager.cpp
Abstract:
	Implementation file for Data Manager 
*/

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#include "srv_datamanager.h"
//	Qt includes
#include <QDir>
////////////////////////////////////////////////////////////////////////////////

//
//  Static Member Initialization
//
const QLatin1String srv::CDataManager::m_csDataFilePath = QLatin1String( "data/" );
const QLatin1String srv::CDataManager::m_csDataFileName = QLatin1String( "data.sqlite" );

//
//  class CDataManager
//

// initialize
void srv::CDataManager::initialize()
{
	bool bCreateTables = false;
	// Chack data file existance
	QDir oDataFileDir;
	QString sFilePath = m_csDataFilePath + m_csDataFileName;
	if (!oDataFileDir.exists( sFilePath ))
	{
		if(!oDataFileDir.mkpath( m_csDataFilePath ))
			throw zz::CException( zz::qtr( "Unable to create path" ));
		bCreateTables = true;
	}

	// Create SQlite connection
	m_oDB = QSqlDatabase::addDatabase( "QSQLITE" );
	m_oDB.setDatabaseName( sFilePath );
	if (!m_oDB.open())
	{
		QString sErrMsg = m_oDB.lastError().driverText();
		throw zz::CException( zz::qtr( "Unable to establish database connection: " )
			.append( sErrMsg ) );
	}
	
	// Create DB Infrastructure if necessary
	if (bCreateTables)
		createDBInfrastructure();
}

//	createDBInfrastructure
void srv::CDataManager::createDBInfrastructure()
{
	QSqlQuery oQuery;
	// Create Table user_info
	oQuery.exec( "CREATE TABLE user_info ("
				 "user_id    INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "first_name TEXT    NOT NULL, "
				 "last_name  TEXT    NOT NULL, "
				 "birthday   DATE    NOT NULL, "
				 "gender     INTEGER NOT NULL, "
				 "avatar     BLOB);" );
	checkExecution( oQuery );

	// Create Auth Table
	oQuery.exec( "CREATE TABLE auth_info ("
				 "auth_id  INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "username TEXT    NOT NULL UNIQUE, "
				 "password INTEGER NOT NULL, "
				 "user_id  INTEGER NOT NULL UNIQUE);" );
	checkExecution( oQuery );

	// Create Friendship Table
	oQuery.exec( "CREATE TABLE friendship ("
				 "friendship_id INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "user_id       INTEGER NOT NULL, "
				 "friend_id     INTEGER NOT NULL);" );
	checkExecution( oQuery );

	// Create Conversation Table
	oQuery.exec( "CREATE TABLE conversation ("
				 "conv_id    INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "table_name TEXT NOT NULL);" );
	checkExecution( oQuery );

	// Create Conversation Info Table
	oQuery.exec( "CREATE TABLE conversation_info ("
				 "user_id INTEGER NOT NULL, "
				 "conv_id INTEGER NOT NULL);" );
	checkExecution( oQuery );

	// Create Messages Table
	oQuery.exec( "CREATE TABLE messages ("
				 "conv_id   INTEGER  NOT NULL, "
				 "user_id   INTEGER  NOT NULL, "
				 "message   TEXT     NOT NULL, "
				 "send_time DATETIME );" );
	checkExecution( oQuery );
}



//	registerUser
uint srv::CDataManager::registerUser( zz::CUserInfo const& info, uint unPwdHash )
{
	QString sfName = info.getFirstName();
	ZZ_ASSERT( !sfName.isEmpty() );
	QString slName = info.getLastName();
	ZZ_ASSERT( !slName.isEmpty( ) );
	QDate oBrDay = info.getBirthday();
	ZZ_ASSERT( oBrDay.isValid() );
	QString sDate = oBrDay.toString( QString( "yyyy-MM-dd" ) );
	zz::EGender eGender = info.getGender();
	ZZ_ASSERT( eGender != zz::EGender::Undefined );

	QSqlQuery oQuery;
	oQuery.exec( QString( "INSERT INTO user_info"
				             "(first_name, last_name, birthday, gender) VALUES"
							 "(      '%1',      '%2',     '%3',     %4);" )
							 .arg( sfName ).arg( slName ).arg( sDate ).arg( int( eGender ) ) );
	checkExecution( oQuery );
	return 0;
}