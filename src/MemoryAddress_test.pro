TARGET = MemoryAddress_test

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += MemoryAddress_test.cc

HEADERS += INumberReadableWritable.hh

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Memory.hh
SOURCES += Memory.cc
