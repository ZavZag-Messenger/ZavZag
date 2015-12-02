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
////////////////////////////////////////////////////////////////////////////////
namespace keys {// Keys for the values of request
////////////////////////////////////////////////////////////////////////////////

static const char* cszUsername     = "__username";
static const char* cszPassword     = "__password";
static const char* cszFirstName    = "__first_name";
static const char* cszLastName     = "__last_name";
static const char* cszBirthday     = "__birthday";
static const char* cszGender       = "__gender";
static const char* cszErrorMessage = "__error_message";
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
