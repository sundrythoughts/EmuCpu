/****************************************************************************
** Meta object code from reading C++ file 'SegmentRegistersWidget.hh'
**
** Created: Tue Oct 6 20:53:14 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SegmentRegistersWidget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SegmentRegistersWidget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SegmentRegistersWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      26,   24,   23,   23, 0x0a,
      54,   52,   23,   23, 0x0a,
      82,   52,   23,   23, 0x0a,
     110,   52,   23,   23, 0x0a,
     138,   52,   23,   23, 0x0a,
     166,   52,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SegmentRegistersWidget[] = {
    "SegmentRegistersWidget\0\0b\0"
    "enableDisableToggle(bool)\0i\0"
    "setSegRegCS(unsigned short)\0"
    "setSegRegDS(unsigned short)\0"
    "setSegRegES(unsigned short)\0"
    "setSegRegSS(unsigned short)\0"
    "setRegIP(unsigned short)\0"
};

const QMetaObject SegmentRegistersWidget::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_SegmentRegistersWidget,
      qt_meta_data_SegmentRegistersWidget, 0 }
};

const QMetaObject *SegmentRegistersWidget::metaObject() const
{
    return &staticMetaObject;
}

void *SegmentRegistersWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SegmentRegistersWidget))
        return static_cast<void*>(const_cast< SegmentRegistersWidget*>(this));
    if (!strcmp(_clname, "Ui::SegmentRegistersWidget"))
        return static_cast< Ui::SegmentRegistersWidget*>(const_cast< SegmentRegistersWidget*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int SegmentRegistersWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: enableDisableToggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: setSegRegCS((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 2: setSegRegDS((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 3: setSegRegES((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 4: setSegRegSS((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 5: setRegIP((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
