/****************************************************************************
** Meta object code from reading C++ file 'animationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PAD-Engine/animationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'animationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnimationWidget_t {
    QByteArrayData data[10];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimationWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimationWidget_t qt_meta_stringdata_AnimationWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AnimationWidget"
QT_MOC_LITERAL(1, 16, 7), // "updated"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 27), // "on_meshEdit_editingFinished"
QT_MOC_LITERAL(4, 53, 31), // "on_materialEdit_editingFinished"
QT_MOC_LITERAL(5, 85, 27), // "on_animEdit_editingFinished"
QT_MOC_LITERAL(6, 113, 31), // "on_skeletonEdit_editingFinished"
QT_MOC_LITERAL(7, 145, 28), // "on_speedEdit_editingFinished"
QT_MOC_LITERAL(8, 174, 20), // "on_Loop_stateChanged"
QT_MOC_LITERAL(9, 195, 4) // "arg1"

    },
    "AnimationWidget\0updated\0\0"
    "on_meshEdit_editingFinished\0"
    "on_materialEdit_editingFinished\0"
    "on_animEdit_editingFinished\0"
    "on_skeletonEdit_editingFinished\0"
    "on_speedEdit_editingFinished\0"
    "on_Loop_stateChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void AnimationWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimationWidget *_t = static_cast<AnimationWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updated(); break;
        case 1: _t->on_meshEdit_editingFinished(); break;
        case 2: _t->on_materialEdit_editingFinished(); break;
        case 3: _t->on_animEdit_editingFinished(); break;
        case 4: _t->on_skeletonEdit_editingFinished(); break;
        case 5: _t->on_speedEdit_editingFinished(); break;
        case 6: _t->on_Loop_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AnimationWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AnimationWidget::updated)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AnimationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AnimationWidget.data,
      qt_meta_data_AnimationWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AnimationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AnimationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AnimationWidget::updated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
