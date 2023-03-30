/****************************************************************************
** Meta object code from reading C++ file 'tileButton.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../tileButton.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tileButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_tileButton_t {
    uint offsetsAndSizes[12];
    char stringdata0[11];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[22];
    char stringdata5[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_tileButton_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_tileButton_t qt_meta_stringdata_tileButton = {
    {
        QT_MOC_LITERAL(0, 10),  // "tileButton"
        QT_MOC_LITERAL(11, 12),  // "rightClicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 11),  // "setIconSlot"
        QT_MOC_LITERAL(37, 21),  // "std::shared_ptr<Tile>"
        QT_MOC_LITERAL(59, 4)   // "tile"
    },
    "tileButton",
    "rightClicked",
    "",
    "setIconSlot",
    "std::shared_ptr<Tile>",
    "tile"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_tileButton[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   27,    2, 0x0a,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject tileButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_tileButton.offsetsAndSizes,
    qt_meta_data_tileButton,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_tileButton_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<tileButton, std::true_type>,
        // method 'rightClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setIconSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>
    >,
    nullptr
} };

void tileButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tileButton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rightClicked(); break;
        case 1: _t->setIconSlot((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (tileButton::*)();
            if (_t _q_method = &tileButton::rightClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *tileButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tileButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tileButton.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<tileButton>"))
        return static_cast< std::enable_shared_from_this<tileButton>*>(this);
    return QPushButton::qt_metacast(_clname);
}

int tileButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void tileButton::rightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
