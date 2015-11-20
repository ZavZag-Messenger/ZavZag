#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QWidget>

class CMessage : public QWidget
{
public:
    explicit CMessage(const QString & sMessage, QWidget *pParent = 0);

private:

};

#endif // CMESSAGE_H
