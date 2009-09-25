TARGET = InstructionDecoder_test

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += InstructionDecoder_test.cc

HEADERS += InstructionDecoder.hh
SOURCES += InstructionDecoder.cc

HEADERS += ExecutionUnit.hh
SOURCES += ExecutionUnit.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Instructions.hh
SOURCES += Instructions.cc

HEADERS += Defines.hh
SOURCES += Defines.cc

HEADERS += Number.hh
SOURCES += Number.cc

HEADERS += Utility.hh
SOURCES += Utility.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc
