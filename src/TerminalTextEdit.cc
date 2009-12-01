#include "TerminalTextEdit.hh"
#include <iostream>

TerminalTextEdit::TerminalTextEdit (QWidget *parent) : QTextEdit (parent) {
	setReadOnly (true);
	setStyleSheet ("background-color: rgb(0, 0, 0);\n \
	               selection-background-color: rgb(255, 255, 255);\n \
	               color: rgb(255, 255, 255);\n \
	               selection-color: rgb(0, 0, 0);");

	connect (this, SIGNAL(textChanged ()), this, SLOT(scrollToCursor ()));
}

void
TerminalTextEdit::scrollToCursor () {
	ensureCursorVisible ();
}

void
TerminalTextEdit::keyPressEvent (QKeyEvent *key_event) {
	QChar ch = key_event->text ().toAscii ().at (0);
	//std::cout << (unsigned int)ch.toAscii () << std::endl;
	if (ch.isPrint () || ch == '\r' || ch == '\n') {
		//insertPlainText (ch);
		Q_EMIT charTyped (ch.toAscii ());
	}
}

void
TerminalTextEdit::mousePressEvent (QMouseEvent *event) {
	setFocus ();
}

