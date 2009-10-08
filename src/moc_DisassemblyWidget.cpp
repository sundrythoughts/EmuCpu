/****************************************************************************
** Meta object code from reading C++ file 'DisassemblyWidget.hh'
**
** Created: Tue Oct 6 20:53:18 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DisassemblyWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DisassemblyWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DisassemblyWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      21,   19,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DisassemblyWidget[] = {
    "DisassemblyWidget\0\0b\0enableDisableToggle(bool)\0"
};

const QMetaObject DisassemblyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DisassemblyWidget,
      qt_meta_data_DisassemblyWidget, 0 }
};

const QMetaObject *DisassemblyWidget::metaObject() const
{
    return &staticMetaObject;
}

void *DisassemblyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DisassemblyWidget))
        return static_cast<void*>(const_cast< DisassemblyWidget*>(this));
    if (!strcmp(_clname, "Ui::DisassemblyWidget"))
        return static_cast< Ui::DisassemblyWidget*>(const_cast< DisassemblyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DisassemblyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enableDisableToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
