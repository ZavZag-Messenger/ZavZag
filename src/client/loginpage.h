#ifndef CLOGIN_PAGE_H
#define CLOGIN_PAGE_H

///////////////////////////////////////////////
//	includes
///////////////////////////////////////////////
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include "register.h"
#include "login.h"


namespace zz_cl
{


///////////////////////////////////////////////
//	This class is login page
///////////////////////////////////////////////
class CLogInPage : public QWidget
{
    Q_OBJECT
public:
	//
	//	constructor
	//
	explicit CLogInPage( QWidget* pParent = nullptr );

private slots:
	//
	//	register mode on / off
	//
	void registerClicled();

private:
	//
	//	make functions
	//
	//	make openning page's left side ( login and register )
	//
	void makePageLeftSide( QHBoxLayout* pLayout );
	//
	//	make login widget
	//
	void makeLogIn( QVBoxLayout* pLayout );
	//
	//	make register widgets
	//
	void makeRegister( QVBoxLayout* pLayout );

private:
	//
	//	open register
	//
	void openRegister();
	//
	//	close register
	//
	void closeRegister();

private:
	//
	//	set connections
	//
	void setConnections();

private:
	//
	//	members
	//
	CLogIn* m_pLogin;
	CRegister* m_pRegister;
	QRadioButton* m_pRegisterModeButton;

};


} // namespace zz_cl


#endif // CLOGIN_PAGE_H
// end of file