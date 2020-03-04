/****************************************************************************
** Meta object code from reading C++ file 'qmqttclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mqtt/qmqttclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmqttclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMqttClient_t {
    QByteArrayData data[97];
    char stringdata0[1287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMqttClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMqttClient_t qt_meta_stringdata_QMqttClient = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QMqttClient"
QT_MOC_LITERAL(1, 12, 9), // "connected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "disconnected"
QT_MOC_LITERAL(4, 36, 15), // "messageReceived"
QT_MOC_LITERAL(5, 52, 7), // "message"
QT_MOC_LITERAL(6, 60, 14), // "QMqttTopicName"
QT_MOC_LITERAL(7, 75, 5), // "topic"
QT_MOC_LITERAL(8, 81, 11), // "messageSent"
QT_MOC_LITERAL(9, 93, 2), // "id"
QT_MOC_LITERAL(10, 96, 20), // "pingResponseReceived"
QT_MOC_LITERAL(11, 117, 21), // "brokerSessionRestored"
QT_MOC_LITERAL(12, 139, 15), // "subtopicChanged"
QT_MOC_LITERAL(13, 155, 8), // "subtopic"
QT_MOC_LITERAL(14, 164, 16), // "shostnameChanged"
QT_MOC_LITERAL(15, 181, 9), // "shostname"
QT_MOC_LITERAL(16, 191, 15), // "hostnameChanged"
QT_MOC_LITERAL(17, 207, 8), // "hostname"
QT_MOC_LITERAL(18, 216, 17), // "attackTypeChanged"
QT_MOC_LITERAL(19, 234, 11), // "portChanged"
QT_MOC_LITERAL(20, 246, 4), // "port"
QT_MOC_LITERAL(21, 251, 15), // "clientIdChanged"
QT_MOC_LITERAL(22, 267, 8), // "clientId"
QT_MOC_LITERAL(23, 276, 16), // "keepAliveChanged"
QT_MOC_LITERAL(24, 293, 9), // "keepAlive"
QT_MOC_LITERAL(25, 303, 22), // "protocolVersionChanged"
QT_MOC_LITERAL(26, 326, 15), // "ProtocolVersion"
QT_MOC_LITERAL(27, 342, 15), // "protocolVersion"
QT_MOC_LITERAL(28, 358, 12), // "stateChanged"
QT_MOC_LITERAL(29, 371, 11), // "ClientState"
QT_MOC_LITERAL(30, 383, 5), // "state"
QT_MOC_LITERAL(31, 389, 12), // "errorChanged"
QT_MOC_LITERAL(32, 402, 11), // "ClientError"
QT_MOC_LITERAL(33, 414, 5), // "error"
QT_MOC_LITERAL(34, 420, 15), // "usernameChanged"
QT_MOC_LITERAL(35, 436, 8), // "username"
QT_MOC_LITERAL(36, 445, 15), // "passwordChanged"
QT_MOC_LITERAL(37, 461, 8), // "password"
QT_MOC_LITERAL(38, 470, 19), // "cleanSessionChanged"
QT_MOC_LITERAL(39, 490, 12), // "cleanSession"
QT_MOC_LITERAL(40, 503, 16), // "willTopicChanged"
QT_MOC_LITERAL(41, 520, 9), // "willTopic"
QT_MOC_LITERAL(42, 530, 14), // "willQoSChanged"
QT_MOC_LITERAL(43, 545, 7), // "willQoS"
QT_MOC_LITERAL(44, 553, 18), // "willMessageChanged"
QT_MOC_LITERAL(45, 572, 11), // "willMessage"
QT_MOC_LITERAL(46, 584, 17), // "willRetainChanged"
QT_MOC_LITERAL(47, 602, 10), // "willRetain"
QT_MOC_LITERAL(48, 613, 19), // "isSubscriberChanged"
QT_MOC_LITERAL(49, 633, 12), // "isSubscriber"
QT_MOC_LITERAL(50, 646, 18), // "isPublisherChanged"
QT_MOC_LITERAL(51, 665, 11), // "isPublisher"
QT_MOC_LITERAL(52, 677, 17), // "pubMessageChanged"
QT_MOC_LITERAL(53, 695, 10), // "pubMessage"
QT_MOC_LITERAL(54, 706, 18), // "pubIntervalChanged"
QT_MOC_LITERAL(55, 725, 11), // "pubInterval"
QT_MOC_LITERAL(56, 737, 11), // "setsubtopic"
QT_MOC_LITERAL(57, 749, 12), // "setShostname"
QT_MOC_LITERAL(58, 762, 11), // "setHostname"
QT_MOC_LITERAL(59, 774, 13), // "setAttackType"
QT_MOC_LITERAL(60, 788, 10), // "attackType"
QT_MOC_LITERAL(61, 799, 7), // "setPort"
QT_MOC_LITERAL(62, 807, 11), // "setClientId"
QT_MOC_LITERAL(63, 819, 12), // "setKeepAlive"
QT_MOC_LITERAL(64, 832, 18), // "setProtocolVersion"
QT_MOC_LITERAL(65, 851, 8), // "setState"
QT_MOC_LITERAL(66, 860, 8), // "setError"
QT_MOC_LITERAL(67, 869, 11), // "setUsername"
QT_MOC_LITERAL(68, 881, 11), // "setPassword"
QT_MOC_LITERAL(69, 893, 15), // "setCleanSession"
QT_MOC_LITERAL(70, 909, 12), // "setWillTopic"
QT_MOC_LITERAL(71, 922, 10), // "setWillQoS"
QT_MOC_LITERAL(72, 933, 14), // "setWillMessage"
QT_MOC_LITERAL(73, 948, 13), // "setWillRetain"
QT_MOC_LITERAL(74, 962, 15), // "setIsSubscriber"
QT_MOC_LITERAL(75, 978, 14), // "setIsPublisher"
QT_MOC_LITERAL(76, 993, 13), // "setPubMessage"
QT_MOC_LITERAL(77, 1007, 14), // "setPubInterval"
QT_MOC_LITERAL(78, 1022, 7), // "publish"
QT_MOC_LITERAL(79, 1030, 3), // "qos"
QT_MOC_LITERAL(80, 1034, 6), // "retain"
QT_MOC_LITERAL(81, 1041, 13), // "connectToHost"
QT_MOC_LITERAL(82, 1055, 22), // "connectToHostEncrypted"
QT_MOC_LITERAL(83, 1078, 11), // "sslPeerName"
QT_MOC_LITERAL(84, 1090, 18), // "disconnectFromHost"
QT_MOC_LITERAL(85, 1109, 12), // "Disconnected"
QT_MOC_LITERAL(86, 1122, 10), // "Connecting"
QT_MOC_LITERAL(87, 1133, 9), // "Connected"
QT_MOC_LITERAL(88, 1143, 7), // "NoError"
QT_MOC_LITERAL(89, 1151, 22), // "InvalidProtocolVersion"
QT_MOC_LITERAL(90, 1174, 10), // "IdRejected"
QT_MOC_LITERAL(91, 1185, 17), // "ServerUnavailable"
QT_MOC_LITERAL(92, 1203, 21), // "BadUsernameOrPassword"
QT_MOC_LITERAL(93, 1225, 13), // "NotAuthorized"
QT_MOC_LITERAL(94, 1239, 16), // "TransportInvalid"
QT_MOC_LITERAL(95, 1256, 17), // "ProtocolViolation"
QT_MOC_LITERAL(96, 1274, 12) // "UnknownError"

    },
    "QMqttClient\0connected\0\0disconnected\0"
    "messageReceived\0message\0QMqttTopicName\0"
    "topic\0messageSent\0id\0pingResponseReceived\0"
    "brokerSessionRestored\0subtopicChanged\0"
    "subtopic\0shostnameChanged\0shostname\0"
    "hostnameChanged\0hostname\0attackTypeChanged\0"
    "portChanged\0port\0clientIdChanged\0"
    "clientId\0keepAliveChanged\0keepAlive\0"
    "protocolVersionChanged\0ProtocolVersion\0"
    "protocolVersion\0stateChanged\0ClientState\0"
    "state\0errorChanged\0ClientError\0error\0"
    "usernameChanged\0username\0passwordChanged\0"
    "password\0cleanSessionChanged\0cleanSession\0"
    "willTopicChanged\0willTopic\0willQoSChanged\0"
    "willQoS\0willMessageChanged\0willMessage\0"
    "willRetainChanged\0willRetain\0"
    "isSubscriberChanged\0isSubscriber\0"
    "isPublisherChanged\0isPublisher\0"
    "pubMessageChanged\0pubMessage\0"
    "pubIntervalChanged\0pubInterval\0"
    "setsubtopic\0setShostname\0setHostname\0"
    "setAttackType\0attackType\0setPort\0"
    "setClientId\0setKeepAlive\0setProtocolVersion\0"
    "setState\0setError\0setUsername\0setPassword\0"
    "setCleanSession\0setWillTopic\0setWillQoS\0"
    "setWillMessage\0setWillRetain\0"
    "setIsSubscriber\0setIsPublisher\0"
    "setPubMessage\0setPubInterval\0publish\0"
    "qos\0retain\0connectToHost\0"
    "connectToHostEncrypted\0sslPeerName\0"
    "disconnectFromHost\0Disconnected\0"
    "Connecting\0Connected\0NoError\0"
    "InvalidProtocolVersion\0IdRejected\0"
    "ServerUnavailable\0BadUsernameOrPassword\0"
    "NotAuthorized\0TransportInvalid\0"
    "ProtocolViolation\0UnknownError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMqttClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
      21,  470, // properties
       2,  554, // enums/sets
       0,    0, // constructors
       0,       // flags
      28,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  299,    2, 0x06 /* Public */,
       3,    0,  300,    2, 0x06 /* Public */,
       4,    2,  301,    2, 0x06 /* Public */,
       4,    1,  306,    2, 0x26 /* Public | MethodCloned */,
       8,    1,  309,    2, 0x06 /* Public */,
      10,    0,  312,    2, 0x06 /* Public */,
      11,    0,  313,    2, 0x06 /* Public */,
      12,    1,  314,    2, 0x06 /* Public */,
      14,    1,  317,    2, 0x06 /* Public */,
      16,    1,  320,    2, 0x06 /* Public */,
      18,    1,  323,    2, 0x06 /* Public */,
      19,    1,  326,    2, 0x06 /* Public */,
      21,    1,  329,    2, 0x06 /* Public */,
      23,    1,  332,    2, 0x06 /* Public */,
      25,    1,  335,    2, 0x06 /* Public */,
      28,    1,  338,    2, 0x06 /* Public */,
      31,    1,  341,    2, 0x06 /* Public */,
      34,    1,  344,    2, 0x06 /* Public */,
      36,    1,  347,    2, 0x06 /* Public */,
      38,    1,  350,    2, 0x06 /* Public */,
      40,    1,  353,    2, 0x06 /* Public */,
      42,    1,  356,    2, 0x06 /* Public */,
      44,    1,  359,    2, 0x06 /* Public */,
      46,    1,  362,    2, 0x06 /* Public */,
      48,    1,  365,    2, 0x06 /* Public */,
      50,    1,  368,    2, 0x06 /* Public */,
      52,    1,  371,    2, 0x06 /* Public */,
      54,    1,  374,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      56,    1,  377,    2, 0x0a /* Public */,
      57,    1,  380,    2, 0x0a /* Public */,
      58,    1,  383,    2, 0x0a /* Public */,
      59,    1,  386,    2, 0x0a /* Public */,
      61,    1,  389,    2, 0x0a /* Public */,
      62,    1,  392,    2, 0x0a /* Public */,
      63,    1,  395,    2, 0x0a /* Public */,
      64,    1,  398,    2, 0x0a /* Public */,
      65,    1,  401,    2, 0x0a /* Public */,
      66,    1,  404,    2, 0x0a /* Public */,
      67,    1,  407,    2, 0x0a /* Public */,
      68,    1,  410,    2, 0x0a /* Public */,
      69,    1,  413,    2, 0x0a /* Public */,
      70,    1,  416,    2, 0x0a /* Public */,
      71,    1,  419,    2, 0x0a /* Public */,
      72,    1,  422,    2, 0x0a /* Public */,
      73,    1,  425,    2, 0x0a /* Public */,
      74,    1,  428,    2, 0x0a /* Public */,
      75,    1,  431,    2, 0x0a /* Public */,
      76,    1,  434,    2, 0x0a /* Public */,
      77,    1,  437,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      78,    4,  440,    2, 0x02 /* Public */,
      78,    3,  449,    2, 0x22 /* Public | MethodCloned */,
      78,    2,  456,    2, 0x22 /* Public | MethodCloned */,
      78,    1,  461,    2, 0x22 /* Public | MethodCloned */,
      81,    0,  464,    2, 0x02 /* Public */,
      82,    1,  465,    2, 0x02 /* Public */,
      82,    0,  468,    2, 0x22 /* Public | MethodCloned */,
      84,    0,  469,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::UShort,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::UShort,   24,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::UChar,   43,
    QMetaType::Void, QMetaType::QByteArray,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void, QMetaType::UShort,   55,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Void, QMetaType::UShort,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::UShort,   24,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::UChar,   43,
    QMetaType::Void, QMetaType::QByteArray,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void, QMetaType::UShort,   55,

 // methods: parameters
    QMetaType::Int, 0x80000000 | 6, QMetaType::QByteArray, QMetaType::UChar, QMetaType::Bool,    7,    5,   79,   80,
    QMetaType::Int, 0x80000000 | 6, QMetaType::QByteArray, QMetaType::UChar,    7,    5,   79,
    QMetaType::Int, 0x80000000 | 6, QMetaType::QByteArray,    7,    5,
    QMetaType::Int, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   83,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      22, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495003,
      15, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      60, QMetaType::QString, 0x00495103,
      20, QMetaType::UShort, 0x00495103,
      24, QMetaType::UShort, 0x00495103,
      27, 0x80000000 | 26, 0x0049510b,
      30, 0x80000000 | 29, 0x0049510b,
      33, 0x80000000 | 32, 0x0049510b,
      35, QMetaType::QString, 0x00495103,
      37, QMetaType::QString, 0x00495103,
      39, QMetaType::Bool, 0x00495103,
      41, QMetaType::QString, 0x00495103,
      45, QMetaType::QByteArray, 0x00495103,
      43, QMetaType::UChar, 0x00495103,
      47, QMetaType::Bool, 0x00495103,
      49, QMetaType::Bool, 0x00495103,
      51, QMetaType::Bool, 0x00495103,
      53, QMetaType::QString, 0x00495103,
      55, QMetaType::UShort, 0x00495103,

 // properties: notify_signal_id
      12,
       7,
       8,
       9,
      10,
      11,
      13,
      14,
      15,
      16,
      17,
      18,
      19,
      20,
      22,
      21,
      23,
      24,
      25,
      26,
      27,

 // enums: name, alias, flags, count, data
      29,   29, 0x0,    3,  564,
      32,   32, 0x0,    9,  570,

 // enum data: key, value
      85, uint(QMqttClient::Disconnected),
      86, uint(QMqttClient::Connecting),
      87, uint(QMqttClient::Connected),
      88, uint(QMqttClient::NoError),
      89, uint(QMqttClient::InvalidProtocolVersion),
      90, uint(QMqttClient::IdRejected),
      91, uint(QMqttClient::ServerUnavailable),
      92, uint(QMqttClient::BadUsernameOrPassword),
      93, uint(QMqttClient::NotAuthorized),
      94, uint(QMqttClient::TransportInvalid),
      95, uint(QMqttClient::ProtocolViolation),
      96, uint(QMqttClient::UnknownError),

       0        // eod
};

void QMqttClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMqttClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->messageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QMqttTopicName(*)>(_a[2]))); break;
        case 3: _t->messageReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->messageSent((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        case 5: _t->pingResponseReceived(); break;
        case 6: _t->brokerSessionRestored(); break;
        case 7: _t->subtopicChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->shostnameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->hostnameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->attackTypeChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->portChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 12: _t->clientIdChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->keepAliveChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 14: _t->protocolVersionChanged((*reinterpret_cast< ProtocolVersion(*)>(_a[1]))); break;
        case 15: _t->stateChanged((*reinterpret_cast< ClientState(*)>(_a[1]))); break;
        case 16: _t->errorChanged((*reinterpret_cast< ClientError(*)>(_a[1]))); break;
        case 17: _t->usernameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->passwordChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->cleanSessionChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->willTopicChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->willQoSChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 22: _t->willMessageChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 23: _t->willRetainChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->isSubscriberChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->isPublisherChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->pubMessageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->pubIntervalChanged((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 28: _t->setsubtopic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->setShostname((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->setHostname((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->setAttackType((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->setPort((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 33: _t->setClientId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->setKeepAlive((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 35: _t->setProtocolVersion((*reinterpret_cast< ProtocolVersion(*)>(_a[1]))); break;
        case 36: _t->setState((*reinterpret_cast< ClientState(*)>(_a[1]))); break;
        case 37: _t->setError((*reinterpret_cast< ClientError(*)>(_a[1]))); break;
        case 38: _t->setUsername((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->setPassword((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->setCleanSession((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->setWillTopic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->setWillQoS((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 43: _t->setWillMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 44: _t->setWillRetain((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->setIsSubscriber((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->setIsPublisher((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->setPubMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->setPubInterval((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 49: { qint32 _r = _t->publish((*reinterpret_cast< const QMqttTopicName(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 50: { qint32 _r = _t->publish((*reinterpret_cast< const QMqttTopicName(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 51: { qint32 _r = _t->publish((*reinterpret_cast< const QMqttTopicName(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 52: { qint32 _r = _t->publish((*reinterpret_cast< const QMqttTopicName(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qint32*>(_a[0]) = std::move(_r); }  break;
        case 53: _t->connectToHost(); break;
        case 54: _t->connectToHostEncrypted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: _t->connectToHostEncrypted(); break;
        case 56: _t->disconnectFromHost(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        case 49:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        case 50:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        case 51:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        case 52:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMqttTopicName >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QMqttClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(const QByteArray & , const QMqttTopicName & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::messageReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(qint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::messageSent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::pingResponseReceived)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::brokerSessionRestored)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::subtopicChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::shostnameChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::hostnameChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::attackTypeChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::portChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::clientIdChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::keepAliveChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(ProtocolVersion );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::protocolVersionChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(ClientState );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::stateChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(ClientError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::errorChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::usernameChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::passwordChanged)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::cleanSessionChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::willTopicChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::willQoSChanged)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::willMessageChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::willRetainChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::isSubscriberChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::isPublisherChanged)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::pubMessageChanged)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (QMqttClient::*)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMqttClient::pubIntervalChanged)) {
                *result = 27;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QMqttClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->clientId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->subtopic(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->shostname(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->hostname(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->attackType(); break;
        case 5: *reinterpret_cast< quint16*>(_v) = _t->port(); break;
        case 6: *reinterpret_cast< quint16*>(_v) = _t->keepAlive(); break;
        case 7: *reinterpret_cast< ProtocolVersion*>(_v) = _t->protocolVersion(); break;
        case 8: *reinterpret_cast< ClientState*>(_v) = _t->state(); break;
        case 9: *reinterpret_cast< ClientError*>(_v) = _t->error(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->username(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->password(); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->cleanSession(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->willTopic(); break;
        case 14: *reinterpret_cast< QByteArray*>(_v) = _t->willMessage(); break;
        case 15: *reinterpret_cast< quint8*>(_v) = _t->willQoS(); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->willRetain(); break;
        case 17: *reinterpret_cast< bool*>(_v) = _t->isSubscriber(); break;
        case 18: *reinterpret_cast< bool*>(_v) = _t->isPublisher(); break;
        case 19: *reinterpret_cast< QString*>(_v) = _t->pubMessage(); break;
        case 20: *reinterpret_cast< quint16*>(_v) = _t->pubInterval(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QMqttClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClientId(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setsubtopic(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setShostname(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setHostname(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setAttackType(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setPort(*reinterpret_cast< quint16*>(_v)); break;
        case 6: _t->setKeepAlive(*reinterpret_cast< quint16*>(_v)); break;
        case 7: _t->setProtocolVersion(*reinterpret_cast< ProtocolVersion*>(_v)); break;
        case 8: _t->setState(*reinterpret_cast< ClientState*>(_v)); break;
        case 9: _t->setError(*reinterpret_cast< ClientError*>(_v)); break;
        case 10: _t->setUsername(*reinterpret_cast< QString*>(_v)); break;
        case 11: _t->setPassword(*reinterpret_cast< QString*>(_v)); break;
        case 12: _t->setCleanSession(*reinterpret_cast< bool*>(_v)); break;
        case 13: _t->setWillTopic(*reinterpret_cast< QString*>(_v)); break;
        case 14: _t->setWillMessage(*reinterpret_cast< QByteArray*>(_v)); break;
        case 15: _t->setWillQoS(*reinterpret_cast< quint8*>(_v)); break;
        case 16: _t->setWillRetain(*reinterpret_cast< bool*>(_v)); break;
        case 17: _t->setIsSubscriber(*reinterpret_cast< bool*>(_v)); break;
        case 18: _t->setIsPublisher(*reinterpret_cast< bool*>(_v)); break;
        case 19: _t->setPubMessage(*reinterpret_cast< QString*>(_v)); break;
        case 20: _t->setPubInterval(*reinterpret_cast< quint16*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QMqttClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QMqttClient.data,
    qt_meta_data_QMqttClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QMqttClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMqttClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMqttClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMqttClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 21;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QMqttClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QMqttClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QMqttClient::messageReceived(const QByteArray & _t1, const QMqttTopicName & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void QMqttClient::messageSent(qint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMqttClient::pingResponseReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QMqttClient::brokerSessionRestored()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QMqttClient::subtopicChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QMqttClient::shostnameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QMqttClient::hostnameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QMqttClient::attackTypeChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QMqttClient::portChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QMqttClient::clientIdChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QMqttClient::keepAliveChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QMqttClient::protocolVersionChanged(ProtocolVersion _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QMqttClient::stateChanged(ClientState _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void QMqttClient::errorChanged(ClientError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void QMqttClient::usernameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void QMqttClient::passwordChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void QMqttClient::cleanSessionChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void QMqttClient::willTopicChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void QMqttClient::willQoSChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void QMqttClient::willMessageChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void QMqttClient::willRetainChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void QMqttClient::isSubscriberChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void QMqttClient::isPublisherChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void QMqttClient::pubMessageChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void QMqttClient::pubIntervalChanged(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
