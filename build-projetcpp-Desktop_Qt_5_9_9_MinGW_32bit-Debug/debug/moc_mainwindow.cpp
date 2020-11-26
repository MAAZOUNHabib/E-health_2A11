/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projetcpp/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[394];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 22), // "on_tableView_activated"
QT_MOC_LITERAL(4, 57, 5), // "index"
QT_MOC_LITERAL(5, 63, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 87, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 111, 17), // "on_pb_ok1_clicked"
QT_MOC_LITERAL(8, 129, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(9, 153, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(10, 177, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(11, 199, 4), // "arg1"
QT_MOC_LITERAL(12, 204, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(13, 228, 19), // "on_pb_ok1_2_clicked"
QT_MOC_LITERAL(14, 248, 23), // "on_pushButton_9_clicked"
QT_MOC_LITERAL(15, 272, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(16, 296, 24), // "on_tableView_2_activated"
QT_MOC_LITERAL(17, 321, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(18, 345, 23), // "on_comboBox_2_activated"
QT_MOC_LITERAL(19, 369, 24) // "on_pushButton_10_clicked"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_tableView_activated\0index\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pb_ok1_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_5_clicked\0on_comboBox_activated\0"
    "arg1\0on_pushButton_6_clicked\0"
    "on_pb_ok1_2_clicked\0on_pushButton_9_clicked\0"
    "on_pushButton_7_clicked\0"
    "on_tableView_2_activated\0"
    "on_pushButton_8_clicked\0on_comboBox_2_activated\0"
    "on_pushButton_10_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    1,  103,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    1,  110,    2, 0x08 /* Private */,
      17,    0,  113,    2, 0x08 /* Private */,
      18,    1,  114,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_tableView_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pb_ok1_clicked(); break;
        case 5: _t->on_pushButton_4_clicked(); break;
        case 6: _t->on_pushButton_5_clicked(); break;
        case 7: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_6_clicked(); break;
        case 9: _t->on_pb_ok1_2_clicked(); break;
        case 10: _t->on_pushButton_9_clicked(); break;
        case 11: _t->on_pushButton_7_clicked(); break;
        case 12: _t->on_tableView_2_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_pushButton_8_clicked(); break;
        case 14: _t->on_comboBox_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_pushButton_10_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
