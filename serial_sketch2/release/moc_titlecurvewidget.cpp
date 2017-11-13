/****************************************************************************
** Meta object code from reading C++ file 'titlecurvewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../titlecurvewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'titlecurvewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TitleCurveWidget_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TitleCurveWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TitleCurveWidget_t qt_meta_stringdata_TitleCurveWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TitleCurveWidget"
QT_MOC_LITERAL(1, 17, 11), // "appendValue"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "value"
QT_MOC_LITERAL(4, 36, 8), // "setTitle"
QT_MOC_LITERAL(5, 45, 8), // "strTitle"
QT_MOC_LITERAL(6, 54, 12), // "setYMaxValue"
QT_MOC_LITERAL(7, 67, 8) // "maxValue"

    },
    "TitleCurveWidget\0appendValue\0\0value\0"
    "setTitle\0strTitle\0setYMaxValue\0maxValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TitleCurveWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void TitleCurveWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TitleCurveWidget *_t = static_cast<TitleCurveWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->appendValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setYMaxValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TitleCurveWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TitleCurveWidget.data,
      qt_meta_data_TitleCurveWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TitleCurveWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TitleCurveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TitleCurveWidget.stringdata0))
        return static_cast<void*>(const_cast< TitleCurveWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TitleCurveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
