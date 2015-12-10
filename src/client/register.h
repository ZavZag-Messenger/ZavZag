#ifndef CREGISTER_H
#define CREGISTER_H

//////////////////////////////////////////////////////////////////////////
//	includes
//////////////////////////////////////////////////////////////////////////
#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QButtonGroup>
#include <QPushButton>


namespace zz_cl
{


//////////////////////////////////////////////////////////////////////////
//	This class is register widget
//////////////////////////////////////////////////////////////////////////
class CRegister : public QWidget
{
    Q_OBJECT
public:
	//
	//	constructor
	//
	explicit CRegister( const QString & sTitle, QWidget *pParent = nullptr );

private:
	//
	//	make functions
	//
    void makeFirstNameField(QLayout *pLayout);
    void makeLastNameField(QLayout *pLayout);
    void makeUserNameField(QLayout *pLayout);
    void makePasswordField(QLayout *pLayout);
    void makeGenderField(QLayout *pLayout);
    void makeBirthdayField(QLayout *pLayout);
    void makeRegisterButton(QLayout *pLayout);

private:
	//
	//
	//
//	void setConnections();
	//
	//	returns true if there are all required datas
	//
	bool isValid() const;

signals:
	//
	//	register signals
	//
 //   void registerClicked();

public slots:	//	maybe private slots
	//
	//	register request
	//
    void registerRequest();
	//
	//	password edited
	//
    void passwordEdited();

private:
	//
	//	members
	//
    QLineEdit *m_pFirstNameField;
    QLineEdit *m_pLastNameField;
    QLineEdit *m_pUserNameField;
    QLineEdit *m_pPasswordField;
    QLineEdit *m_pConfirmPasswordField;
    QDateEdit *m_pBirthdayField;
    QButtonGroup *m_pGender;
    QPushButton *m_pRegisterButton;

};


} // namespace zz_cl


#endif // CREGISTER_H
// end of file