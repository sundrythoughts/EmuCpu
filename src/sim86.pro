TARGET = sim86

CONFIG += debug

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += Sim86.cc

HEADERS += Cpu.hh
SOURCES += Cpu.cc

HEADERS += ExecutionUnit.hh
SOURCES += ExecutionUnit.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += Loader.hh
SOURCES += Loader.cc

HEADERS += FlagRegisterSignalsAndSlots.hh
SOURCES += FlagRegisterSignalsAndSlots.cc

HEADERS += GeneralRegisterSignalsAndSlots.hh
SOURCES += GeneralRegisterSignalsAndSlots.cc

HEADERS += SegmentRegisterSignalsAndSlots.hh
SOURCES += SegmentRegisterSignalsAndSlots.cc

HEADERS += MemorySignalsAndSlots.hh
SOURCES += MemorySignalsAndSlots.cc

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
