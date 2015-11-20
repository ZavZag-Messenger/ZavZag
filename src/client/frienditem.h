#ifndef CFRIENDITEM_H
#define CFRIENDITEM_H

#include <QListWidgetItem>

#include "user.h"



class CFriendItem : public QListWidgetItem
{
public:
    CFriendItem(CUser *pUser, QListWidget * pParent = 0, int type = 1001);

    QVariant data(int nRole);

private:
    CUser *m_pUser;

};

#endif // CFRIENDITEM_H
