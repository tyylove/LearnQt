/****************************************************************************
** Meta object code from reading C++ file 'AbstractKeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Keyboard/AbstractKeyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AbstractKeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AeaQt__AbstractKeyboard_t {
    QByteArrayData data[8];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AeaQt__AbstractKeyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AeaQt__AbstractKeyboard_t qt_meta_stringdata_AeaQt__AbstractKeyboard = {
    {
QT_MOC_LITERAL(0, 0, 23), // "AeaQt::AbstractKeyboard"
QT_MOC_LITERAL(1, 24, 10), // "keyPressed"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "key"
QT_MOC_LITERAL(4, 40, 5), // "value"
QT_MOC_LITERAL(5, 46, 6), // "update"
QT_MOC_LITERAL(6, 53, 4), // "text"
QT_MOC_LITERAL(7, 58, 12) // "onKeyPressed"

    },
    "AeaQt::AbstractKeyboard\0keyPressed\0\0"
    "key\0value\0update\0text\0onKeyPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AeaQt__AbstractKeyboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   34,    2, 0x0a /* Public */,
       7,    2,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,

       0        // eod
};

void AeaQt::AbstractKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractKeyboard *_t = static_cast<AbstractKeyboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->update((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onKeyPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractKeyboard::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractKeyboard::keyPressed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AeaQt::AbstractKeyboard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AeaQt__AbstractKeyboard.data,
      qt_meta_data_AeaQt__AbstractKeyboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AeaQt::AbstractKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AeaQt::AbstractKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AeaQt__AbstractKeyboard.stringdata0))
        return static_cast<void*>(const_cast< AbstractKeyboard*>(this));
    return QWidget::qt_metacast(_clname);
}

int AeaQt::AbstractKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AeaQt::AbstractKeyboard::keyPressed(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
