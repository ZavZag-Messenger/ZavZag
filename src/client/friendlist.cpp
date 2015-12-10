#include "friendlist.h"


namespace zz_cl
{


CFriendList::CFriendList(QWidget* pParent)
            : QListWidget(pParent),
			  nMaxWidth(0)
{
}


void CFriendList::addFriend( CFriendWidget* pFriend )
{
	m_lstFriends.append( pFriend );
	addItem( pFriend );

	if ( pFriend->sizeHint().width() > nMaxWidth )
	{
		nMaxWidth = pFriend->sizeHint().width();
		setFixedWidth( nMaxWidth );
	}

}


} // namespace zz_cl 