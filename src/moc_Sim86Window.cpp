/****************************************************************************
** Meta object code from reading C++ file 'Sim86Window.hh'
**
** Created: Tue Oct 6 20:53:25 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Sim86Window.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sim86Window.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Sim86Window[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      24,   12,   12,   12, 0x05,
      35,   12,   12,   12, 0x05,
      46,   12,   12,   12, 0x05,
      72,   62,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   90,   12,   12, 0x08,
     129,   90,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Sim86Window[] = {
    "Sim86Window\0\0startCpu()\0resetCpu()\0"
    "pauseCpu()\0singleStepCpu()\0file_name\0"
    "loadFile(QString)\0b\0"
    "enableDisableToggleDisassembly(bool)\0"
    "enableDisableToggleMemory(bool)\0"
};

const QMetaObject Sim86Window::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Sim86Window,
      qt_meta_data_Sim86Window, 0 }
};

const QMetaObject *Sim86Window::metaObject() const
{
    return &staticMetaObject;
}

void *Sim86Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Sim86Window))
        return static_cast<void*>(const_cast< Sim86Window*>(this));
    if (!strcmp(_clname, "Ui::Sim86Window"))
        return static_cast< Ui::Sim86Window*>(const_cast< Sim86Window*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Sim86Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startCpu(); break;
        case 1: resetCpu(); break;
        case 2: pauseCpu(); break;
        case 3: singleStepCpu(); break;
        case 4: loadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: enableDisableToggleDisassembly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: enableDisableToggleMemory((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Sim86Window::startCpu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Sim86Window::resetCpu()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Sim86Window::pauseCpu()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Sim86Window::singleStepCpu()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Sim86Window::loadFile(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
