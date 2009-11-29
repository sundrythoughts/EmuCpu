#include "TerminalTextEdit.hh"
#include <iostream>

TerminalTextEdit::TerminalTextEdit (QWidget *parent) : QTextEdit (parent) {
	setReadOnly (true);

	connect (this, SIGNAL(textChanged ()), this, SLOT(scrollToCursor ()));
}

void
TerminalTextEdit::scrollToCursor () {
	ensureCursorVisible ();
}

void
TerminalTextEdit::keyPressEvent (QKeyEvent *key_event) {
	QChar ch = key_event->text ().toAscii ().at (0);
	std::cout << (unsigned int)ch.toAscii () << std::endl;
	//if (ch.isPrint ()) {
		//insertPlainText (ch);
		Q_EMIT charTyped (ch.toAscii ());
	//}
}

