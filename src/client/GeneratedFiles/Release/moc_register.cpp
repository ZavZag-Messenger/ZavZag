/****************************************************************************
** Meta object code from reading C++ file 'register.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../register.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'register.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CRegister_t {
    QByteArrayData data[5];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRegister_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRegister_t qt_meta_stringdata_CRegister = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CRegister"
QT_MOC_LITERAL(1, 10, 15), // "registerClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "registerRequest"
QT_MOC_LITERAL(4, 43, 14) // "passwordEdited"

    },
    "CRegister\0registerClicked\0\0registerRequest\0"
    "passwordEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRegister[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRegister *_t = static_cast<CRegister *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->registerClicked(); break;
        case 1: _t->registerRequest(); break;
        case 2: _t->passwordEdited(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CRegister::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CRegister::registerClicked)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CRegister::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_CRegister.data,
      qt_meta_data_CRegister,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CRegister.stringdata0))
        return static_cast<void*>(const_cast< CRegister*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int CRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CRegister::registerClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
