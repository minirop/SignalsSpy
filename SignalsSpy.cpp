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

#include "SignalsSpy.h"
#include <QMetaObject>
#include <QMetaMethod>

SignalsSpy::SignalsSpy(QObject * object)
	: QObject(object), signalIdentifier(object)
{
	const QMetaObject * metaObject = object->metaObject();
	for(int i = 0;i < metaObject->methodCount();i++)
	{
		QMetaMethod method = metaObject->method(i);
		if(method.methodType() == QMetaMethod::Signal)
		{
			signalIdentifier.addSignal(method.signature());
		}
	}
	connect(&signalIdentifier, SIGNAL(hasBeenEmitted(QString)), this, SLOT(onSignalCalled(QString)));
}

void SignalsSpy::onSignalCalled(QString signature)
{
	emit emitted(signature);
	emit emittedNameOnly(signature.left(signature.indexOf("(")));
}
