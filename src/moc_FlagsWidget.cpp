/****************************************************************************
** Meta object code from reading C++ file 'FlagsWidget.hh'
**
** Created: Tue Oct 6 20:53:09 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "FlagsWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlagsWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlagsWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x0a,
      43,   41,   12,   12, 0x0a,
      70,   68,   12,   12, 0x0a,
      86,   68,   12,   12, 0x0a,
     102,   68,   12,   12, 0x0a,
     118,   68,   12,   12, 0x0a,
     134,   68,   12,   12, 0x0a,
     150,   68,   12,   12, 0x0a,
     166,   68,   12,   12, 0x0a,
     182,   68,   12,   12, 0x0a,
     198,   68,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FlagsWidget[] = {
    "FlagsWidget\0\0b\0enableDisableToggle(bool)\0"
    "i\0setFlags(unsigned short)\0v\0"
    "setFlagCF(bool)\0setFlagPF(bool)\0"
    "setFlagAF(bool)\0setFlagZF(bool)\0"
    "setFlagSF(bool)\0setFlagTF(bool)\0"
    "setFlagIF(bool)\0setFlagDF(bool)\0"
    "setFlagOF(bool)\0"
};

const QMetaObject FlagsWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_FlagsWidget,
      qt_meta_data_FlagsWidget, 0 }
};

const QMetaObject *FlagsWidget::metaObject() const
{
    return &staticMetaObject;
}

void *FlagsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlagsWidget))
        return static_cast<void*>(const_cast< FlagsWidget*>(this));
    if (!strcmp(_clname, "Ui::FlagsWidget"))
        return static_cast< Ui::FlagsWidget*>(const_cast< FlagsWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int FlagsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enableDisableToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setFlags((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 2: setFlagCF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: setFlagPF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: setFlagAF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: setFlagZF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: setFlagSF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: setFlagTF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: setFlagIF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: setFlagDF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setFlagOF((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
