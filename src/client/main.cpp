#include "mainwindow.h"
#include <QApplication>


# define __TEST__
#  ifdef __TEST__

#include "mainpage.h"
#include "register.h"
#include "login.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	zz_cl::CLogIn* p = new zz_cl::CLogIn();
	p->show();
	

	return a.exec();
}


#else


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zz_cl::CMainWindow w;
	w.show();

	w.connect();

    return a.exec();
}


#endif // __TEST__
// end of file