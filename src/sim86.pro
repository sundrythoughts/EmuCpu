TARGET = sim86

SOURCES += main.cc

FORMS += FlagsWidget.ui
HEADERS += FlagsWidget.hh
SOURCES += FlagsWidget.cc

FORMS += GeneralRegistersWidget.ui
HEADERS += GeneralRegistersWidget.hh
SOURCES += GeneralRegistersWidget.cc

FORMS += SegmentRegistersWidget.ui
HEADERS += SegmentRegistersWidget.hh
SOURCES += SegmentRegistersWidget.cc

FORMS += StackWidget.ui
HEADERS += StackWidget.hh
SOURCES += StackWidget.cc

FORMS += DisassemblyWidget.ui
HEADERS += DisassemblyWidget.hh
SOURCES += DisassemblyWidget.cc

FORMS += MemoryWidget.ui
HEADERS += MemoryWidget.hh
SOURCES += MemoryWidget.cc

FORMS += TerminalWidget.ui
HEADERS += TerminalWidget.hh
SOURCES += TerminalWidget.cc

FORMS += Sim86Window.ui
HEADERS += Sim86Window.hh
SOURCES += Sim86Window.cc
