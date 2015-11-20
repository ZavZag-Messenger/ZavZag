#include "message.h"
#include <QLabel>
#include <QVBoxLayout>

CMessage::CMessage(const QString & sMessage, QWidget *pParent)
    : QWidget(pParent)
{
    QVBoxLayout *pVLayout = new QVBoxLayout();
    pVLayout->setMargin(0);
    setLayout(pVLayout);

    QLabel *pLabel = new QLabel(sMessage, this);
    pLabel->setAutoFillBackground(true);
    pLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    pVLayout->addWidget(pLabel);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

