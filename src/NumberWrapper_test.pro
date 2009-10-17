TARGET = NumberWrapper_test

CONFIG += debug

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += NumberWrapper_test.cc

HEADERS += NumberWrapper.hh
SOURCES += NumberWrapper.cc

HEADERS += INumberReadableWritable.hh

HEADERS += Register.hh
SOURCES += Register.cc

HEADERS += Immediate.hh
SOURCES += Immediate.cc
