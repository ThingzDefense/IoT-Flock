/****************************************************************************
** Meta object code from reading C++ file 'coapnetworkaccessmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "coap/coapnetworkaccessmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coapnetworkaccessmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CoapNetworkAccessManager_t {
    QByteArrayData data[19];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoapNetworkAccessManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoapNetworkAccessManager_t qt_meta_stringdata_CoapNetworkAccessManager = {
    {
QT_MOC_LITERAL(0, 0, 24), // "CoapNetworkAccessManager"
QT_MOC_LITERAL(1, 25, 13), // "replyFinished"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 10), // "CoapReply*"
QT_MOC_LITERAL(4, 51, 5), // "reply"
QT_MOC_LITERAL(5, 57, 20), // "notificationReceived"
QT_MOC_LITERAL(6, 78, 19), // "CoapObserveResource"
QT_MOC_LITERAL(7, 98, 8), // "resource"
QT_MOC_LITERAL(8, 107, 18), // "notificationNumber"
QT_MOC_LITERAL(9, 126, 7), // "payload"
QT_MOC_LITERAL(10, 134, 20), // "onHostLookupFinished"
QT_MOC_LITERAL(11, 155, 9), // "QHostInfo"
QT_MOC_LITERAL(12, 165, 8), // "hostInfo"
QT_MOC_LITERAL(13, 174, 13), // "onSocketError"
QT_MOC_LITERAL(14, 188, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(15, 217, 5), // "error"
QT_MOC_LITERAL(16, 223, 11), // "onReadyRead"
QT_MOC_LITERAL(17, 235, 14), // "onReplyTimeout"
QT_MOC_LITERAL(18, 250, 15) // "onReplyFinished"

    },
    "CoapNetworkAccessManager\0replyFinished\0"
    "\0CoapReply*\0reply\0notificationReceived\0"
    "CoapObserveResource\0resource\0"
    "notificationNumber\0payload\0"
    "onHostLookupFinished\0QHostInfo\0hostInfo\0"
    "onSocketError\0QAbstractSocket::SocketError\0"
    "error\0onReadyRead\0onReplyTimeout\0"
    "onReplyFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoapNetworkAccessManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    3,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   59,    2, 0x08 /* Private */,
      13,    1,   62,    2, 0x08 /* Private */,
      16,    0,   65,    2, 0x08 /* Private */,
      17,    0,   66,    2, 0x08 /* Private */,
      18,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, QMetaType::QByteArray,    7,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CoapNetworkAccessManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CoapNetworkAccessManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyFinished((*reinterpret_cast< CoapReply*(*)>(_a[1]))); break;
        case 1: _t->notificationReceived((*reinterpret_cast< const CoapObserveResource(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3]))); break;
        case 2: _t->onHostLookupFinished((*reinterpret_cast< const QHostInfo(*)>(_a[1]))); break;
        case 3: _t->onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->onReadyRead(); break;
        case 5: _t->onReplyTimeout(); break;
        case 6: _t->onReplyFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CoapReply* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QHostInfo >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CoapNetworkAccessManager::*)(CoapReply * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoapNetworkAccessManager::replyFinished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CoapNetworkAccessManager::*)(const CoapObserveResource & , const int & , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoapNetworkAccessManager::notificationReceived)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CoapNetworkAccessManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CoapNetworkAccessManager.data,
    qt_meta_data_CoapNetworkAccessManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CoapNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoapNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CoapNetworkAccessManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CoapNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CoapNetworkAccessManager::replyFinished(CoapReply * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CoapNetworkAccessManager::notificationReceived(const CoapObserveResource & _t1, const int & _t2, const QByteArray & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
