#ifndef CFRIENDITEM_H
#define CFRIENDITEM_H
//////////////////////////////////////////////////////////////////////////
//
//	includes
//
#include <QListWidgetItem>
#include "zz_utility.h"
//////////////////////////////////////////////////////////////////////////


namespace zz_cl
{


//
//	This class is user's friends item widget
//
class CFriendWidget : public QListWidgetItem
{
public:
	//
	//	constructor
	//
	CFriendWidget( zz::CUserInfo* pUser, QListWidget* pParent = nullptr );

private:
	//
	//	members
	//
	zz::CUserInfo* m_pUser;

};


} // namespace zz_cl


#endif // CFRIENDITEM_H
// end of file