/*
	File: 
		zz_request.cpp
	Abstract:
		Implementation file for all request types
*/

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#include "zz_request.h"
#include "zz_utility.h"
////////////////////////////////////////////////////////////////////////////////

/*
+====================+=================+
|     H E A D E R    |     B O D Y     |
+====================+=================+
|   Type    | Size: N| Variant Hash... |
|   1 Byte  | 4 Byte |     N Byte      |
+======================================+
*/

//
//  Initialization of request keys 
//
////////////////////////////////////////////////////////////////////////////////
namespace keys {// Keys for the values of request
////////////////////////////////////////////////////////////////////////////////

static const QString sUsername     = "__username";
static const QString sPassword     = "__password";
static const QString sFirstName    = "__first_name";
static const QString sLastName     = "__last_name";
static const QString sBirthday     = "__birthday";
static const QString sGender       = "__gender";
static const QString sErrorMessage = "__error_message";
static const QString sAvatar       = "__avatar";
static const QString sFriendList   = "__friend_list";
////////////////////////////////////////////////////////////////////////////////
} // namespace keys
////////////////////////////////////////////////////////////////////////////////

//
//	class CRequest
//
//! Destructor
zz::CRequest::~CRequest()
{}

// CRequestserialize
QByteArray zz::CRequest::serialize() const
{
	QByteArray aBuffer;
	QDataStream oOut(&aBuffer, QIODevice::WriteOnly);
	quint8  unType = static_cast<int>(m_eType);
	quint32 unSize = m_hshData.size();
	// Serializing
	oOut << unType << unType << m_hshData;
	return aBuffer;
}

/*end of file*/
