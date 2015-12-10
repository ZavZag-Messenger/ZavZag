#include "mainpage.h"
#include <QHBoxLayout>


namespace zz_cl
{


	CMainPage::CMainPage( zz::CUserInfo* pUser, QWidget* pParent )
            : QWidget( pParent ),
              m_pUser( pUser )
{
	QHBoxLayout* pLayout = new QHBoxLayout( this );
	setLayout( pLayout );

	makeMessageBox( pLayout );
	makeFriendList( pLayout );

	QObject::connect( m_pFriendList, SIGNAL( itemChanged( QListWidgetItem* ) ), m_pFriendList, SLOT() );
}


void CMainPage::makeFriendList(QLayout* pLayout)
{
	m_pFriendList = new CFriendList( this );
	QBoxLayout* bl = qobject_cast< QBoxLayout* >( pLayout );
	bl->addWidget( m_pFriendList);
	m_pFriendList->setSizePolicy( QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding );

	/*CUser::FriendList::const_iterator cIt = m_pUser->friendList().constBegin();
	while ( cIt != m_pUser->friendList().constEnd() )
    {
        CFriendWidget *pFriendWidget = new CFriendWidget(*cIt, m_pFriendList);
		m_pFriendList->addFriend( pFriendWidget );
        ++cIt;
    }*/
}

void CMainPage::makeMessageBox(QLayout* pLayout)
{
	m_pMessageBox = new CMessageBox( this );
	QBoxLayout* bl = qobject_cast< QBoxLayout* >( pLayout );
	bl->addWidget( m_pMessageBox ,1);
}


} // namespace zz_cl