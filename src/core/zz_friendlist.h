/*
File:
	zz_friendlist.h

Abstract:
	Defines Friend List and Friend List Item classes 
*/

#ifndef ZZ_FRIEND_LIST_H
#define ZZ_FRIEND_LIST_H

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
//	class CFriendListItem
//
class CFriendListItem
{
public:
	//!	Default Constructor
	inline CFriendListItem();
	//!	Constructor
	inline CFriendListItem( uint unId,
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
//	class CFriendList
//
typedef QList<CFriendListItem> CFriendList;
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//	Inline Implementations
//
////////////////////////////////////////////////////////////////////////////////

//!	Default Constructor
inline CFriendListItem::CFriendListItem()
	: m_unId( 0 )
{}

//!	Constructor
inline CFriendListItem::CFriendListItem( uint unId,
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
inline uint    CFriendListItem::getId()        const { return m_unId; }
inline QString CFriendListItem::getFirstName() const { return m_sfName; }
inline QString CFriendListItem::getLastName()  const { return m_slName; }
inline QImage  CFriendListItem::getAvatar()    const { return m_imgAvatar; }

////////////////////////////////////////////////////////////////////////////////
} // namespace zz
////////////////////////////////////////////////////////////////////////////////

//	Meta Type Declaration
Q_DECLARE_METATYPE( zz::CFriendListItem );
Q_DECLARE_METATYPE( zz::CFriendList );

#endif // ZZ_FRIEND_LIST_H
