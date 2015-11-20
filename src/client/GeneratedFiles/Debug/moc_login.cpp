/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CLogIn_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLogIn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLogIn_t qt_meta_stringdata_CLogIn = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CLogIn"
QT_MOC_LITERAL(1, 7, 15), // "registerClicked"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "loginClicked"
QT_MOC_LITERAL(4, 37, 15), // "registerRequest"
QT_MOC_LITERAL(5, 53, 12) // "loginRequest"

    },
    "CLogIn\0registerClicked\0\0loginClicked\0"
    "registerRequest\0loginRequest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLogIn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CLogIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CLogIn *_t = static_cast<CLogIn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->registerClicked(); break;
        case 1: _t->loginClicked(); break;
        case 2: _t->registerRequest(); break;
        case 3: _t->loginRequest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CLogIn::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLogIn::registerClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (CLogIn::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLogIn::loginClicked)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CLogIn::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CLogIn.data,
      qt_meta_data_CLogIn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CLogIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLogIn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CLogIn.stringdata0))
        return static_cast<void*>(const_cast< CLogIn*>(this));
    return QWidget::qt_metacast(_clname);
}

int CLogIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CLogIn::registerClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CLogIn::loginClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
