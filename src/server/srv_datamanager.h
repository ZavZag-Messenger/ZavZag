/*
File:
   srv_datamanager.h
Abstract:
   Defines the data manager class which is direcly works with the DB 
   and provides an interface to perform some predefined operations
*/

#ifndef SRV_DATA_MANAGER_H
#define SRV_DATA_MANAGER_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef ZZ_CORE_H
#   include "zz_core.h"
#endif

#ifndef ZZ_UTILITY_H
#	include "zz_utility.h"
#endif

//	Qt includes
#include <QSqlDataBase>
#include <QSqlQuery>
#include <QSqlQuery>
#include <QSqlError>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace srv { // Server
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	class CDataManager
//!	Wraps DB abilities and provides suitable interface for the server
class CDataManager
{
public:
	// Request data definition
	//typedef

public:
	//! Default Constructor
	inline CDataManager();
	//! Destructor
	inline ~CDataManager();

public:
	//
	//	Main Interface
	//
	// Registers a new user
	// In case of success returns id of the new user, 
	// otherwise throws an exception 
	uint registerUser( zz::CUserInfo, uint unPwdHash );
	// Checks whether the username is free
	bool isUsernameFree( QString const& sUsername ) const;
	// Login
	zz::CUserInfo login( QString const& sUsername,
				         uint           unPwdHash );



protected:
	//
	//  Tools Methods
	//
	// Creates DB connection and makes all necesary tables if not exist
	void initialize();
	void createDBInfrastructure();

	// If execution fails throws an exception with error message
	inline void checkExecution( QSqlQuery const& query );

private:
	//
	//	Content
	//
	QSqlDatabase m_oDB;

	// 
	static const QLatin1String m_csDataFileName;
	static const QLatin1String m_csDataFilePath;

};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

//! Constructor
inline CDataManager::CDataManager()
{
	initialize();
}

//! Destructor
inline CDataManager::~CDataManager()
{}

// checkExecution
inline void CDataManager::checkExecution( QSqlQuery const& query )
{
	if (!query.isActive())
	{
		QString sErrMsg = query.lastError().databaseText();
		throw zz::CException( zz::qtr( "DB Query Failed: " ).append( sErrMsg ) );
	}
}

////////////////////////////////////////////////////////////////////////////////
} // namespace srv
////////////////////////////////////////////////////////////////////////////////

#endif // SRV_DATA_MANAGER_H
/* end of file */
