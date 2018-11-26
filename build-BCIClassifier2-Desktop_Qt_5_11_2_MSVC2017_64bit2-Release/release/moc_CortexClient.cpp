/****************************************************************************
** Meta object code from reading C++ file 'CortexClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BCIClassifier2/CortexClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CortexClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CortexClient_t {
    QByteArrayData data[68];
    char stringdata0[724];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CortexClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CortexClient_t qt_meta_stringdata_CortexClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CortexClient"
QT_MOC_LITERAL(1, 13, 9), // "connected"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "disconnected"
QT_MOC_LITERAL(4, 37, 15), // "queryHeadsetsOk"
QT_MOC_LITERAL(5, 53, 14), // "QList<Headset>"
QT_MOC_LITERAL(6, 68, 8), // "headsets"
QT_MOC_LITERAL(7, 77, 14), // "getUserLoginOk"
QT_MOC_LITERAL(8, 92, 9), // "usernames"
QT_MOC_LITERAL(9, 102, 7), // "loginOk"
QT_MOC_LITERAL(10, 110, 8), // "logoutOk"
QT_MOC_LITERAL(11, 119, 11), // "authorizeOk"
QT_MOC_LITERAL(12, 131, 9), // "authToken"
QT_MOC_LITERAL(13, 141, 15), // "createSessionOk"
QT_MOC_LITERAL(14, 157, 9), // "sessionId"
QT_MOC_LITERAL(15, 167, 14), // "closeSessionOk"
QT_MOC_LITERAL(16, 182, 11), // "subscribeOk"
QT_MOC_LITERAL(17, 194, 13), // "unsubscribeOk"
QT_MOC_LITERAL(18, 208, 3), // "msg"
QT_MOC_LITERAL(19, 212, 18), // "getDetectionInfoOk"
QT_MOC_LITERAL(20, 231, 7), // "actions"
QT_MOC_LITERAL(21, 239, 8), // "controls"
QT_MOC_LITERAL(22, 248, 6), // "events"
QT_MOC_LITERAL(23, 255, 10), // "trainingOk"
QT_MOC_LITERAL(24, 266, 14), // "injectMarkerOk"
QT_MOC_LITERAL(25, 281, 13), // "errorReceived"
QT_MOC_LITERAL(26, 295, 6), // "method"
QT_MOC_LITERAL(27, 302, 4), // "code"
QT_MOC_LITERAL(28, 307, 5), // "error"
QT_MOC_LITERAL(29, 313, 18), // "streamDataReceived"
QT_MOC_LITERAL(30, 332, 6), // "stream"
QT_MOC_LITERAL(31, 339, 4), // "time"
QT_MOC_LITERAL(32, 344, 4), // "data"
QT_MOC_LITERAL(33, 349, 4), // "open"
QT_MOC_LITERAL(34, 354, 5), // "close"
QT_MOC_LITERAL(35, 360, 13), // "queryHeadsets"
QT_MOC_LITERAL(36, 374, 12), // "getUserLogin"
QT_MOC_LITERAL(37, 387, 5), // "login"
QT_MOC_LITERAL(38, 393, 8), // "username"
QT_MOC_LITERAL(39, 402, 8), // "password"
QT_MOC_LITERAL(40, 411, 8), // "clientId"
QT_MOC_LITERAL(41, 420, 12), // "clientSecret"
QT_MOC_LITERAL(42, 433, 6), // "logout"
QT_MOC_LITERAL(43, 440, 9), // "authorize"
QT_MOC_LITERAL(44, 450, 7), // "license"
QT_MOC_LITERAL(45, 458, 13), // "createSession"
QT_MOC_LITERAL(46, 472, 5), // "token"
QT_MOC_LITERAL(47, 478, 9), // "headsetId"
QT_MOC_LITERAL(48, 488, 8), // "activate"
QT_MOC_LITERAL(49, 497, 12), // "closeSession"
QT_MOC_LITERAL(50, 510, 9), // "subscribe"
QT_MOC_LITERAL(51, 520, 11), // "unsubscribe"
QT_MOC_LITERAL(52, 532, 16), // "getDetectionInfo"
QT_MOC_LITERAL(53, 549, 9), // "detection"
QT_MOC_LITERAL(54, 559, 8), // "training"
QT_MOC_LITERAL(55, 568, 6), // "action"
QT_MOC_LITERAL(56, 575, 7), // "control"
QT_MOC_LITERAL(57, 583, 12), // "injectMarker"
QT_MOC_LITERAL(58, 596, 5), // "label"
QT_MOC_LITERAL(59, 602, 5), // "value"
QT_MOC_LITERAL(60, 608, 16), // "injectStopMarker"
QT_MOC_LITERAL(61, 625, 7), // "onError"
QT_MOC_LITERAL(62, 633, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(63, 662, 11), // "onSslErrors"
QT_MOC_LITERAL(64, 674, 16), // "QList<QSslError>"
QT_MOC_LITERAL(65, 691, 6), // "errors"
QT_MOC_LITERAL(66, 698, 17), // "onMessageReceived"
QT_MOC_LITERAL(67, 716, 7) // "message"

    },
    "CortexClient\0connected\0\0disconnected\0"
    "queryHeadsetsOk\0QList<Headset>\0headsets\0"
    "getUserLoginOk\0usernames\0loginOk\0"
    "logoutOk\0authorizeOk\0authToken\0"
    "createSessionOk\0sessionId\0closeSessionOk\0"
    "subscribeOk\0unsubscribeOk\0msg\0"
    "getDetectionInfoOk\0actions\0controls\0"
    "events\0trainingOk\0injectMarkerOk\0"
    "errorReceived\0method\0code\0error\0"
    "streamDataReceived\0stream\0time\0data\0"
    "open\0close\0queryHeadsets\0getUserLogin\0"
    "login\0username\0password\0clientId\0"
    "clientSecret\0logout\0authorize\0license\0"
    "createSession\0token\0headsetId\0activate\0"
    "closeSession\0subscribe\0unsubscribe\0"
    "getDetectionInfo\0detection\0training\0"
    "action\0control\0injectMarker\0label\0"
    "value\0injectStopMarker\0onError\0"
    "QAbstractSocket::SocketError\0onSslErrors\0"
    "QList<QSslError>\0errors\0onMessageReceived\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CortexClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x06 /* Public */,
       3,    0,  190,    2, 0x06 /* Public */,
       4,    1,  191,    2, 0x06 /* Public */,
       7,    1,  194,    2, 0x06 /* Public */,
       9,    0,  197,    2, 0x06 /* Public */,
      10,    0,  198,    2, 0x06 /* Public */,
      11,    1,  199,    2, 0x06 /* Public */,
      13,    1,  202,    2, 0x06 /* Public */,
      15,    0,  205,    2, 0x06 /* Public */,
      16,    1,  206,    2, 0x06 /* Public */,
      17,    1,  209,    2, 0x06 /* Public */,
      19,    3,  212,    2, 0x06 /* Public */,
      23,    1,  219,    2, 0x06 /* Public */,
      24,    0,  222,    2, 0x06 /* Public */,
      25,    3,  223,    2, 0x06 /* Public */,
      29,    4,  230,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      33,    0,  239,    2, 0x0a /* Public */,
      34,    0,  240,    2, 0x0a /* Public */,
      35,    0,  241,    2, 0x0a /* Public */,
      36,    0,  242,    2, 0x0a /* Public */,
      37,    4,  243,    2, 0x0a /* Public */,
      42,    1,  252,    2, 0x0a /* Public */,
      43,    0,  255,    2, 0x0a /* Public */,
      43,    3,  256,    2, 0x0a /* Public */,
      45,    3,  263,    2, 0x0a /* Public */,
      49,    2,  270,    2, 0x0a /* Public */,
      50,    3,  275,    2, 0x0a /* Public */,
      51,    3,  282,    2, 0x0a /* Public */,
      52,    1,  289,    2, 0x0a /* Public */,
      54,    5,  292,    2, 0x0a /* Public */,
      57,    5,  303,    2, 0x0a /* Public */,
      60,    5,  314,    2, 0x0a /* Public */,
      61,    1,  325,    2, 0x08 /* Private */,
      63,    1,  328,    2, 0x08 /* Private */,
      66,    1,  331,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QStringList,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,   20,   21,   22,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,   26,   27,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QJsonArray,   14,   30,   31,   32,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   38,   39,   40,   41,
    QMetaType::Void, QMetaType::QString,   38,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   40,   41,   44,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   46,   47,   48,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   46,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   46,   14,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   46,   14,   30,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   46,   14,   53,   55,   56,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::LongLong,   46,   14,   58,   59,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::LongLong,   46,   14,   58,   59,   31,
    QMetaType::Void, 0x80000000 | 62,   28,
    QMetaType::Void, 0x80000000 | 64,   65,
    QMetaType::Void, QMetaType::QString,   67,

       0        // eod
};

void CortexClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CortexClient *_t = static_cast<CortexClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->queryHeadsetsOk((*reinterpret_cast< const QList<Headset>(*)>(_a[1]))); break;
        case 3: _t->getUserLoginOk((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->loginOk(); break;
        case 5: _t->logoutOk(); break;
        case 6: _t->authorizeOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->createSessionOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->closeSessionOk(); break;
        case 9: _t->subscribeOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->unsubscribeOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->getDetectionInfoOk((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 12: _t->trainingOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->injectMarkerOk(); break;
        case 14: _t->errorReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 15: _t->streamDataReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< const QJsonArray(*)>(_a[4]))); break;
        case 16: _t->open(); break;
        case 17: _t->close(); break;
        case 18: _t->queryHeadsets(); break;
        case 19: _t->getUserLogin(); break;
        case 20: _t->login((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 21: _t->logout((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->authorize(); break;
        case 23: _t->authorize((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 24: _t->createSession((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 25: _t->closeSession((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: _t->subscribe((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 27: _t->unsubscribe((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 28: _t->getDetectionInfo((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->training((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 30: _t->injectMarker((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< qint64(*)>(_a[5]))); break;
        case 31: _t->injectStopMarker((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< qint64(*)>(_a[5]))); break;
        case 32: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 33: _t->onSslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 34: _t->onMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CortexClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(const QList<Headset> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::queryHeadsetsOk)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(const QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::getUserLoginOk)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::loginOk)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::logoutOk)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::authorizeOk)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::createSessionOk)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::closeSessionOk)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::subscribeOk)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::unsubscribeOk)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QStringList , QStringList , QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::getDetectionInfoOk)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::trainingOk)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::injectMarkerOk)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString , int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::errorReceived)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CortexClient::*)(QString , QString , double , const QJsonArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CortexClient::streamDataReceived)) {
                *result = 15;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CortexClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CortexClient.data,
      qt_meta_data_CortexClient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CortexClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CortexClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CortexClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CortexClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void CortexClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CortexClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CortexClient::queryHeadsetsOk(const QList<Headset> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CortexClient::getUserLoginOk(const QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CortexClient::loginOk()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void CortexClient::logoutOk()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void CortexClient::authorizeOk(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CortexClient::createSessionOk(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CortexClient::closeSessionOk()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void CortexClient::subscribeOk(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CortexClient::unsubscribeOk(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CortexClient::getDetectionInfoOk(QStringList _t1, QStringList _t2, QStringList _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CortexClient::trainingOk(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CortexClient::injectMarkerOk()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void CortexClient::errorReceived(QString _t1, int _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void CortexClient::streamDataReceived(QString _t1, QString _t2, double _t3, const QJsonArray & _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
