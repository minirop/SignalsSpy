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

#ifndef SIGNALIDENTIFIER_H
#define SIGNALIDENTIFIER_H

#include <QObject>
#include <QList>
#include <QByteArray>

// DO NOT MODIFY THIS FILE UNLESS YOU KNOW WHAT YOU'RE DOING !!!!

class SignalIdentifier : public QObject
{
public:
	SignalIdentifier(QObject * object);
	void addSignal(const char * signal);
	
	// ALL QT META OBJECT CRAP. DO NOT TOUCH !!!
	static const QMetaObject staticMetaObject;
	virtual const QMetaObject *metaObject() const;
	virtual void *qt_metacast(const char *);
	static inline QString tr(const char *s, const char *c = 0)
		{ return staticMetaObject.tr(s, c); }
	static inline QString trUtf8(const char *s, const char *c = 0)
		{ return staticMetaObject.trUtf8(s, c); }
	static inline QString tr(const char *s, const char *c, int n)
		{ return staticMetaObject.tr(s, c, n); }
	static inline QString trUtf8(const char *s, const char *c, int n)
		{ return staticMetaObject.trUtf8(s, c, n); }
	virtual int qt_metacall(QMetaObject::Call, int, void **);

signals:
	void hasBeenEmitted(QString);

private:
	QObject * monitoredObj;
	QList<QByteArray> slotList;
};

#endif
