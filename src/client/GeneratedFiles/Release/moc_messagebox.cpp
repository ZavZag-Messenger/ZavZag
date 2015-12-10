/****************************************************************************
** Meta object code from reading C++ file 'messagebox.h'
**
** Created: Thu Dec 10 18:20:44 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../messagebox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagebox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_zz_cl__CMessageBox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      40,   20,   19,   19, 0x08,
      68,   19,   19,   19, 0x0a,
      82,   19,   19,   19, 0x0a,
     105,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_zz_cl__CMessageBox[] = {
    "zz_cl::CMessageBox\0\0sMessage,bMyMessage\0"
    "appendMessage(QString,bool)\0sendMessage()\0"
    "reciveMessage(QString)\0"
    "showMessaging(QWidgetItem*)\0"
};

const QMetaObject zz_cl::CMessageBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_zz_cl__CMessageBox,
      qt_meta_data_zz_cl__CMessageBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &zz_cl::CMessageBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *zz_cl::CMessageBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *zz_cl::CMessageBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zz_cl__CMessageBox))
        return static_cast<void*>(const_cast< CMessageBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int zz_cl::CMessageBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: appendMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: sendMessage(); break;
        case 2: reciveMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: showMessaging((*reinterpret_cast< QWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
