# SignalsSpy

 SignalsSpy allow you to track QObjects' signals emissions. It's the opposite of __QSignalMapper__. Track all signals from a __single__ object.

## installation

 copy the files in the directory of your project, add the file to your `.pro` and enjoy (`qmake` may be necessary).

## constructor

 - __QObject * object__ : the object to monitor and the parent of the SignalsSpy.

## signals

 - __emitted(QString signature)__ : send the signature of the signal that just been emitted, like `"valueChanged(int)"`
 - __emittedNameOnly(QString name)__ : send the name of the signal that just been emitted, like `"valueChanged"`

## example

    QPushButton * button = new QPushButton("click me!");
	SignalsSpy * spy = new SignalsSpy(button);
	connect(spy, SIGNAL(emittedNameOnly(QString)), button, SLOT(setText(QString)));

 When you'll click the button, the displayed text should go through something like : pressed, released, clicked( bool ), clicked
