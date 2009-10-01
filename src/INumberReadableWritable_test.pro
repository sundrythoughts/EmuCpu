TARGET = INumberReadableWritable_test

CONFIG += debug

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += INumberReadableWritable_test.cc

HEADERS += INumberReadableWritable.hh

HEADERS += Immediate.hh
SOURCES += Immediate.cc

HEADERS += Register.hh
SOURCES += Register.cc

HEADERS += MemoryAddress.hh
SOURCES += MemoryAddress.cc

HEADERS += Memory.hh
