TARGET = Memory_test

CONFIG += debug
CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += Memory_test.cc

HEADERS += Memory.hh
SOURCES += Memory.cc

HEADERS += Number.hh
SOURCES += Number.cc
