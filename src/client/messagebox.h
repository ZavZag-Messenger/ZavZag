#ifndef CMESSAGEBOX_H
#define CMESSAGEBOX_H

#include <QWidget>
#include <QTextEdit>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QLayout>
#include <QVBoxLayout>

#include "message.h"

class CMessageBox : public QWidget
{
    Q_OBJECT
public:
    explicit CMessageBox(QWidget *pParent = 0);

private:
    void createMessageStory(QLayout *pLayout);
    void createMessageRedactor(QLayout *pLayout);

public slots:
    void appendMessage(CMessage *pMsg, bool bMyMessage);

private slots:
    void sendMessage();

private:
    QScrollArea *m_pScrollArea;
    QTextEdit *m_pMessageRedactor;
    QPushButton *m_pSendMessageButton;

    QGridLayout *m_pScrollWidgetLayout;

};

#endif // CMESSAGEBOX_H
