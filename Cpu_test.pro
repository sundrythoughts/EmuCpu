TARGET = Cpu_test

CONFIG += qt

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

SOURCES += Cpu_test.cc

HEADERS += Cpu.hh
SOURCES += Cpu.cc
