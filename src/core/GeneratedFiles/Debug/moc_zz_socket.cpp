/****************************************************************************
** Meta object code from reading C++ file 'zz_socket.h'
**
** Created: Thu Dec 10 18:23:34 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../zz_socket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'zz_socket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_zz__CSocket[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      42,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   12,   12,   12, 0x08,
      76,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_zz__CSocket[] = {
    "zz::CSocket\0\0sigNewRequest(zz::CRequest*)\0"
    "sigRequestWasSent()\0onReadyReed()\0"
    "onBytesWritten(qint64)\0"
};

const QMetaObject zz::CSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_zz__CSocket,
      qt_meta_data_zz__CSocket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &zz::CSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *zz::CSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *zz::CSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_zz__CSocket))
        return static_cast<void*>(const_cast< CSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int zz::CSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sigNewRequest((*reinterpret_cast< zz::CRequest*(*)>(_a[1]))); break;
        case 1: sigRequestWasSent(); break;
        case 2: onReadyReed(); break;
        case 3: onBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void zz::CSocket::sigNewRequest(zz::CRequest * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void zz::CSocket::sigRequestWasSent()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
