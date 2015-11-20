#include "user.h"

CUser::CUser()
        : m_sFirstName("FirstName"),
          m_sLastName("LastName"),
          m_bIsOnline(false)
{
}


CUser::CUser(const QString & sFirstName, const QString & sLastName, bool bOnline)
        : m_sFirstName(sFirstName),
          m_sLastName(sLastName),
          m_bIsOnline(false)
{
}


CUser::~CUser()
{
    FriendList::iterator it = m_lstFriends.begin();
    while (it != m_lstFriends.end())
    {
        delete (*it);
        ++it;
    }
}


void CUser::setFirstName(const QString & sFirstName)
{
    m_sFirstName = sFirstName;
}


void CUser::setLastName(const QString & sLastName)
{
    m_sLastName = sLastName;
}


void CUser::setOnline(bool bOnline)
{
   m_bIsOnline = bOnline;
}


void CUser::addFriend(CUser *pFreindUser)
{
    m_lstFriends.append(pFreindUser);
}


void CUser::eraseFriend(CUser *pFriendUser)
{
    FriendList::iterator it = std::find(m_lstFriends.begin(), m_lstFriends.end(), pFriendUser);
    if (it != m_lstFriends.end())
    {
        m_lstFriends.erase(it);
    }
}


QString CUser::getFirstName() const
{
    return m_sFirstName;
}


QString CUser::getLastName() const
{
    return m_sLastName;
}


bool CUser::isOnline() const
{
    return m_bIsOnline;
}


const CUser::FriendList& CUser::friendList() const
{
    return m_lstFriends;
}
