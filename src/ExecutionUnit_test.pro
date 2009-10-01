TARGET = ExecutionUnit_test

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += ExecutionUnit_test.cc

HEADERS += ExecutionUnit.hh
SOURCES += ExecutionUnit.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Register.hh
SOURCES += Register.cc

HEADERS += Defines.hh
SOURCES += Defines.cc

HEADERS += Utility.hh
SOURCES += Utility.cc
