/****************************************************************************
** Meta object code from reading C++ file 'coapreply.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "coap/coapreply.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coapreply.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CoapReply_t {
    QByteArrayData data[12];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoapReply_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoapReply_t qt_meta_stringdata_CoapReply = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CoapReply"
QT_MOC_LITERAL(1, 10, 7), // "timeout"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "finished"
QT_MOC_LITERAL(4, 28, 5), // "error"
QT_MOC_LITERAL(5, 34, 5), // "Error"
QT_MOC_LITERAL(6, 40, 4), // "code"
QT_MOC_LITERAL(7, 45, 7), // "NoError"
QT_MOC_LITERAL(8, 53, 17), // "HostNotFoundError"
QT_MOC_LITERAL(9, 71, 12), // "TimeoutError"
QT_MOC_LITERAL(10, 84, 21), // "InvalidUrlSchemeError"
QT_MOC_LITERAL(11, 106, 15) // "InvalidPduError"

    },
    "CoapReply\0timeout\0\0finished\0error\0"
    "Error\0code\0NoError\0HostNotFoundError\0"
    "TimeoutError\0InvalidUrlSchemeError\0"
    "InvalidPduError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoapReply[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   34, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    1,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,

 // enums: name, alias, flags, count, data
       5,    5, 0x0,    5,   39,

 // enum data: key, value
       7, uint(CoapReply::NoError),
       8, uint(CoapReply::HostNotFoundError),
       9, uint(CoapReply::TimeoutError),
      10, uint(CoapReply::InvalidUrlSchemeError),
      11, uint(CoapReply::InvalidPduError),

       0        // eod
};

void CoapReply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CoapReply *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeout(); break;
        case 1: _t->finished(); break;
        case 2: _t->error((*reinterpret_cast< const Error(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CoapReply::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoapReply::timeout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CoapReply::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoapReply::finished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CoapReply::*)(const Error & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoapReply::error)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CoapReply::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CoapReply.data,
    qt_meta_data_CoapReply,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CoapReply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoapReply::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CoapReply.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CoapReply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void CoapReply::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CoapReply::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CoapReply::error(const Error & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
