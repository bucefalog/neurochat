/****************************************************************************
** Meta object code from reading C++ file 'BCIDataStream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BCIClassifier2/BCIDataStream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BCIDataStream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BCIDataStream_t {
    QByteArrayData data[23];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BCIDataStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BCIDataStream_t qt_meta_stringdata_BCIDataStream = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BCIDataStream"
QT_MOC_LITERAL(1, 14, 11), // "onConnected"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "onDisconnected"
QT_MOC_LITERAL(4, 42, 15), // "onErrorReceived"
QT_MOC_LITERAL(5, 58, 6), // "method"
QT_MOC_LITERAL(6, 65, 4), // "code"
QT_MOC_LITERAL(7, 70, 5), // "error"
QT_MOC_LITERAL(8, 76, 15), // "onHeadsetsFound"
QT_MOC_LITERAL(9, 92, 14), // "QList<Headset>"
QT_MOC_LITERAL(10, 107, 8), // "headsets"
QT_MOC_LITERAL(11, 116, 16), // "onSessionCreated"
QT_MOC_LITERAL(12, 133, 5), // "token"
QT_MOC_LITERAL(13, 139, 9), // "sessionId"
QT_MOC_LITERAL(14, 149, 13), // "onSubscribeOk"
QT_MOC_LITERAL(15, 163, 3), // "sid"
QT_MOC_LITERAL(16, 167, 15), // "onUnsubscribeOk"
QT_MOC_LITERAL(17, 183, 3), // "msg"
QT_MOC_LITERAL(18, 187, 20), // "onStreamDataReceived"
QT_MOC_LITERAL(19, 208, 6), // "stream"
QT_MOC_LITERAL(20, 215, 4), // "time"
QT_MOC_LITERAL(21, 220, 4), // "data"
QT_MOC_LITERAL(22, 225, 16) // "onCloseSessionOk"

    },
    "BCIDataStream\0onConnected\0\0onDisconnected\0"
    "onErrorReceived\0method\0code\0error\0"
    "onHeadsetsFound\0QList<Headset>\0headsets\0"
    "onSessionCreated\0token\0sessionId\0"
    "onSubscribeOk\0sid\0onUnsubscribeOk\0msg\0"
    "onStreamDataReceived\0stream\0time\0data\0"
    "onCloseSessionOk"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BCIDataStream[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    3,   61,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,
      11,    2,   71,    2, 0x08 /* Private */,
      14,    1,   76,    2, 0x08 /* Private */,
      16,    1,   79,    2, 0x08 /* Private */,
      18,    4,   82,    2, 0x08 /* Private */,
      22,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QJsonArray,   13,   19,   20,   21,
    QMetaType::Void,

       0        // eod
};

void BCIDataStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BCIDataStream *_t = static_cast<BCIDataStream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onConnected(); break;
        case 1: _t->onDisconnected(); break;
        case 2: _t->onErrorReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->onHeadsetsFound((*reinterpret_cast< const QList<Headset>(*)>(_a[1]))); break;
        case 4: _t->onSessionCreated((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->onSubscribeOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onUnsubscribeOk((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onStreamDataReceived((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< const QJsonArray(*)>(_a[4]))); break;
        case 8: _t->onCloseSessionOk(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BCIDataStream::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BCIDataStream.data,
      qt_meta_data_BCIDataStream,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BCIDataStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BCIDataStream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BCIDataStream.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BCIDataStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
