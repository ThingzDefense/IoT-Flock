/****************************************************************************
** Meta object code from reading C++ file 'coappdu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IoTFlock/coap/coappdu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'coappdu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CoapPdu_t {
    QByteArrayData data[42];
    char stringdata0[528];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CoapPdu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CoapPdu_t qt_meta_stringdata_CoapPdu = {
    {
QT_MOC_LITERAL(0, 0, 7), // "CoapPdu"
QT_MOC_LITERAL(1, 8, 11), // "MessageType"
QT_MOC_LITERAL(2, 20, 11), // "Confirmable"
QT_MOC_LITERAL(3, 32, 14), // "NonConfirmable"
QT_MOC_LITERAL(4, 47, 15), // "Acknowledgement"
QT_MOC_LITERAL(5, 63, 5), // "Reset"
QT_MOC_LITERAL(6, 69, 10), // "StatusCode"
QT_MOC_LITERAL(7, 80, 5), // "Empty"
QT_MOC_LITERAL(8, 86, 3), // "Get"
QT_MOC_LITERAL(9, 90, 4), // "Post"
QT_MOC_LITERAL(10, 95, 3), // "Put"
QT_MOC_LITERAL(11, 99, 6), // "Delete"
QT_MOC_LITERAL(12, 106, 7), // "Created"
QT_MOC_LITERAL(13, 114, 7), // "Deleted"
QT_MOC_LITERAL(14, 122, 5), // "Valid"
QT_MOC_LITERAL(15, 128, 7), // "Changed"
QT_MOC_LITERAL(16, 136, 7), // "Content"
QT_MOC_LITERAL(17, 144, 8), // "Continue"
QT_MOC_LITERAL(18, 153, 10), // "BadRequest"
QT_MOC_LITERAL(19, 164, 12), // "Unauthorized"
QT_MOC_LITERAL(20, 177, 9), // "BadOption"
QT_MOC_LITERAL(21, 187, 9), // "Forbidden"
QT_MOC_LITERAL(22, 197, 8), // "NotFound"
QT_MOC_LITERAL(23, 206, 16), // "MethodNotAllowed"
QT_MOC_LITERAL(24, 223, 13), // "NotAcceptable"
QT_MOC_LITERAL(25, 237, 23), // "RequestEntityIncomplete"
QT_MOC_LITERAL(26, 261, 18), // "PreconditionFailed"
QT_MOC_LITERAL(27, 280, 21), // "RequestEntityTooLarge"
QT_MOC_LITERAL(28, 302, 24), // "UnsupportedContentFormat"
QT_MOC_LITERAL(29, 327, 19), // "InternalServerError"
QT_MOC_LITERAL(30, 347, 14), // "NotImplemented"
QT_MOC_LITERAL(31, 362, 10), // "BadGateway"
QT_MOC_LITERAL(32, 373, 17), // "ServiceUnavailabl"
QT_MOC_LITERAL(33, 391, 14), // "GatewayTimeout"
QT_MOC_LITERAL(34, 406, 20), // "ProxyingNotSupported"
QT_MOC_LITERAL(35, 427, 11), // "ContentType"
QT_MOC_LITERAL(36, 439, 9), // "TextPlain"
QT_MOC_LITERAL(37, 449, 15), // "ApplicationLink"
QT_MOC_LITERAL(38, 465, 14), // "ApplicationXml"
QT_MOC_LITERAL(39, 480, 16), // "ApplicationOctet"
QT_MOC_LITERAL(40, 497, 14), // "ApplicationExi"
QT_MOC_LITERAL(41, 512, 15) // "ApplicationJson"

    },
    "CoapPdu\0MessageType\0Confirmable\0"
    "NonConfirmable\0Acknowledgement\0Reset\0"
    "StatusCode\0Empty\0Get\0Post\0Put\0Delete\0"
    "Created\0Deleted\0Valid\0Changed\0Content\0"
    "Continue\0BadRequest\0Unauthorized\0"
    "BadOption\0Forbidden\0NotFound\0"
    "MethodNotAllowed\0NotAcceptable\0"
    "RequestEntityIncomplete\0PreconditionFailed\0"
    "RequestEntityTooLarge\0UnsupportedContentFormat\0"
    "InternalServerError\0NotImplemented\0"
    "BadGateway\0ServiceUnavailabl\0"
    "GatewayTimeout\0ProxyingNotSupported\0"
    "ContentType\0TextPlain\0ApplicationLink\0"
    "ApplicationXml\0ApplicationOctet\0"
    "ApplicationExi\0ApplicationJson"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CoapPdu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       3,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    4,   29,
       6,    6, 0x0,   28,   37,
      35,   35, 0x0,    6,   93,

 // enum data: key, value
       2, uint(CoapPdu::Confirmable),
       3, uint(CoapPdu::NonConfirmable),
       4, uint(CoapPdu::Acknowledgement),
       5, uint(CoapPdu::Reset),
       7, uint(CoapPdu::Empty),
       8, uint(CoapPdu::Get),
       9, uint(CoapPdu::Post),
      10, uint(CoapPdu::Put),
      11, uint(CoapPdu::Delete),
      12, uint(CoapPdu::Created),
      13, uint(CoapPdu::Deleted),
      14, uint(CoapPdu::Valid),
      15, uint(CoapPdu::Changed),
      16, uint(CoapPdu::Content),
      17, uint(CoapPdu::Continue),
      18, uint(CoapPdu::BadRequest),
      19, uint(CoapPdu::Unauthorized),
      20, uint(CoapPdu::BadOption),
      21, uint(CoapPdu::Forbidden),
      22, uint(CoapPdu::NotFound),
      23, uint(CoapPdu::MethodNotAllowed),
      24, uint(CoapPdu::NotAcceptable),
      25, uint(CoapPdu::RequestEntityIncomplete),
      26, uint(CoapPdu::PreconditionFailed),
      27, uint(CoapPdu::RequestEntityTooLarge),
      28, uint(CoapPdu::UnsupportedContentFormat),
      29, uint(CoapPdu::InternalServerError),
      30, uint(CoapPdu::NotImplemented),
      31, uint(CoapPdu::BadGateway),
      32, uint(CoapPdu::ServiceUnavailabl),
      33, uint(CoapPdu::GatewayTimeout),
      34, uint(CoapPdu::ProxyingNotSupported),
      36, uint(CoapPdu::TextPlain),
      37, uint(CoapPdu::ApplicationLink),
      38, uint(CoapPdu::ApplicationXml),
      39, uint(CoapPdu::ApplicationOctet),
      40, uint(CoapPdu::ApplicationExi),
      41, uint(CoapPdu::ApplicationJson),

       0        // eod
};

void CoapPdu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CoapPdu::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CoapPdu.data,
    qt_meta_data_CoapPdu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CoapPdu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CoapPdu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CoapPdu.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CoapPdu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
