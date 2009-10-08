/****************************************************************************
** Meta object code from reading C++ file 'FlagRegisterSignalsAndSlots.hh'
**
** Created: Tue Oct 6 20:53:07 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FlagRegisterSignalsAndSlots.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlagRegisterSignalsAndSlots.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlagRegisterSignalsAndSlots[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      31,   29,   28,   28, 0x05,
      67,   65,   28,   28, 0x05,
      92,   65,   28,   28, 0x05,
     117,   65,   28,   28, 0x05,
     142,   65,   28,   28, 0x05,
     167,   65,   28,   28, 0x05,
     192,   65,   28,   28, 0x05,
     217,   65,   28,   28, 0x05,
     242,   65,   28,   28, 0x05,
     267,   65,   28,   28, 0x05,

 // slots: signature, parameters, type, tag, flags
     292,   65,   28,   28, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FlagRegisterSignalsAndSlots[] = {
    "FlagRegisterSignalsAndSlots\0\0i\0"
    "valueChangedFlags(unsigned short)\0b\0"
    "valueChangedFlagAF(bool)\0"
    "valueChangedFlagCF(bool)\0"
    "valueChangedFlagDF(bool)\0"
    "valueChangedFlagIF(bool)\0"
    "valueChangedFlagOF(bool)\0"
    "valueChangedFlagPF(bool)\0"
    "valueChangedFlagSF(bool)\0"
    "valueChangedFlagTF(bool)\0"
    "valueChangedFlagZF(bool)\0enableDisable(bool)\0"
};

const QMetaObject FlagRegisterSignalsAndSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FlagRegisterSignalsAndSlots,
      qt_meta_data_FlagRegisterSignalsAndSlots, 0 }
};

const QMetaObject *FlagRegisterSignalsAndSlots::metaObject() const
{
    return &staticMetaObject;
}

void *FlagRegisterSignalsAndSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlagRegisterSignalsAndSlots))
        return static_cast<void*>(const_cast< FlagRegisterSignalsAndSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int FlagRegisterSignalsAndSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChangedFlags((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 1: valueChangedFlagAF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: valueChangedFlagCF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: valueChangedFlagDF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: valueChangedFlagIF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: valueChangedFlagOF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: valueChangedFlagPF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: valueChangedFlagSF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: valueChangedFlagTF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: valueChangedFlagZF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: enableDisable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void FlagRegisterSignalsAndSlots::valueChangedFlags(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FlagRegisterSignalsAndSlots::valueChangedFlagAF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FlagRegisterSignalsAndSlots::valueChangedFlagCF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FlagRegisterSignalsAndSlots::valueChangedFlagDF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FlagRegisterSignalsAndSlots::valueChangedFlagIF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FlagRegisterSignalsAndSlots::valueChangedFlagOF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FlagRegisterSignalsAndSlots::valueChangedFlagPF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void FlagRegisterSignalsAndSlots::valueChangedFlagSF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void FlagRegisterSignalsAndSlots::valueChangedFlagTF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void FlagRegisterSignalsAndSlots::valueChangedFlagZF(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
