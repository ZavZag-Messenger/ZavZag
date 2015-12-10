#ifndef RED_BLECK_TREE
#define RED_BLECK_TREE

#include <memory>

// EColor
enum EColor
{
	Black,
	Red
};



// SNode
template<typename T>
struct SNode
{
	SNode( T const& tValue, SNode* pParent, EColor eColor, SNode* pRight, SNode* pLeft )
	:  m_tValue( tValue ),
	   m_pParent( pParent ),
	   m_eColor( eColor ),
	   m_pRight( pRight ),
	   m_pLeft( pLeft )
	{}
	// Content
	T      m_tValue;
	SNode*  m_pParent;
	EColor m_eColor;
	std::unique_ptr<SNode> m_pRight;
	std::unique_ptr<SNode> m_pLeft;
};

////////////////////////////////////////////////////////////////////////////////
//
//	class CReadBleckTree
//
template<typename T>
class CReadBleckTree
{
	typedef SNode<T>* t_NodePtr;
public:
	//Constructor & Destructor
	CReadBleckTree();
	~CReadBleckTree();

public:
	//
	//	Main Interface
	//
	void insert( T const& tVal );
	void remove( T const& tVal );

	// show tree 
	void show() const;

private:
	// 
	//	Helpers
	//
	void insert_rec( SNode<T>* pNew, SNode<T>* pCurr );
	void insert_case1( SNode<T>* pNew );

private:
	//
	//	Content
	//
	std::unique_ptr< SNode<T> > m_pRoot;
};
////////////////////////////////////////////////////////////////////////////////

// CReadBleckTree
template<typename T>
CReadBleckTree<T>::CReadBleckTree()
{}

// ~CReadBleckTree
template<typename T>
CReadBleckTree<T>::~CReadBleckTree()
{}

// insert
template<typename T>
void CReadBleckTree<T>::insert( T const& tVal )
{
	SNode<T>* pNew = new SNode<T>( tVal, nullptr, Black );
	if (!m_pRoot)
		m_pRoot = pNew;
	else
		insert_rec( pNew );

}

template<typename T>
void CReadBleckTree<T>::insert_rec( SNode<T>* pNew, SNode<T>* pCurr )
{
	if (pNew->m_tValue < pCurr->m_tValue)
	{
		if (pCurr->m_pLeft)
			insert_rec( pNew, pCurr->m_pLeft );
		else
		{
			pCurr->m_pLeft = pNew;
			pNew->m_pParent = pCurr;
		}
	}
	else if (pNew->m_tValue > pCurr->m_tValue)
	{
		if (pCurr->m_pRight)
			insert_rec( pNew, pCurr->m_pRight );
		else
		{
			pCurr->m_pRight= pNew;
			pNew->m_pParent = pCurr;
		}
	}
}

// remove
template<typename T>
void CReadBleckTree<T>::remove( T const& tVal )
{

}


#endif // RED_BLECK_TREE