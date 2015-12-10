#ifndef CUSER_H
#define CUSER_H
////////////////////////////////////////////////////////////////////////////////////////////
//
//	includes
//
////////////////////////////////////////////////////////////////////////////////////////////
#include <QObject>
#include <QList>
#include <QString>
////////////////////////////////////////////////////////////////////////////////////////////
//
//	This class is contains users info
//
////////////////////////////////////////////////////////////////////////////////////////////
class CUser
{
public:
	//
	//	typedefs
	//
    typedef QList<CUser*> FriendList;

public:
	//
	//	constructors
	//
    explicit CUser();
    explicit CUser(const QString & sFirstName, const QString & sLastName, bool bOnline);
	//
	//	destructor
	//
    ~CUser();

public:
	//
	//	set functions
	//
    void setFirstName(const QString & sFirstName);
    void setLastName(const QString & sLastName);
    void setOnline(bool bOnline);					//	maybe slot
	//
	//	add new freind
	//
    void addFriend(CUser *pFreindUser);
	//
	//	erase friend
	//
    void eraseFriend(CUser *pFriendUser);
	//
	//	get functions
	//
    QString getFirstName() const;
    QString getLastName() const;
	//
	//	check is user online
	//
    bool isOnline() const;
	//
	//	get friend list
	//
    const FriendList& friendList() const;

private:
	//
	//	members
	//
    QString m_sFirstName;
    QString m_sLastName;
    bool m_bIsOnline;
    FriendList m_lstFriends;

};


#endif // CUSER_H
// end of file