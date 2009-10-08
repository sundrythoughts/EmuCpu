/****************************************************************************
** Meta object code from reading C++ file 'Cpu.hh'
**
** Created: Tue Oct 6 21:01:17 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Cpu.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Cpu.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Cpu[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      16,    4,    4,    4, 0x0a,
      27,    4,    4,    4, 0x0a,
      38,    4,    4,    4, 0x0a,
      64,   54,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Cpu[] = {
    "Cpu\0\0startCpu()\0pauseCpu()\0resetCpu()\0"
    "singleStepCpu()\0file_name\0loadFile(QString)\0"
};

const QMetaObject Cpu::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Cpu,
      qt_meta_data_Cpu, 0 }
};

const QMetaObject *Cpu::metaObject() const
{
    return &staticMetaObject;
}

void *Cpu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cpu))
        return static_cast<void*>(const_cast< Cpu*>(this));
    return QThread::qt_metacast(_clname);
}

int Cpu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startCpu(); break;
        case 1: pauseCpu(); break;
        case 2: resetCpu(); break;
        case 3: singleStepCpu(); break;
        case 4: loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
