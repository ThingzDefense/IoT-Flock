/****************************************************************************
** Meta object code from reading C++ file 'topics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IoTFlock/topics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'topics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Topics_t {
    QByteArrayData data[10];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Topics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Topics_t qt_meta_stringdata_Topics = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Topics"
QT_MOC_LITERAL(1, 7, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(4, 47, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(5, 66, 9), // "deleteRow"
QT_MOC_LITERAL(6, 76, 9), // "saveTopic"
QT_MOC_LITERAL(7, 86, 10), // "fillTopics"
QT_MOC_LITERAL(8, 97, 9), // "editTopic"
QT_MOC_LITERAL(9, 107, 2) // "id"

    },
    "Topics\0on_btnAdd_clicked\0\0"
    "on_btnCancel_clicked\0on_btnSave_clicked\0"
    "deleteRow\0saveTopic\0fillTopics\0editTopic\0"
    "id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Topics[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void Topics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Topics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnAdd_clicked(); break;
        case 1: _t->on_btnCancel_clicked(); break;
        case 2: _t->on_btnSave_clicked(); break;
        case 3: _t->deleteRow(); break;
        case 4: _t->saveTopic(); break;
        case 5: _t->fillTopics(); break;
        case 6: _t->editTopic((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Topics::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Topics.data,
    qt_meta_data_Topics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Topics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Topics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Topics.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Topics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
