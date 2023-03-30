/****************************************************************************
** Meta object code from reading C++ file 'tile.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../tile.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tile.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_Tile_t {
    uint offsetsAndSizes[18];
    char stringdata0[5];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[5];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[11];
    char stringdata8[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Tile_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Tile_t qt_meta_stringdata_Tile = {
    {
        QT_MOC_LITERAL(0, 4),  // "Tile"
        QT_MOC_LITERAL(5, 11),  // "iconUpdated"
        QT_MOC_LITERAL(17, 0),  // ""
        QT_MOC_LITERAL(18, 21),  // "std::shared_ptr<Tile>"
        QT_MOC_LITERAL(40, 4),  // "tile"
        QT_MOC_LITERAL(45, 11),  // "flagToggled"
        QT_MOC_LITERAL(57, 11),  // "tileClicked"
        QT_MOC_LITERAL(69, 10),  // "toggleFlag"
        QT_MOC_LITERAL(80, 10)   // "revealSlot"
    },
    "Tile",
    "iconUpdated",
    "",
    "std::shared_ptr<Tile>",
    "tile",
    "flagToggled",
    "tileClicked",
    "toggleFlag",
    "revealSlot"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Tile[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x06,    1 /* Public */,
       5,    1,   47,    2, 0x06,    3 /* Public */,
       6,    1,   50,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   53,    2, 0x0a,    7 /* Public */,
       8,    0,   54,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Tile::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Tile.offsetsAndSizes,
    qt_meta_data_Tile,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Tile_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Tile, std::true_type>,
        // method 'iconUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'flagToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'tileClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<Tile>, std::false_type>,
        // method 'toggleFlag'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'revealSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Tile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->iconUpdated((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 1: _t->flagToggled((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 2: _t->tileClicked((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<Tile>>>(_a[1]))); break;
        case 3: _t->toggleFlag(); break;
        case 4: _t->revealSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::iconUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::flagToggled; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tile::*)(std::shared_ptr<Tile> );
            if (_t _q_method = &Tile::tileClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tile.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "std::enable_shared_from_this<Tile>"))
        return static_cast< std::enable_shared_from_this<Tile>*>(this);
    return QObject::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tile::iconUpdated(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tile::flagToggled(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tile::tileClicked(std::shared_ptr<Tile> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
