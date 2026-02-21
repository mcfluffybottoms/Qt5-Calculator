/****************************************************************************
** Meta object code from reading C++ file 'CalculatorWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/CalculatorWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalculatorWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorWindow_t {
    QByteArrayData data[17];
    char stringdata0[250];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorWindow_t qt_meta_stringdata_CalculatorWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CalculatorWindow"
QT_MOC_LITERAL(1, 17, 18), // "displayTextChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 17), // "answerTextChanged"
QT_MOC_LITERAL(4, 55, 15), // "passwordEntered"
QT_MOC_LITERAL(5, 71, 17), // "handleNumberClick"
QT_MOC_LITERAL(6, 89, 6), // "suffix"
QT_MOC_LITERAL(7, 96, 14), // "handleOperator"
QT_MOC_LITERAL(8, 111, 2), // "op"
QT_MOC_LITERAL(9, 114, 11), // "handleClear"
QT_MOC_LITERAL(10, 126, 19), // "handleBracketChange"
QT_MOC_LITERAL(11, 146, 16), // "handleSignChange"
QT_MOC_LITERAL(12, 163, 12), // "handleSolver"
QT_MOC_LITERAL(13, 176, 24), // "enableWaitingForPassword"
QT_MOC_LITERAL(14, 201, 25), // "disableWaitingForPassword"
QT_MOC_LITERAL(15, 227, 11), // "displayText"
QT_MOC_LITERAL(16, 239, 10) // "answerText"

    },
    "CalculatorWindow\0displayTextChanged\0"
    "\0answerTextChanged\0passwordEntered\0"
    "handleNumberClick\0suffix\0handleOperator\0"
    "op\0handleClear\0handleBracketChange\0"
    "handleSignChange\0handleSolver\0"
    "enableWaitingForPassword\0"
    "disableWaitingForPassword\0displayText\0"
    "answerText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       2,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   72,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,
       9,    0,   78,    2, 0x0a /* Public */,
      10,    0,   79,    2, 0x0a /* Public */,
      11,    0,   80,    2, 0x0a /* Public */,
      12,    0,   81,    2, 0x0a /* Public */,
      13,    0,   82,    2, 0x0a /* Public */,
      14,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void CalculatorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->displayTextChanged(); break;
        case 1: _t->answerTextChanged(); break;
        case 2: _t->passwordEntered(); break;
        case 3: _t->handleNumberClick((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->handleOperator((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->handleClear(); break;
        case 6: _t->handleBracketChange(); break;
        case 7: _t->handleSignChange(); break;
        case 8: _t->handleSolver(); break;
        case 9: _t->enableWaitingForPassword(); break;
        case 10: _t->disableWaitingForPassword(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalculatorWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalculatorWindow::displayTextChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CalculatorWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalculatorWindow::answerTextChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CalculatorWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalculatorWindow::passwordEntered)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CalculatorWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->displayText(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->answerText(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<CalculatorWindow *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDisplayText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setAnswerText(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject CalculatorWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CalculatorWindow.data,
    qt_meta_data_CalculatorWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalculatorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CalculatorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CalculatorWindow::displayTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CalculatorWindow::answerTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CalculatorWindow::passwordEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
