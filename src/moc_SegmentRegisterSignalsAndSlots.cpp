/****************************************************************************
** Meta object code from reading C++ file 'SegmentRegisterSignalsAndSlots.hh'
**
** Created: Tue Oct 6 20:53:08 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SegmentRegisterSignalsAndSlots.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SegmentRegisterSignalsAndSlots.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SegmentRegisterSignalsAndSlots[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      34,   32,   31,   31, 0x05,
      71,   32,   31,   31, 0x05,
     108,   32,   31,   31, 0x05,
     145,   32,   31,   31, 0x05,
     182,   32,   31,   31, 0x05,

 // slots: signature, parameters, type, tag, flags
     218,  216,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SegmentRegisterSignalsAndSlots[] = {
    "SegmentRegisterSignalsAndSlots\0\0i\0"
    "valueChangedSegRegCS(unsigned short)\0"
    "valueChangedSegRegDS(unsigned short)\0"
    "valueChangedSegRegES(unsigned short)\0"
    "valueChangedSegRegSS(unsigned short)\0"
    "valueChangedRegIP(unsigned short)\0b\0"
    "enableDisable(bool)\0"
};

const QMetaObject SegmentRegisterSignalsAndSlots::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SegmentRegisterSignalsAndSlots,
      qt_meta_data_SegmentRegisterSignalsAndSlots, 0 }
};

const QMetaObject *SegmentRegisterSignalsAndSlots::metaObject() const
{
    return &staticMetaObject;
}

void *SegmentRegisterSignalsAndSlots::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SegmentRegisterSignalsAndSlots))
        return static_cast<void*>(const_cast< SegmentRegisterSignalsAndSlots*>(this));
    return QObject::qt_metacast(_clname);
}

int SegmentRegisterSignalsAndSlots::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChangedSegRegCS((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 1: valueChangedSegRegDS((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 2: valueChangedSegRegES((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 3: valueChangedSegRegSS((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 4: valueChangedRegIP((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 5: enableDisable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SegmentRegisterSignalsAndSlots::valueChangedSegRegCS(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SegmentRegisterSignalsAndSlots::valueChangedSegRegDS(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SegmentRegisterSignalsAndSlots::valueChangedSegRegES(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SegmentRegisterSignalsAndSlots::valueChangedSegRegSS(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SegmentRegisterSignalsAndSlots::valueChangedRegIP(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
