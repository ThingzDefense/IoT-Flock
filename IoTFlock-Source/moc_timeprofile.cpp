/****************************************************************************
** Meta object code from reading C++ file 'timeprofile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "timeprofile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeProfile_t {
    QByteArrayData data[10];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeProfile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeProfile_t qt_meta_stringdata_TimeProfile = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TimeProfile"
QT_MOC_LITERAL(1, 12, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "on_btnSave_clicked"
QT_MOC_LITERAL(4, 53, 15), // "saveTimeProfile"
QT_MOC_LITERAL(5, 69, 15), // "fillTimeProfile"
QT_MOC_LITERAL(6, 85, 15), // "editTimeProfile"
QT_MOC_LITERAL(7, 101, 2), // "id"
QT_MOC_LITERAL(8, 104, 24), // "on_rbEventDriven_clicked"
QT_MOC_LITERAL(9, 129, 21) // "on_rbPeriodic_clicked"

    },
    "TimeProfile\0on_btnCancel_clicked\0\0"
    "on_btnSave_clicked\0saveTimeProfile\0"
    "fillTimeProfile\0editTimeProfile\0id\0"
    "on_rbEventDriven_clicked\0on_rbPeriodic_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeProfile[] = {

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
       6,    1,   53,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TimeProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TimeProfile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCancel_clicked(); break;
        case 1: _t->on_btnSave_clicked(); break;
        case 2: _t->saveTimeProfile(); break;
        case 3: _t->fillTimeProfile(); break;
        case 4: _t->editTimeProfile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_rbEventDriven_clicked(); break;
        case 6: _t->on_rbPeriodic_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimeProfile::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_TimeProfile.data,
    qt_meta_data_TimeProfile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TimeProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeProfile.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TimeProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
