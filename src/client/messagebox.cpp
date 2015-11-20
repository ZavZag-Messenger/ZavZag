#include "messagebox.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>

#include <QPushButton>

CMessageBox::CMessageBox(QWidget *pParent)
    : QWidget(pParent)
{
    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    setLayout(pVBoxLayout);

    createMessageStory(pVBoxLayout);
    createMessageRedactor(pVBoxLayout);

    appendMessage(new CMessage("Hi"), false);

    QObject::connect(m_pSendMessageButton, SIGNAL(pressed()), this, SLOT(sendMessage()));
}


void CMessageBox::createMessageStory(QLayout *pLayout)
{
    m_pScrollArea = new QScrollArea(this);
    m_pScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pLayout->addWidget(m_pScrollArea);

    m_pScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QWidget *pScrollWidget = new QWidget;
    m_pScrollWidgetLayout = new QGridLayout;
    pScrollWidget->setLayout(m_pScrollWidgetLayout);
    pScrollWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    m_pScrollArea->setWidget(pScrollWidget);
    m_pScrollArea->setWidgetResizable(true);
}


void CMessageBox::createMessageRedactor(QLayout *pLayout)
{
    QHBoxLayout *pHBoxLayout = new QHBoxLayout;
    pLayout->addItem(pHBoxLayout);

    m_pMessageRedactor = new QTextEdit(this);
    m_pMessageRedactor->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    pHBoxLayout->addWidget(m_pMessageRedactor);

    m_pSendMessageButton = new QPushButton("send", this);
    m_pSendMessageButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    pHBoxLayout->addWidget(m_pSendMessageButton);
}



void CMessageBox::appendMessage(CMessage *pMsg, bool bMyMessage)
{
    if (bMyMessage)
    {
       m_pScrollWidgetLayout->addWidget(pMsg, m_pScrollWidgetLayout->rowCount(), 1, 1, 1);
    }
    else
    {
       m_pScrollWidgetLayout->addWidget(pMsg, m_pScrollWidgetLayout->rowCount(), 0, 1, 1);
    }
}


void CMessageBox::sendMessage()
{
    QString sMessage = m_pMessageRedactor->toPlainText();

    if (sMessage.isEmpty())
    {
        return;
    }

    CMessage *pNewMessage = new CMessage(sMessage);
    pNewMessage->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

    appendMessage(pNewMessage, true);

    m_pMessageRedactor->clear();
}
