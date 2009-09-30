TARGET = main

CONFIG += link_pkgconfig
PKGCONFIG += sigc++-2.0

CONFIG += qt

HEADERS += INumberReadable.hh
HEADERS += INumberWritable.hh
HEADERS += INumberReadableWritable.hh
HEADERS += Number.hh
SOURCES += main.cc
