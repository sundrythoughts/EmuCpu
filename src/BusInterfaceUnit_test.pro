TARGET = BusInterfaceUnit_test

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += BusInterfaceUnit_test.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Register.hh
SOURCES += Register.cc
