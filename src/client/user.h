#ifndef CUSER_H
#define CUSER_H

#include <QObject>
#include <QList>
#include <QString>

class CUser
{
public:
    typedef QList<CUser*> FriendList;

public:
    explicit CUser();
    explicit CUser(const QString & sFirstName, const QString & sLastName, bool bOnline);
    ~CUser();

public:
    void setFirstName(const QString & sFirstName);
    void setLastName(const QString & sLastName);
    void setOnline(bool bOnline);
    void addFriend(CUser *pFreindUser);
    void eraseFriend(CUser *pFriendUser);

    QString getFirstName() const;
    QString getLastName() const;
    bool isOnline() const;

    const FriendList& friendList() const;

private:
    QString m_sFirstName;
    QString m_sLastName;
    bool m_bIsOnline;
    FriendList m_lstFriends;

};

#endif // CUSER_H
