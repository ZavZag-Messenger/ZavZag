#include "mainpage.h"

#include <QHBoxLayout>


CMainPage::CMainPage(CUser *pUser, QWidget *pParent)
            : QWidget(pParent),
              m_pUser(pUser)
{
    QHBoxLayout *pLayout = new QHBoxLayout(this);
    setLayout(pLayout);

    makeMessageBox(pLayout);
    makeFriendList(pLayout);
}


void CMainPage::makeFriendList(QLayout *pLayout)
{
    m_pFriendList = new CFriendList(this);
    pLayout->addWidget(m_pFriendList);

    CUser::FriendList::const_iterator cIt = m_pUser->friendList().cbegin();
    while (cIt != m_pUser->friendList().cend())
    {
        CFriendItem *pFriendItem = new CFriendItem(*cIt, m_pFriendList);
        m_pFriendList->addItem(pFriendItem);

        ++cIt;
    }
}

void CMainPage::makeMessageBox(QLayout *pLayout)
{
    m_pMessageBox = new CMessageBox(this);
    pLayout->addWidget(m_pMessageBox);
}

