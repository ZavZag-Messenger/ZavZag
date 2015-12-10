#ifndef CLOGIN_H
#define CLOGIN_H


///////////////////////////////////////////////
//	includes
///////////////////////////////////////////////
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include "connection.h"


namespace zz_cl
{


///////////////////////////////////////////////
//	This class is login widget
///////////////////////////////////////////////
class CLogIn : public QWidget
{
	Q_OBJECT
public:
	explicit CLogIn( QWidget* pParent = nullptr );

private:
	//
	//	make user name
	//
	void makeUserName( QLayout *pLayout );
	//
	//	make password ( this part maybe will marge by login )
	//
	void makePassword( QLayout *pLayout );
	//
	//	make login button ( this part maybe will marge by login )
	//
	void makeLogInButton( QLayout *pLayout );

private:
	//
	//	set connections
	//
	void setConnections();
	//
	//	returns true if username and password wrote
	//
	bool isValid() const;

private slots:
	//
	void sendRequest();

private:
	//
	//	members
	//	
	QLineEdit* m_pUserName;
	QLineEdit* m_pPassword;
	QPushButton* m_pLoginButton;

};


} // namespace zz_cl


#endif // CLOGIN_PAGE_H
// end of file