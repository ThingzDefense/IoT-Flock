/****************************************************************************
** Meta object code from reading C++ file 'device.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IoTFlock/device.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'device.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Device_t {
    QByteArrayData data[15];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Device_t qt_meta_stringdata_Device = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Device"
QT_MOC_LITERAL(1, 7, 13), // "workRequested"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "valueChanged"
QT_MOC_LITERAL(4, 35, 5), // "value"
QT_MOC_LITERAL(5, 41, 8), // "finished"
QT_MOC_LITERAL(6, 50, 6), // "doWork"
QT_MOC_LITERAL(7, 57, 9), // "TimerTick"
QT_MOC_LITERAL(8, 67, 15), // "TimerTickAttack"
QT_MOC_LITERAL(9, 83, 17), // "updateStateChange"
QT_MOC_LITERAL(10, 101, 19), // "onCoapReplyFinished"
QT_MOC_LITERAL(11, 121, 10), // "CoapReply*"
QT_MOC_LITERAL(12, 132, 5), // "reply"
QT_MOC_LITERAL(13, 138, 32), // "onCoapNotificationSignalReceived"
QT_MOC_LITERAL(14, 171, 19) // "CoapObserveResource"

    },
    "Device\0workRequested\0\0valueChanged\0"
    "value\0finished\0doWork\0TimerTick\0"
    "TimerTickAttack\0updateStateChange\0"
    "onCoapReplyFinished\0CoapReply*\0reply\0"
    "onCoapNotificationSignalReceived\0"
    "CoapObserveResource"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      13,    3,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::QByteArray,    2,    2,    2,

       0        // eod
};

void Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workRequested(); break;
        case 1: _t->valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->doWork(); break;
        case 4: _t->TimerTick(); break;
        case 5: _t->TimerTickAttack(); break;
        case 6: _t->updateStateChange(); break;
        case 7: _t->onCoapReplyFinished((*reinterpret_cast< CoapReply*(*)>(_a[1]))); break;
        case 8: _t->onCoapNotificationSignalReceived((*reinterpret_cast< CoapObserveResource(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CoapReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::workRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Device::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::valueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Device::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Device.data,
    qt_meta_data_Device,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Device::workRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Device::valueChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Device::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
