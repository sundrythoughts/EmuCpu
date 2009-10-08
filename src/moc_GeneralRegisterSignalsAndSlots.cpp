/****************************************************************************
** Meta object code from reading C++ file 'GeneralRegisterSignalsAndSlots.hh'
**
** Created: Tue Oct 6 20:53:08 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GeneralRegisterSignalsAndSlots.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneralRegisterSignalsAndSlots.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneralRegisterSignalsAndSlots[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      34,   32,   31,   31, 0x05,
      68,   32,   31,   31, 0x05,
     102,   32,   31,   31, 0x05,
     136,   32,   31,   31, 0x05,
     170,   32,   31,   31, 0x05,
     204,   32,   31,   31, 0x05,
     238,   32,   31,   31, 0x05,
     272,   32,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     308,  306,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneralRegisterSignalsAndSlots[] = {
    "GeneralRegisterSignalsAndSlots\0\0i\0"
    "valueChangedRegAX(unsigned short)\0"
    "valueChangedRegBX(unsigned short)\0"
    "valueChangedRegCX(unsigned short)\0"
    "valueChangedRegDX(unsigned short)\0"
    "valueChangedRegSI(unsigned short)\0"
    "valueChangedRegDI(unsigned short)\0"
    "valueChangedRegBP(unsigned short)\0"
    "valueChangedRegSP(unsigned short)\0b\0"
    "enableDisable(bool)\0"
};

const QMetaObject GeneralRegisterSignalsAndSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeneralRegisterSignalsAndSlots,
      qt_meta_data_GeneralRegisterSignalsAndSlots, 0 }
};

const QMetaObject *GeneralRegisterSignalsAndSlots::metaObject() const
{
    return &staticMetaObject;
}

void *GeneralRegisterSignalsAndSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralRegisterSignalsAndSlots))
        return static_cast<void*>(const_cast< GeneralRegisterSignalsAndSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int GeneralRegisterSignalsAndSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChangedRegAX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 1: valueChangedRegBX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 2: valueChangedRegCX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 3: valueChangedRegDX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 4: valueChangedRegSI((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 5: valueChangedRegDI((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 6: valueChangedRegBP((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 7: valueChangedRegSP((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 8: enableDisable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GeneralRegisterSignalsAndSlots::valueChangedRegAX(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GeneralRegisterSignalsAndSlots::valueChangedRegBX(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GeneralRegisterSignalsAndSlots::valueChangedRegCX(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GeneralRegisterSignalsAndSlots::valueChangedRegDX(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GeneralRegisterSignalsAndSlots::valueChangedRegSI(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GeneralRegisterSignalsAndSlots::valueChangedRegDI(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GeneralRegisterSignalsAndSlots::valueChangedRegBP(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GeneralRegisterSignalsAndSlots::valueChangedRegSP(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
