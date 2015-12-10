#ifndef CFRIENDLIST_H
#define CFRIENDLIST_H

//////////////////////////////////////////////////////
//	includes
//
#include <QWidgetList>
#include <QList>
#include "friendwidget.h"
//
//////////////////////////////////////////////////////


namespace zz_cl
{


//
//	This class is user's friends items list widget
//
class CFriendList : public QListWidget
{
public:
	//
	//	constructor
	//
    CFriendList(QWidget* pParent = nullptr);

public:
	//
	//	add friand widget
	//
	void addFriend( CFriendWidget* pFriend );

private:
	//
	//	members
	//
	int nMaxWidth;
	QList<CFriendWidget*> m_lstFriends;

};


} // namespace zz_cl


#endif // CFRIENDLIST_H
// end of file