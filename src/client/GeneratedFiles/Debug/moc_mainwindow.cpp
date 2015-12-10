/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Dec 10 21:27:51 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_zz_cl__CMainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      42,   36,   19,   19, 0x0a,
      71,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_zz_cl__CMainWindow[] = {
    "zz_cl::CMainWindow\0\0openLogInPage()\0"
    "pUser\0openMainPage(zz::CUserInfo*)\0"
    "makeStatusBar()\0"
};

const QMetaObject zz_cl::CMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_zz_cl__CMainWindow,
      qt_meta_data_zz_cl__CMainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &zz_cl::CMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *zz_cl::CMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *zz_cl::CMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zz_cl__CMainWindow))
        return static_cast<void*>(const_cast< CMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int zz_cl::CMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openLogInPage(); break;
        case 1: openMainPage((*reinterpret_cast< zz::CUserInfo*(*)>(_a[1]))); break;
        case 2: makeStatusBar(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
