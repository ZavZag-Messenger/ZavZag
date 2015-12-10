/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created: Thu Dec 10 21:27:50 2015
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
static const uint qt_meta_data_zz_cl__CConnector[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   34,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_zz_cl__CConnector[] = {
    "zz_cl::CConnector\0\0sigConnected()\0"
    "pSocket,,nPort\0tryToConnect(zz::CSocket*,QString,int)\0"
};

const QMetaObject zz_cl::CConnector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_zz_cl__CConnector,
      qt_meta_data_zz_cl__CConnector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &zz_cl::CConnector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *zz_cl::CConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *zz_cl::CConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zz_cl__CConnector))
        return static_cast<void*>(const_cast< CConnector*>(this));
    return QObject::qt_metacast(_clname);
}

int zz_cl::CConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigConnected(); break;
        case 1: tryToConnect((*reinterpret_cast< zz::CSocket*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void zz_cl::CConnector::sigConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_zz_cl__CConnection[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      38,   35,   19,   19, 0x05,
      80,   19,   19,   19, 0x05,
      94,   19,   19,   19, 0x05,
     107,   19,   19,   19, 0x05,
     139,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     168,  159,   19,   19, 0x0a,
     195,   19,   19,   19, 0x0a,
     207,  159,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_zz_cl__CConnection[] = {
    "zz_cl::CConnection\0\0sigConnected()\0"
    ",,\0sigTryToConnect(zz::CSocket*,QString,int)\0"
    "login(CUser*)\0registered()\0"
    "showMessaging(QList<CMessage*>)\0"
    "newMessage(QString)\0pRequest\0"
    "sendRequest(zz::CRequest*)\0connected()\0"
    "getResponse(zz::CRequest*)\0"
};

const QMetaObject zz_cl::CConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_zz_cl__CConnection,
      qt_meta_data_zz_cl__CConnection, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &zz_cl::CConnection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *zz_cl::CConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *zz_cl::CConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zz_cl__CConnection))
        return static_cast<void*>(const_cast< CConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int zz_cl::CConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigConnected(); break;
        case 1: sigTryToConnect((*reinterpret_cast< zz::CSocket*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: login((*reinterpret_cast< CUser*(*)>(_a[1]))); break;
        case 3: registered(); break;
        case 4: showMessaging((*reinterpret_cast< QList<CMessage*>(*)>(_a[1]))); break;
        case 5: newMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: sendRequest((*reinterpret_cast< zz::CRequest*(*)>(_a[1]))); break;
        case 7: connected(); break;
        case 8: getResponse((*reinterpret_cast< zz::CRequest*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void zz_cl::CConnection::sigConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void zz_cl::CConnection::sigTryToConnect(zz::CSocket * _t1, QString const & _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void zz_cl::CConnection::login(CUser * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void zz_cl::CConnection::registered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void zz_cl::CConnection::showMessaging(QList<CMessage*> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void zz_cl::CConnection::newMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
