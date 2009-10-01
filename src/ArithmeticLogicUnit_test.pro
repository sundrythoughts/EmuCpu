TARGET = ArithmeticLogicUnit_test

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += ArithmeticLogicUnit_test.cc

HEADERS += ArithmeticLogicUnit.hh
SOURCES += ArithmeticLogicUnit.cc

HEADERS += ExecutionUnit.hh
SOURCES += ExecutionUnit.cc

HEADERS += Utility.hh
SOURCES += Utility.cc

HEADERS += Register.hh
SOURCES += Register.cc

HEADERS += BusInterfaceUnit.hh
SOURCES += BusInterfaceUnit.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Defines.hh
SOURCES += Defines.cc
