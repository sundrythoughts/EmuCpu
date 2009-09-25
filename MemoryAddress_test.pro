TARGET = MemoryAddress_test

CONFIG += debug
CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += MemoryAddress_test.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += Number.hh
SOURCES += Number.cc
