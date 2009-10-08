/****************************************************************************
** Meta object code from reading C++ file 'GeneralRegistersWidget.hh'
**
** Created: Tue Oct 6 20:53:12 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GeneralRegistersWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeneralRegistersWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeneralRegistersWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      26,   24,   23,   23, 0x0a,
      54,   52,   23,   23, 0x0a,
      79,   52,   23,   23, 0x0a,
     104,   52,   23,   23, 0x0a,
     129,   52,   23,   23, 0x0a,
     154,   52,   23,   23, 0x0a,
     179,   52,   23,   23, 0x0a,
     204,   52,   23,   23, 0x0a,
     229,   52,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeneralRegistersWidget[] = {
    "GeneralRegistersWidget\0\0b\0"
    "enableDisableToggle(bool)\0i\0"
    "setRegAX(unsigned short)\0"
    "setRegBX(unsigned short)\0"
    "setRegCX(unsigned short)\0"
    "setRegDX(unsigned short)\0"
    "setRegSI(unsigned short)\0"
    "setRegDI(unsigned short)\0"
    "setRegBP(unsigned short)\0"
    "setRegSP(unsigned short)\0"
};

const QMetaObject GeneralRegistersWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_GeneralRegistersWidget,
      qt_meta_data_GeneralRegistersWidget, 0 }
};

const QMetaObject *GeneralRegistersWidget::metaObject() const
{
    return &staticMetaObject;
}

void *GeneralRegistersWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeneralRegistersWidget))
        return static_cast<void*>(const_cast< GeneralRegistersWidget*>(this));
    if (!strcmp(_clname, "Ui::GeneralRegistersWidget"))
        return static_cast< Ui::GeneralRegistersWidget*>(const_cast< GeneralRegistersWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int GeneralRegistersWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enableDisableToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setRegAX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 2: setRegBX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 3: setRegCX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 4: setRegDX((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 5: setRegSI((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 6: setRegDI((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 7: setRegBP((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 8: setRegSP((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
