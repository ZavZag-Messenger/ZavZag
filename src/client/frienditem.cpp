#include "frienditem.h"

CFriendItem::CFriendItem(CUser *pUser, QListWidget *pParent, int type)
            : QListWidgetItem(pUser->getFirstName(), pParent, type),
              m_pUser(pUser)
{
}


QVariant CFriendItem::data(int nRole)
{
    QVariant retValue;

    switch (nRole) {
    case Qt::DisplayRole:
    {
        QString sFirstName = m_pUser->getFirstName();
        QString sLastName = m_pUser->getLastName();
        retValue.setValue(sFirstName + " " + sLastName);
        break;
    }
    default:
        break;
    }

    return retValue;
}




