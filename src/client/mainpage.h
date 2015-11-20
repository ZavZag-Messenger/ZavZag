#ifndef CMAINPAGE_H
#define CMAINPAGE_H

#include <QWidget>
#include <QLayout>

#include "friendlist.h"
#include "frienditem.h"
#include "user.h"
#include "messagebox.h"

class CMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit CMainPage(CUser *pUser, QWidget *pParent = 0);

private:
    void makeFriendList(QLayout *pLayout);
    void makeMessageBox(QLayout *pLayout);

signals:

public slots:

private:
    CUser *m_pUser;
    CMessageBox *m_pMessageBox;
    CFriendList *m_pFriendList;

};

#endif // CMAINPAGE_H
