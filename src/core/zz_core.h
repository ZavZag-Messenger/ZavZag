/******************************************************************************/ 
/*  This is the open source project which has GNU GNU GENERAL PUBLIC LICENSE  */
/*	        The developers are Aram Hakhverdyan and Levon Gasparyan.          */
/******************************************************************************/

/*
	File: 
		zz_core.h
	Abstract:
		Defines the main protocol concepst to work with the low-level layer
*/

#ifndef ZZ_CORE_H
#define ZZ_CORE_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
//
//  STD includes
//
#include <stdexcept>
#include <new>

//
//	Qt includes
//
#include <QObject>
#include <QMetaType>
#include <QPair>
#include <QString>
#include <QList>
#include <QMap>
#include <QVector>
#include <QSet>
#include <QHash>
#include <QStack>
#include <QQueue>
#include <QByteArray>
#include <QBitArray>
#include <QLinkedList>
#include <QStringList>
#include <QVariant>
#include <QDateTime>
#include <QDataStream>
#include <QTextStream>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QCoreApplication>
#include <QtCore/qglobal.h>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Macros Helpers
//
#if defined (QT_DEBUG)
#	define ZZ_ASSERT(_test_) Q_ASSERT(_test_)
#   define ZZ_ASSERT_EX( _test_, _what_ ) Q_ASSERT_X( _test_, '\0', _what_ )
#elif defined (QT_NO_DEBUG)
#	define ZZ_ASSERT(_test_)             ((void)(0))
#	define ZZ_ASSERT_X( _test_, _what_ ) ((void)(0))
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Library Export
//
#if defined ZZ_CORE_EXPORT
#	undef ZZ_CORE_EXPORT
#endif
#ifdef CORE_LIB
#	define ZZ_CORE_EXPORT Q_DECL_EXPORT
#else
#	define ZZ_CORE_EXPORT Q_DECL_IMPORT
#endif
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace zz { // [Z]av[Z]ag :P
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
// QTR function declaration for internationalization
//
inline QString qtr( char const* cszText )
{
	return QCoreApplication::translate( "zz_core", cszText );
}
inline QString qtr( QLatin1String const& cszText )
{
	return qtr( cszText.latin1() );
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Global Port Definitions
//
static const int g_nPort = 5476;
////////////////////////////////////////////////////////////////////////////////

//
//	Request Types
//
enum class ERequestType
{
	Undefined = 0,
	Register,
	Login,
	Logout,
	Lookup,
	Friend,
	ShowMessaging,
	SettingsChanged,
	SendMessage,
	Unregister,
	// Failure
	RequestFailed
};

//
//	Request Keys
//
//enum class ERequestKeys
//{
//	// User Info
//	FirstName = 0, // QString
//	LastName,      // QString
//	Username,      // QString
//	Password,      // QString
//	Birthday,      // QDateTime
//	Gender,        // Bool : true-Male | false-Female
//	Avatar,        // QImage
//
//	ErrorMessage   // Error Message
//};

//
//  Key type definition
//
typedef QString t_KeyType;
<<<<<<< HEAD

//
//	Request Data Type Definition
//	
typedef QHash<t_KeyType, QVariant> t_RequestData;


////////////////////////////////////////////////////////////////////////////////
namespace keys {// Keys for the values of request
	////////////////////////////////////////////////////////////////////////////////

	const QString sUsername = QLatin1String( "__username" );
	const QString sPassword = QLatin1String( "__password" );
	const QString sFirstName = QLatin1String( "__first_name" );
	const QString sLastName = QLatin1String( "__last_name" );
	const QString sBirthday = QLatin1String( "__birthday" );
	const QString sGender = QLatin1String( "__gender" );
	const QString sErrorMessage = QLatin1String( "__error_message" );
	const QString sAvatar = QLatin1String( "__avatar" );
	const QString sFriendList = QLatin1String( "__friend_list" );
=======

//
//	Request Data Type Definition
//	
typedef QHash<t_KeyType, QVariant> t_RequestData;


////////////////////////////////////////////////////////////////////////////////
namespace keys {// Keys for the values of request
	////////////////////////////////////////////////////////////////////////////////
	const QString sUserId       = QString( "__user_id" );
	const QString sUsername     = QString( "__username" );
	const QString sPassword     = QString( "__password" );
	const QString sFirstName    = QString( "__first_name" );
	const QString sLastName     = QString( "__last_name" );
	const QString sBirthday     = QString( "__birthday" );
	const QString sGender       = QString( "__gender" );
	const QString sErrorMessage = QString( "__error_message" );
	const QString sAvatar       = QString( "__avatar" );
	const QString sFriendList   = QString( "__friend_list" );
>>>>>>> a9b9cf482393a54bd1646a16847fc44046a69361
	////////////////////////////////////////////////////////////////////////////////
} // namespace keys
////////////////////////////////////////////////////////////////////////////////


//
//	Request Status
//
enum class ERequestStatus
{
	Unknown = 0,
	Succeeded,
	Failed,
	Canceled
};

//
//	Gender Definition
//
enum class EGender
{
	Undefined = 0,
	Male,
	Female
};

////////////////////////////////////////////////////////////////////////////////
//
//	Useful Tool Functions
//
////////////////////////////////////////////////////////////////////////////////
inline bool isValidRequestType( ERequestType eType )
{
	switch ( eType )
	{
	case ERequestType::Register:
	case ERequestType::Login:
	case ERequestType::Logout:
	case ERequestType::Lookup:
	case ERequestType::Friend:
	case ERequestType::ShowMessaging:
	case ERequestType::SettingsChanged:
	case ERequestType::SendMessage:
	case ERequestType::Unregister:
	case ERequestType::RequestFailed:
		return true;
	default: 
		return false;
	}
}


////////////////////////////////////////////////////////////////////////////////
//
//	class CException
//  
//! Common exception class
class CException : public std::exception
{
public:
	inline CException( QString const& sErr = qtr( m_cszDefaultMsg ) )	throw();
	//! copy constructor
	inline CException( CException const& rhs ) throw();
	//! destructor
	virtual ~CException() {};

public:
	// 
	//	std::exception Interface
	//
	inline CException& operator=(CException const& rhs) throw();
	// what
	const char* what() const throw() override;

private:
	// Error Message
	QByteArray m_aErrMsg;
	// default message
	static const QLatin1String m_cszDefaultMsg;
};

////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////

//
//	class CException
//
// Default constructor
inline CException::CException( QString const& sErr )	throw()
	: m_aErrMsg( sErr.toUtf8() )
{}

//! Copy constructor
inline CException::CException( CException const& rhs ) throw()
	: m_aErrMsg( rhs.m_aErrMsg )
{}

// operator=
inline CException& CException::operator=(CException const& rhs) throw()
{
	m_aErrMsg = rhs.m_aErrMsg;
	return *this;
}

// what
inline const char* CException::what() const throw()
{
	return m_aErrMsg.constData();
}

////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

#endif // ZZ_CORE_H
/* end of file */
