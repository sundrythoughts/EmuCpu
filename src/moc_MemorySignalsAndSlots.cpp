/****************************************************************************
** Meta object code from reading C++ file 'MemorySignalsAndSlots.hh'
**
** Created: Tue Oct 6 20:53:09 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MemorySignalsAndSlots.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MemorySignalsAndSlots.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MemorySignalsAndSlots[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      32,   23,   22,   22, 0x05,
      67,   64,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   83,   22,   22, 0x0a,
     105,   64,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MemorySignalsAndSlots[] = {
    "MemorySignalsAndSlots\0\0addr,val\0"
    "valueChanged(int,unsigned char)\0sz\0"
    "resized(size_t)\0b\0enableDisable(bool)\0"
    "resize(size_t)\0"
};

const QMetaObject MemorySignalsAndSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MemorySignalsAndSlots,
      qt_meta_data_MemorySignalsAndSlots, 0 }
};

const QMetaObject *MemorySignalsAndSlots::metaObject() const
{
    return &staticMetaObject;
}

void *MemorySignalsAndSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MemorySignalsAndSlots))
        return static_cast<void*>(const_cast< MemorySignalsAndSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int MemorySignalsAndSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< unsigned char(*)>(_a[2]))); break;
        case 1: resized((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 2: enableDisable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: resize((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MemorySignalsAndSlots::valueChanged(int _t1, unsigned char _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MemorySignalsAndSlots::resized(size_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
