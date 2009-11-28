DESTDIR = ..
TARGET = sim86

CONFIG += no_keywords

#CONFIG += qt thread debug
CONFIG += qt thread

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

LIBS += -lsybdb

SOURCES += Sim86.cc

HEADERS += ArithmeticLogicUnit.hh
SOURCES += ArithmeticLogicUnit.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Cpu.hh
SOURCES += Cpu.cc

HEADERS += CpuComponents.hh
SOURCES += CpuComponents.cc

HEADERS += DatabaseTester.hh
SOURCES += DatabaseTester.cc

HEADERS += Defines.hh
SOURCES += Defines.cc

HEADERS += DisassemblySignalsAndSlots.hh
SOURCES += DisassemblySignalsAndSlots.cc

FORMS += DisassemblyWidget.ui
HEADERS += DisassemblyWidget.hh
SOURCES += DisassemblyWidget.cc

HEADERS += ExecutionUnit.hh
SOURCES += ExecutionUnit.cc

HEADERS += FlagRegisterSignalsAndSlots.hh
SOURCES += FlagRegisterSignalsAndSlots.cc

FORMS += FlagsWidget.ui
HEADERS += FlagsWidget.hh
SOURCES += FlagsWidget.cc

HEADERS += GeneralRegisterSignalsAndSlots.hh
SOURCES += GeneralRegisterSignalsAndSlots.cc

FORMS += GeneralRegistersWidget.ui
HEADERS += GeneralRegistersWidget.hh
SOURCES += GeneralRegistersWidget.cc

HEADERS += Immediate.hh

HEADERS += Instruction.hh
SOURCES += Instruction.cc

HEADERS += InstructionDecoder.hh
SOURCES += InstructionDecoder.cc

HEADERS += InstructionDisassembly.hh
SOURCES += InstructionDisassembly.cc

#HEADERS += InstructionExecuter.hh

HEADERS += InstructionTable.hh
SOURCES += InstructionTable.cc

HEADERS += INumberReadableWritable.hh

HEADERS += IOPorts.hh
SOURCES += IOPorts.cc

HEADERS += Loader.hh
SOURCES += Loader.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += MemoryAddress.hh

HEADERS += MemorySignalsAndSlots.hh
SOURCES += MemorySignalsAndSlots.cc

FORMS += MemoryWidget.ui
HEADERS += MemoryWidget.hh
SOURCES += MemoryWidget.cc

HEADERS += NumberWrapper.hh
SOURCES += NumberWrapper.cc

HEADERS += OperandList.hh
SOURCES += OperandList.cc

HEADERS += ProxyLayer.hh
SOURCES += ProxyLayer.cc

HEADERS += SegmentRegisterSignalsAndSlots.hh
SOURCES += SegmentRegisterSignalsAndSlots.cc

FORMS += SegmentRegistersWidget.ui
HEADERS += SegmentRegistersWidget.hh
SOURCES += SegmentRegistersWidget.cc

FORMS += Sim86Window.ui
HEADERS += Sim86Window.hh
SOURCES += Sim86Window.cc

HEADERS += StackSignalsAndSlots.hh
SOURCES += StackSignalsAndSlots.cc

FORMS += StackWidget.ui
HEADERS += StackWidget.hh
SOURCES += StackWidget.cc

HEADERS += TerminalSignalsAndSlots.hh
SOURCES += TerminalSignalsAndSlots.cc

FORMS += TerminalWidget.ui
HEADERS += TerminalWidget.hh
SOURCES += TerminalWidget.cc

HEADERS += Utility.hh
SOURCES += Utility.cc

