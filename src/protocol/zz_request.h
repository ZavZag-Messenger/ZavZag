/*
	File: 
		zz_request.h
	Abstract:
		Defines the all supported request classes
*/

#ifndef ZZ_REQUEST_H
#define ZZ_REQUEST_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
#ifndef ZZ_CORE_H
#	include "zz_core.h"
#endif

//	Qt includes

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace zz { //
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	class CRequest
//!	Base class for all request types
class CRequest
{
public:
	// Request data definition
	typedef QHash<QString, QVariant> t_RequestData;

public:
	//! Constructor for derived classes
	inline CRequest( ERequestType eType );
	//! Destructor
	virtual ~CRequest();

public:
	//
	//	Main Interface
	//
	// Returns request type
	inline ERequestType   getType() const;
	// Returns request status
	inline ERequestStatus getRequestStatus() const;
	// Checks request validation
	inline bool isValid() const;
	// Add data item
	inline void addItem( QString const& sKey, QVariant const& vtValue );
	// Remove data item
	inline void removeItem( QString const& sKey );
	// Get value of data item
	inline QVariant getValue( QString const& sKey ) const;
	// Get item Count
	inline int  getItemCount() const;
	// Is there any items 
	inline bool isEmpty();
	// Returns all item keys
	inline QStringList     getAllKeys() const;
	// Returns all item values
	inline QList<QVariant> getAllValues() const;

	// Returns data buffer which is ready to be transmitted
	virtual QByteArray  getBuffer() const;

private:
	//
	//	Content
	//
	ERequestType   m_eType;
	ERequestStatus m_eStatus;
	t_RequestData  m_hshData;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

//! Constructor
inline CRequest::CRequest( ERequestType eType )
	: m_eType(eType)
{}
// getType
inline ERequestType CRequest::getType() const { return m_eType; }
// isValid
inline bool CRequest::isValid() const { return m_eType != ERequestType::Undefined; }


////////////////////////////////////////////////////////////////////////////////
//
//	class CLoginRequest
//
class CLoginRequest : public CRequest
{
	// Base definition
	typedef CRequest Base;

public:
	//! Constructor for derived classes
	inline CLoginRequest( ERequestType eType );
	//! Destructor
	virtual ~CLoginRequest();

public:
	//
	//	Main Interface
	//
	// Get request type
	inline ERequestType getType() const;
	// Checks request validation
	inline bool         isValid() const;
	// Returns data buffer which is ready to be transmitted
	virtual QByteArray  getBuffer() const = 0;

private:
	//
	//	Content
	//
	ERequestType m_eType;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

#endif // ZZ_REQUEST_H
/* end of file */
