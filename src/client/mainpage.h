#ifndef CMAINPAGE_H
#define CMAINPAGE_H
///////////////////////////////////////////////////////////////////////
//
//	includes
//
///////////////////////////////////////////////////////////////////////
#include <QWidget>
#include <QLayout>
#include "friendlist.h"
#include "friendWidget.h"
#include "zz_utility.h"
#include "messagebox.h"


namespace zz_cl
{


///////////////////////////////////////////////////////////////////////
//
//	This class is main page, this widget contains chat and friend list
//
///////////////////////////////////////////////////////////////////////
class CMainPage : public QWidget
{
    Q_OBJECT
public:
	//
	//	constructors
	//
	explicit CMainPage( zz::CUserInfo* pUser, QWidget *pParent = nullptr );

private:
	//
	//	make friend list
	//
    void makeFriendList(QLayout *pLayout);
	//
	//	make message box
	//
    void makeMessageBox(QLayout *pLayout);

signals:
	/* empty */

public slots:
	/* empty */

private:
	//
	//	members
	//
    zz::CUserInfo* m_pUser;
    CMessageBox* m_pMessageBox;
    CFriendList* m_pFriendList;

};


} // namespace zz_cl


#endif // CMAINPAGE_H
//	end of file