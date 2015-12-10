#include "messagestorylayout.h"


CMessageStoryLayout::CMessageStoryLayout(QWidget *pParent, int nSpacing, int nMargin)
			: QLayout(pParent)
{
	setSpacing( nSpacing );
	setMargin( nMargin );
}


CMessageStoryLayout::~CMessageStoryLayout()
{
	QLayoutItem* pItem = nullptr;
	while ( pItem = takeAt(0) )
	{
		delete pItem;
	}
}


void CMessageStoryLayout::addItem(QLayoutItem* pItem)
{
	add(pItem, ESide::left);
}


void CMessageStoryLayout::addWidget(QWidget* pWidget, ESide side)
{
	pWidget->setParent( parentWidget() );
	addChildWidget( pWidget );
	add( new QWidgetItem( pWidget ), side );
	parentWidget()->setGeometry( geometry() );
	pWidget->setVisible( true );
	invalidate();
}


QSize CMessageStoryLayout::sizeHint() const
{
	return calculateSize( ESizeType::sizeHint );
}


QSize CMessageStoryLayout::minimumSize() const
{
	return calculateSize( ESizeType::minimumSize );
}


void CMessageStoryLayout::setGeometry(const QRect & rect)
{
	//	set layout geometry
	QLayout::setGeometry( rect );
	//	calculate items geometry
	int nTop = margin();
	ItemWraperList::const_iterator cIt = m_lstItems.constBegin();
	while ( cIt != m_lstItems.constEnd() )
	{
		SItemWraper* pItemWraper = *cIt;
		QLayoutItem* pItem = pItemWraper->m_pItem;

		if ( pItemWraper->m_eSide == ESide::left )
		{
			QRect itemRect( rect.left() + margin(), rect.top() + nTop, calculateItemsWidth( rect.width() ), 50 );
			pItem->setGeometry( itemRect );
		}
		else if ( pItemWraper->m_eSide == ESide::right )
		{
			QRect itemRect( rect.left() + 5 * margin(), rect.top() + nTop, calculateItemsWidth( rect.width() ), 50 );
			pItem->setGeometry( itemRect );
		}
		else
		{
			/* throw */
		}
		
		nTop += 50;// +spacing();

		++cIt;
	}

	//	calculate layout geometry
	QSize layoutSize( rect.width(), qMax( nTop - margin(), rect.height() ) );
	QRect layoutRect( rect.topLeft(), layoutSize );


}


QLayoutItem* CMessageStoryLayout::itemAt(int index) const
{
	SItemWraper* pItemWraper = m_lstItems.value(index);

	if (pItemWraper)
		return pItemWraper->m_pItem;
	else
		return nullptr;
}


QLayoutItem* CMessageStoryLayout::takeAt(int index)
{
	QLayoutItem *pItem = nullptr;

	if (index >= 0 && index < m_lstItems.size())
	{
		SItemWraper *pItemWraper = m_lstItems.takeAt(index);
		pItem = pItemWraper->m_pItem;
	}

	return pItem;
}


int CMessageStoryLayout::count() const
{
	return m_lstItems.size();
}


void CMessageStoryLayout::add(QLayoutItem *pItem, ESide side)
{
	m_lstItems.append( new SItemWraper(pItem, side) );
}


QSize CMessageStoryLayout::calculateSize(ESizeType sizeType) const
{
	QSize totalSize(0, 0);

	ItemWraperList::const_iterator cIt = m_lstItems.constBegin();
	while ( cIt != m_lstItems.constEnd() )
	{
		SItemWraper *pItemWraper = *cIt;
		QLayoutItem *pItem = pItemWraper->m_pItem;
		QSize itemSize;

		if ( sizeType == ESizeType::maximumSize )
		{
			itemSize = pItem->widget()->maximumSize();
		}
		else if ( sizeType == ESizeType::minimumSize )
		{
			itemSize = pItem->widget()->minimumSize();
		}
		else if ( sizeType == ESizeType::sizeHint )
		{
			itemSize = pItem->widget()->sizeHint();
		}
		else
		{
			/* throw */
		}

		totalSize.rheight() += itemSize.height();// +spacing();

		++cIt;
	}

	totalSize.setWidth( geometry().width() );

	return totalSize;
}


int CMessageStoryLayout::calculateItemsWidth( int nLayoutWidth ) const
{
	int nWidth = nLayoutWidth - ( 6 * margin() );

	if ( nWidth < 0 )
	{
		nWidth = 0;
	}

	return nWidth;
}
