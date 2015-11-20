/****************************************************************************
** Meta object code from reading C++ file 'messagebox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../messagebox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messagebox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CMessageBox_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMessageBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMessageBox_t qt_meta_stringdata_CMessageBox = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CMessageBox"
QT_MOC_LITERAL(1, 12, 13), // "appendMessage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "CMessage*"
QT_MOC_LITERAL(4, 37, 4), // "pMsg"
QT_MOC_LITERAL(5, 42, 10), // "bMyMessage"
QT_MOC_LITERAL(6, 53, 11) // "sendMessage"

    },
    "CMessageBox\0appendMessage\0\0CMessage*\0"
    "pMsg\0bMyMessage\0sendMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMessageBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x0a /* Public */,
       6,    0,   29,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void,

       0        // eod
};

void CMessageBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMessageBox *_t = static_cast<CMessageBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendMessage((*reinterpret_cast< CMessage*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->sendMessage(); break;
        default: ;
        }
    }
}

const QMetaObject CMessageBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMessageBox.data,
      qt_meta_data_CMessageBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CMessageBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMessageBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CMessageBox.stringdata0))
        return static_cast<void*>(const_cast< CMessageBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int CMessageBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
