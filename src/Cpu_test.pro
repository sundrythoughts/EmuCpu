TARGET = Cpu_test

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += Cpu_test.cc

HEADERS += Cpu.hh
SOURCES += Cpu.cc

HEADERS += ExecutionUnit.hh
SOURCES += ExecutionUnit.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Register.hh
SOURCES += Register.cc

HEADERS += Defines.hh
SOURCES += Defines.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Utility.hh
SOURCES += Utility.cc
