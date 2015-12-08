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
//////////////////////////////////////////////////////////////////////////////////
//namespace keys {// Keys for the values of request
//////////////////////////////////////////////////////////////////////////////////
//
//	const QLatin1String sUsername = QLatin1String("__username");
//	const QLatin1String sPassword = QLatin1String("__password");
//	const QLatin1String sFirstName = QLatin1String("__first_name");
//	const QLatin1String sLastName = QLatin1String("__last_name");
//	const QLatin1String sBirthday = QLatin1String("__birthday");
//	const QLatin1String sGender = QLatin1String("__gender");
//	const QLatin1String sErrorMessage = QLatin1String("__error_message");
//	const QLatin1String sAvatar = QLatin1String("__avatar");
//	const QLatin1String sFriendList = QLatin1String("__friend_list");
//////////////////////////////////////////////////////////////////////////////////
//} // namespace keys
//////////////////////////////////////////////////////////////////////////////////

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
