/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created: Thu Dec 10 18:20:42 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../connection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CConnection[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      28,   12,   12,   12, 0x05,
      42,   12,   12,   12, 0x05,
      55,   12,   12,   12, 0x05,
      87,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     116,  107,   12,   12, 0x0a,
     143,  107,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CConnection[] = {
    "CConnection\0\0sigConnected()\0login(CUser*)\0"
    "registered()\0showMessaging(QList<CMessage*>)\0"
    "newMessage(QString)\0pRequest\0"
    "sendRequest(zz::CRequest*)\0"
    "getResponse(zz::CRequest*)\0"
};

const QMetaObject CConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CConnection,
      qt_meta_data_CConnection, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CConnection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CConnection))
        return static_cast<void*>(const_cast< CConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int CConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigConnected(); break;
        case 1: login((*reinterpret_cast< CUser*(*)>(_a[1]))); break;
        case 2: registered(); break;
        case 3: showMessaging((*reinterpret_cast< QList<CMessage*>(*)>(_a[1]))); break;
        case 4: newMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: sendRequest((*reinterpret_cast< zz::CRequest*(*)>(_a[1]))); break;
        case 6: getResponse((*reinterpret_cast< zz::CRequest*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CConnection::sigConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CConnection::login(CUser * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CConnection::registered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CConnection::showMessaging(QList<CMessage*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CConnection::newMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
