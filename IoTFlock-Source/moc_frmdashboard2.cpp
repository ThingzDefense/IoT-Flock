/****************************************************************************
** Meta object code from reading C++ file 'frmdashboard2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "frmdashboard2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frmdashboard2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_frmDashboard2_t {
    QByteArrayData data[7];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_frmDashboard2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_frmDashboard2_t qt_meta_stringdata_frmDashboard2 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "frmDashboard2"
QT_MOC_LITERAL(1, 14, 27), // "on_btnAddNewUseCase_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 24), // "on_actionTopic_triggered"
QT_MOC_LITERAL(4, 68, 31), // "on_actionData_Profile_triggered"
QT_MOC_LITERAL(5, 100, 31), // "on_actionTime_Profile_triggered"
QT_MOC_LITERAL(6, 132, 34) // "on_actionDevice_Template_trig..."

    },
    "frmDashboard2\0on_btnAddNewUseCase_clicked\0"
    "\0on_actionTopic_triggered\0"
    "on_actionData_Profile_triggered\0"
    "on_actionTime_Profile_triggered\0"
    "on_actionDevice_Template_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_frmDashboard2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void frmDashboard2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<frmDashboard2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnAddNewUseCase_clicked(); break;
        case 1: _t->on_actionTopic_triggered(); break;
        case 2: _t->on_actionData_Profile_triggered(); break;
        case 3: _t->on_actionTime_Profile_triggered(); break;
        case 4: _t->on_actionDevice_Template_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject frmDashboard2::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_frmDashboard2.data,
    qt_meta_data_frmDashboard2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *frmDashboard2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *frmDashboard2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_frmDashboard2.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int frmDashboard2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
