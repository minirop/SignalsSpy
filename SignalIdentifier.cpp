////////////////////////////////////////////////////////////
//
// SignalsSpy - A signal identification class
// Copyright (C) 2011 minirop (minirop@peyj.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

// DO NOT MODIFY THIS FILE UNLESS YOU KNOW WHAT YOUR DOING !!!!

#include "SignalIdentifier.h"

SignalIdentifier::SignalIdentifier(QObject * object)
	: monitoredObj(object)
{
}

void SignalIdentifier::addSignal(const char * signal)
{
	QByteArray theSignal = QMetaObject::normalizedSignature(signal);
	QByteArray theSlot = QMetaObject::normalizedSignature("onSignalEmitted()");
	if (!QMetaObject::checkConnectArgs(theSignal, theSlot))
		return;
	
	int signalId = monitoredObj->metaObject()->indexOfSignal(theSignal);
	if (signalId < 0) 
		return;
	
	int slotId = slotList.indexOf(theSignal, -1);
	if (slotId < 0)
	{
		slotId = slotList.size();
		slotList.append(theSignal);
	}
	
	QMetaObject::connect(monitoredObj, signalId, this, slotId);
}

// ALL QT META OBJECT CRAP. DO NOT TOUCH !!!
static const uint qt_meta_data_SignalIdentifier[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SignalIdentifier[] = {
    "SignalIdentifier\0\0hasBeenEmitted(QString)\0"
};

const QMetaObject SignalIdentifier::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SignalIdentifier,
      qt_meta_data_SignalIdentifier, 0 }
};

const QMetaObject *SignalIdentifier::metaObject() const
{
	return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SignalIdentifier::qt_metacast(const char *_clname)
{
	if (!_clname) return 0;
	if (!strcmp(_clname, qt_meta_stringdata_SignalIdentifier))
		return static_cast<void*>(const_cast<SignalIdentifier*>(this));
	return QObject::qt_metacast(_clname);
}

int SignalIdentifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
	if(_id < 0)
		return _id;
	if(_c == QMetaObject::InvokeMetaMethod)
	{
		Q_ASSERT(_id < slotList.size());
		hasBeenEmitted(slotList[_id]);
	}
	return _id;
}

void SignalIdentifier::hasBeenEmitted(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
