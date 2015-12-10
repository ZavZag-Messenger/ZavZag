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
				 "user_id    INTEGER PRIMARY KEY NOT NULL, "
				 "first_name TEXT    NOT NULL, "
				 "last_name  TEXT    NOT NULL, "
				 "birthday   DATE    NOT NULL, "
				 "gender     INTEGER NOT NULL, "
				 "avatar     BLOB);" );
	checkExecution( oQuery );

	// Create Auth Table
	oQuery.exec( "CREATE TABLE auth_info ("
				 "user_id  INTEGER PRIMARY KEY AUTOINCREMENT,"
				 "username TEXT    NOT NULL UNIQUE, "
				 "password INTEGER NOT NULL);"
				 );
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
	// Get And Check Validation
	QString sfName = info.getFirstName();
		ZZ_ASSERT( !sfName.isEmpty() );
	QString slName = info.getLastName();
		ZZ_ASSERT( !slName.isEmpty( ) );
	QDate oBrDay = info.getBirthday();
		ZZ_ASSERT( oBrDay.isValid() );
	QString sDate = oBrDay.toString( QString( "yyyy-MM-dd" ) );
		ZZ_ASSERT( !sDate.isEmpty() );
	zz::EGender eGender = info.getGender();
		ZZ_ASSERT( eGender != zz::EGender::Undefined );
	QString sUsername = info.getUsername();
		ZZ_ASSERT( !sUsername.isEmpty( ) );
	ZZ_ASSERT( unPwdHash != 0 ); // Should Be removes

	QSqlQuery oQuery;
	// Add username and password 
	oQuery.exec( QString( "INSERT INTO auth_info"
						  "(username, password) VALUES"
						  "(    '%1',     '%2');" )
		.arg( sUsername ).arg( unPwdHash ) );
	checkExecution( oQuery );
	
	// Get new user 
	uint unId = getUserId( sUsername );

	// Insert into user_info table 
	oQuery.exec( QString( "INSERT INTO user_info"
				          "(user_id, first_name, last_name, birthday, gender) VALUES"
						  "(   '%1',       '%2',      '%3',     '%4',     %5);" )
							 .arg(unId).arg( sfName ).arg( slName ).arg( sDate ).arg( int( eGender ) ) );
	checkExecution( oQuery );
	
	return 0;
}

// getUserId
uint srv::CDataManager::getUserId( QString const& sUsername )
{
	QSqlQuery oQuery;
	oQuery.prepare( "SELECT user_id FROM auth_info WHERE username = ?" );
	oQuery.bindValue( 0, sUsername );
	oQuery.exec( );
	checkExecution( oQuery );
	//
	if (!oQuery.first( ))
		throw zz::CException( zz::qtr( "Unexpacted Result: Username %1 not found" ).arg( sUsername ) );

	QString sRowCount = oQuery.value( 0 ).toString( );
	bool bOk = false;
	uint unId = sRowCount.toInt( &bOk );
	if (!bOk)
		throw zz::CException( zz::qtr( "Something goes wrong: Unable To get Row Count." ) );
	return unId;
}

// getUserId
uint srv::CDataManager::getUserId( QString const& sUsername,
								   uint           unPwdHash )
{
	QSqlQuery oQuery;
	oQuery.prepare( "SELECT user_id FROM auth_info WHERE username = ? AND password = ?" );
	oQuery.bindValue( 0, sUsername );
	oQuery.bindValue( 0, unPwdHash );
	oQuery.exec( );
	checkExecution( oQuery );
	//
	if (!oQuery.first( ))
		throw zz::CException( zz::qtr( "Unexpacted Result: Username %1 not found" ).arg( sUsername ) );

	QString sRowCount = oQuery.value( 0 ).toString( );
	bool bOk = false;
	uint unId = sRowCount.toInt( &bOk );
	if (!bOk)
		throw zz::CException( zz::qtr( "Something goes wrong: Unable To get Row Count." ) );
	return unId;
}

// getUserInfo
zz::CUserInfo srv::CDataManager::getUserInfo( uint unId )
{
	QSqlQuery oQuery;
	oQuery.prepare( "SELECT * FROM user_info WHERE user_id = ?" );
	oQuery.bindValue( 0, unId );
	oQuery.exec( );
	checkExecution( oQuery );
	//
	if (!oQuery.first())
		return zz::CUserInfo();
	// Take user info from records
	uint    unUserId   = oQuery.value( 0 ).toUInt();
	// Double check
	ZZ_ASSERT( unUserId == unId );
	QString sFirstName  = oQuery.value( 1 ).toString();
	QString sLastName   = oQuery.value( 2 ).toString();
	QDate   oBrDay      = oQuery.value( 3 ).toDate();
	zz::EGender eGender = zz::EGender( oQuery.value( 4 ).toInt() );
	QImage  imgAvatar  = oQuery.value( 5 ).value<QImage>();
	zz::CUserList lstFriends = getFriendList( unUserId );

	// Complete the user info object
	zz::CUserInfo oInfo;
	oInfo.setUserID( unUserId );
	oInfo.setFirstName( sFirstName );
	oInfo.setLastName( sLastName );
	oInfo.setBirthday( oBrDay );
	oInfo.setGender( eGender );
	oInfo.setAvatar( imgAvatar );
	oInfo.setFriendList( lstFriends );

	return oInfo;
}

// getUserInfo
zz::CUserList srv::CDataManager::getFriendList( uint unId )
{
	QSqlQuery oQuery;
	oQuery.prepare( "SELECT friend_id FROM friendship WHERE user_id = ?" );
	oQuery.bindValue( 0, unId );
	oQuery.exec( );
	checkExecution( oQuery );
	// Get friend id list
	QList<uint> lstFriendIDs;
	while (oQuery.next())
	{
		bool bOk = false;
		uint unFriendID = oQuery.value( 0 ).toUInt( &bOk );
		if (bOk)
			lstFriendIDs.append( unFriendID );
	}

	zz::CUserList lstFriends;
	for (int i = 0; i < lstFriendIDs.size(); ++i)
	{
		uint unFriendID = lstFriendIDs[i];
		oQuery.prepare( "SELECT user_id, first_name, last_name, avatar FROM user_info WHERE user_id = ?" );
		oQuery.bindValue( 0, unFriendID );
		oQuery.exec();
		checkExecution( oQuery );
		//
		uint    unUserId = oQuery.value( 0 ).toUInt();
		// Double check
		ZZ_ASSERT( unUserId == unFriendID );
		QString sFirstName = oQuery.value( 1 ).toString( );
		QString sLastName = oQuery.value( 2 ).toString( );
		QImage  imgAvatar = oQuery.value( 3 ).value<QImage>( );
		//
		zz::CUserListItem oItem( unUserId, sFirstName, sLastName, imgAvatar );
		lstFriends.append( oItem );
	}

	return lstFriends;
}



/*end of file*/
