#ifndef CMESSAGESTORYLAYOUT_H
#define CMESSAGESTORYLAYOUT_H
///////////////////////////////////////////////////////////
//
//	includes
//
////////////////////////////////////////////////////////////
#include <QWidget>
#include <QLayout>
////////////////////////////////////////////////////////////
//
//	This class is message story's scroll area's layuot widget
//
////////////////////////////////////////////////////////////
class CMessageStoryLayout : public QLayout
{
public:
	//
	// enum	item side
	//
	enum class ESide
	{
		left,
		right
	};

	//
	//	enum size type ( for calculate size )
	//
	enum class ESizeType
	{
		minimumSize,
		maximumSize,
		sizeHint
	};

private:
	//
	//	layout item wraper
	//
	struct SItemWraper
	{
		//
		//	constructor
		//
		SItemWraper(QLayoutItem *pItem, ESide side)
					: m_pItem(pItem),
					  m_eSide(side)
		{
		}

		//
		//	members
		//
		QLayoutItem* m_pItem;		//	item
		ESide m_eSide;				//	item side
	};

	typedef QList<SItemWraper*> ItemWraperList;

public:
	//
	//	constructor
	//
	explicit CMessageStoryLayout(QWidget *pParent = nullptr, int nSpacing = 0, int nMargin = 0);
	//
	//	destructor
	//
	virtual ~CMessageStoryLayout();

public:
	//
	//	add item
	//
	void addItem(QLayoutItem* pItem);
	//
	//	add widget
	//
	void addWidget(QWidget* pWidget, ESide side);
	//
	//	return size hint 
	//
	QSize sizeHint() const;
	//
	//	return minimum size
	//
	QSize minimumSize() const;
	//
	//	set geometry
	//
	void setGeometry(const QRect & rect);
	//
	//	return layout item at index
	//
	QLayoutItem* itemAt(int index) const;
	//
	//	remove layout item at index, and return the item
	//
	QLayoutItem* takeAt(int index);
	//
	//	return items count
	//
	int count() const;

private:
	//
	//	helper functions
	//
	//
	//	add item to side
	//
	void add(QLayoutItem *pItem, ESide side);
	//
	//	calculate size
	//
	QSize calculateSize(ESizeType sizeType) const;
	//
	//	calculate items width
	//
	int calculateItemsWidth( int nLayoutWidth ) const;

private:
	//
	//	members
	//
	ItemWraperList m_lstItems;		//	items list

};


#endif // CMESSAGESTORYLAYOUT_H
// end of file
