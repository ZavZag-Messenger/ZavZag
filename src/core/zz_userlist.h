/*
File:
	zz_userlist.h

Abstract:
	Defines Friend List and Friend List Item classes 
*/

#ifndef ZZ_USER_LIST_H
#define ZZ_USER_LIST_H

////////////////////////////////////////////////////////////////////////////////
//
//	Includes
//

// Qt Includes
#include <QString>
#include <QImage>
#include <QList>
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace zz { //
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	class CUserListItem
//
class CUserListItem
{
public:
	//!	Default Constructor
	inline CUserListItem();
	//!	Constructor
	inline CUserListItem( uint unId,
							QString const& sfName,
							QString const& slName,
							QImage  const& imgAvatar = QImage() 
							);

public:
	//
	//	Accessors
	//
	inline uint    getId()        const;
	inline QString getFirstName() const;
	inline QString getLastName()  const;
	inline QImage  getAvatar()    const;

private:
	//
	//	Content
	//
	uint    m_unId;
	QString m_sfName;
	QString m_slName;
	QImage  m_imgAvatar;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	class CUserList
//
typedef QList<CUserListItem> CUserList;
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

//!	Default Constructor
inline CUserListItem::CUserListItem()
	: m_unId( 0 )
{}

//!	Constructor
inline CUserListItem::CUserListItem( uint unId,
							QString const& sfName,
							QString const& slName,
							QImage  const& imgAvatar
							)
							: m_unId(unId),
							  m_sfName(sfName),
							  m_slName(slName),
							  m_imgAvatar( imgAvatar )
{}

// Accessors
inline uint    CUserListItem::getId()        const { return m_unId; }
inline QString CUserListItem::getFirstName() const { return m_sfName; }
inline QString CUserListItem::getLastName()  const { return m_slName; }
inline QImage  CUserListItem::getAvatar()    const { return m_imgAvatar; }

////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

//	Meta Type Declaration
Q_DECLARE_METATYPE( zz::CUserListItem );
Q_DECLARE_METATYPE( zz::CUserList );

#endif // ZZ_USER_LIST_H
