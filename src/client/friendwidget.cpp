#include "friendwidget.h"


namespace zz_cl
{


CFriendWidget::CFriendWidget( zz::CUserInfo* pUser, QListWidget *pParent )
		: QListWidgetItem( pUser->getFirstName() + " " + pUser->getLastName(), pParent ),
            m_pUser(pUser)
{
}



} // namespace zz_cl
