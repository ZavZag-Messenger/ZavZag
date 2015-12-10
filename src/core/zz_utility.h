/*
File:
	zz_utility.h
Abstract:
	Defines usefull utility classes which are used by the server and client
*/

#ifndef ZZ_UTILITY_H
#define ZZ_UTILITY_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef ZZ_CORE_H
#	include "zz_core.h"
#endif

#ifndef ZZ_USER_LIST_H
#	include "zz_userlist.h"
#endif

// Qt includes

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace zz { //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	class CUserInfo
//!	TCP socket class which allows request transmission
class ZZ_CORE_EXPORT CUserInfo
{
public:
	//!	Constructor
	inline CUserInfo();
	inline CUserInfo( t_RequestData const& hshData );
	//! Destructor
	inline ~CUserInfo();

public:
	//
	//	Accessors
	//
	// Get/Set Username
	inline void setUsername( QString const& sUsername );
	inline QString getUsername() const;

	// Get/Set Password
	inline void setPassword( QString const& sPwd );
	inline QString getPassword() const;

	// Get/Set User ID
	inline void setUserID( uint unId );
	inline uint getUserID() const;

	// Get/Set First Name
	inline void setFirstName( QString const& sfName );
	inline QString getFirstName() const;

	// Get/Set Last Name
	inline void setLastName( QString const& slName );
	inline QString getLastName( ) const;

	// Get/Set Birthday
	inline void setBirthday( QDate const& dtBrDay );
	inline QDate getBirthday( ) const;

	// Get/Set Gender
	inline void setGender( EGender eGender );
	inline EGender getGender() const;

	// Get/Set Avatar
	inline void setAvatar( QImage const& imgAvatar );
	inline QImage getAvatar() const;

	// Get/Set Friend List
	inline void setFriendList( CUserList const& lstFriends );
	inline CUserList getFriendList() const;

public:
	// Converts User Info to Request Data type 
	inline t_RequestData toRequestData() const;
	// Is Empty
	inline bool isEmpty() const;

private:
	//
	//  Content
	//
	t_RequestData m_hshData;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////
//! Default Constructor
inline CUserInfo::CUserInfo()
{}
//!
inline CUserInfo::CUserInfo( t_RequestData const& hshData )
	: m_hshData( hshData )
{}
//! Destructor
inline CUserInfo::~CUserInfo()
{}

// toRequestData
inline t_RequestData CUserInfo::toRequestData() const { return m_hshData; }

// setUsername
inline void CUserInfo::setUsername( QString const& sUsername )
{
	if (sUsername.isEmpty())
		return;
	m_hshData.insert( keys::sUsername, QVariant( sUsername ) );
}

// getUsername
inline QString CUserInfo::getUsername() const
{
	return m_hshData.value( keys::sUsername ).toString();
}

// setPassword
inline void CUserInfo::setPassword( QString const& sPwd )
{
	if (sPwd.isEmpty())
		return;
	m_hshData.insert( keys::sPassword, QVariant( sPwd ) );
}

// getPassword
inline QString CUserInfo::getPassword() const
{
	return m_hshData.value( keys::sPassword ).toString();
}

// setUserID
inline void CUserInfo::setUserID( uint unId )
{
	if (unId == 0)
		return;
	m_hshData.insert( keys::sUserId, QVariant( unId ) );
}

// getUserID
inline uint CUserInfo::getUserID() const
{
	return m_hshData.value( keys::sUserId ).toUInt( );
}


// setFirstName
inline void CUserInfo::setFirstName( QString const& sfName )
{
	if (sfName.isEmpty())
		return;
	m_hshData.insert( keys::sFirstName, QVariant( sfName ) );
}

// getFirstName
inline QString CUserInfo::getFirstName() const
{
	return m_hshData.value( keys::sFirstName ).toString();
}

// setLastName
inline void CUserInfo::setLastName( QString const& slName )
{
	if (slName.isEmpty())
		return;
	m_hshData.insert( keys::sLastName, QVariant( slName ) );
}

// getLastName
inline QString CUserInfo::getLastName() const
{
	return m_hshData.value( keys::sLastName ).toString();
}

// setBirthday
inline void CUserInfo::setBirthday( QDate const& dtBrDay )
{
	if (!dtBrDay.isValid())
		return;
	m_hshData.insert( keys::sBirthday, QVariant( dtBrDay ) );
}

// getBirthday
inline QDate CUserInfo::getBirthday() const
{
	return m_hshData.value( keys::sBirthday ).toDate();
}

// setGender
inline void CUserInfo::setGender( EGender eGender )
{
	if (eGender == EGender::Undefined)
		return;
	m_hshData.insert( keys::sGender, QVariant( int( eGender ) ) );
}

// getGender
inline EGender CUserInfo::getGender() const
{
	int nGender = m_hshData.value( keys::sGender ).toInt();
	return EGender( nGender );
}

// setAvatar
inline void CUserInfo::setAvatar( QImage const& imgAvatar )
{
	if (imgAvatar.isNull())
		return;
	m_hshData.insert( keys::sAvatar, QVariant( imgAvatar ) );
}

// getAvatar
inline QImage CUserInfo::getAvatar() const
{
	QVariant vtImage = m_hshData.value( keys::sAvatar );
	return vtImage.value<QImage>();
}

// setFriendList
inline void CUserInfo::setFriendList( CUserList const& lstFriends )
{
	if (lstFriends.isEmpty())
		return;
	QVariant vtFriendList;
	vtFriendList.setValue<CUserList>( lstFriends );
	m_hshData.insert( keys::sFriendList, vtFriendList );
}

// getFriendList
inline CUserList CUserInfo::getFriendList() const
{
	QVariant vtImage = m_hshData.value( keys::sFriendList );
	return vtImage.value<CUserList>();
}

// isEmpty
inline bool  CUserInfo::isEmpty() const { return m_hshData.isEmpty(); }

////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

#endif // ZZ_UTILITY_H
/* end of file */
