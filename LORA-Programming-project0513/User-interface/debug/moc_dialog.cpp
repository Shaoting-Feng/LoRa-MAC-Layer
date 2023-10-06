/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[16];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 18), // "on_btnOpen_clicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 23), // "on_SerialPort_readyRead"
QT_MOC_LITERAL(4, 51, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(5, 70, 21), // "on_btnDomain6_clicked"
QT_MOC_LITERAL(6, 92, 14), // "recvConfigText"
QT_MOC_LITERAL(7, 107, 10), // "ConfigInfo"
QT_MOC_LITERAL(8, 118, 26), // "on_btnClearReceive_clicked"
QT_MOC_LITERAL(9, 145, 23), // "on_btnClearSend_clicked"
QT_MOC_LITERAL(10, 169, 22), // "on_btnDomain10_clicked"
QT_MOC_LITERAL(11, 192, 22), // "on_btnDomain11_clicked"
QT_MOC_LITERAL(12, 215, 22), // "on_btnDomain12_clicked"
QT_MOC_LITERAL(13, 238, 22), // "on_btnDomain13_clicked"
QT_MOC_LITERAL(14, 261, 22), // "on_btnDomain14_clicked"
QT_MOC_LITERAL(15, 284, 23) // "on_EndConfigBtn_clicked"

    },
    "Dialog\0on_btnOpen_clicked\0\0"
    "on_SerialPort_readyRead\0on_btnSend_clicked\0"
    "on_btnDomain6_clicked\0recvConfigText\0"
    "ConfigInfo\0on_btnClearReceive_clicked\0"
    "on_btnClearSend_clicked\0on_btnDomain10_clicked\0"
    "on_btnDomain11_clicked\0on_btnDomain12_clicked\0"
    "on_btnDomain13_clicked\0on_btnDomain14_clicked\0"
    "on_EndConfigBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnOpen_clicked(); break;
        case 1: _t->on_SerialPort_readyRead(); break;
        case 2: _t->on_btnSend_clicked(); break;
        case 3: _t->on_btnDomain6_clicked(); break;
        case 4: _t->recvConfigText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_btnClearReceive_clicked(); break;
        case 6: _t->on_btnClearSend_clicked(); break;
        case 7: _t->on_btnDomain10_clicked(); break;
        case 8: _t->on_btnDomain11_clicked(); break;
        case 9: _t->on_btnDomain12_clicked(); break;
        case 10: _t->on_btnDomain13_clicked(); break;
        case 11: _t->on_btnDomain14_clicked(); break;
        case 12: _t->on_EndConfigBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog.data,
      qt_meta_data_Dialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(const_cast< Dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
