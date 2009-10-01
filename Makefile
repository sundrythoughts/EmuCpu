#############################################################################
# Makefile for building: ExecutionUnit_test
# Generated by qmake (2.01a) (Qt 4.5.0) on: Wed Sep 30 20:46:13 2009
# Project:  ExecutionUnit_test.pro
# Template: app
# Command: /usr/bin/qmake -unix -o Makefile ExecutionUnit_test.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -I/usr/include/sigc++-2.0 -I/usr/lib/sigc++-2.0/include -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lsigc-2.0 -lQtGui -lQtCore -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ExecutionUnit_test.cc \
		ExecutionUnit.cc \
		BusInterfaceUnit.cc \
		Memory.cc \
		MemoryAddress.cc \
		Number.cc \
		Defines.cc \
		Utility.cc 
OBJECTS       = ExecutionUnit_test.o \
		ExecutionUnit.o \
		BusInterfaceUnit.o \
		Memory.o \
		MemoryAddress.o \
		Number.o \
		Defines.o \
		Utility.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		ExecutionUnit_test.pro
QMAKE_TARGET  = ExecutionUnit_test
DESTDIR       = 
TARGET        = ExecutionUnit_test

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ExecutionUnit_test.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/link_pkgconfig.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile ExecutionUnit_test.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/link_pkgconfig.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile ExecutionUnit_test.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/ExecutionUnit_test1.0.0 || $(MKDIR) .tmp/ExecutionUnit_test1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/ExecutionUnit_test1.0.0/ && $(COPY_FILE) --parents ExecutionUnit.hh BusInterfaceUnit.hh Memory.hh MemoryAddress.hh Number.hh Defines.hh Utility.hh .tmp/ExecutionUnit_test1.0.0/ && $(COPY_FILE) --parents ExecutionUnit_test.cc ExecutionUnit.cc BusInterfaceUnit.cc Memory.cc MemoryAddress.cc Number.cc Defines.cc Utility.cc .tmp/ExecutionUnit_test1.0.0/ && (cd `dirname .tmp/ExecutionUnit_test1.0.0` && $(TAR) ExecutionUnit_test1.0.0.tar ExecutionUnit_test1.0.0 && $(COMPRESS) ExecutionUnit_test1.0.0.tar) && $(MOVE) `dirname .tmp/ExecutionUnit_test1.0.0`/ExecutionUnit_test1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/ExecutionUnit_test1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

ExecutionUnit_test.o: ExecutionUnit_test.cc ExecutionUnit.hh \
		BusInterfaceUnit.hh \
		Memory.hh \
		INumberReadableWritable.hh \
		MemoryAddress.hh \
		Defines.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ExecutionUnit_test.o ExecutionUnit_test.cc

ExecutionUnit.o: ExecutionUnit.cc ExecutionUnit.hh \
		BusInterfaceUnit.hh \
		Memory.hh \
		INumberReadableWritable.hh \
		MemoryAddress.hh \
		Defines.hh \
		Utility.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ExecutionUnit.o ExecutionUnit.cc

BusInterfaceUnit.o: BusInterfaceUnit.cc BusInterfaceUnit.hh \
		Memory.hh \
		INumberReadableWritable.hh \
		MemoryAddress.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BusInterfaceUnit.o BusInterfaceUnit.cc

Memory.o: Memory.cc Memory.hh \
		INumberReadableWritable.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Memory.o Memory.cc

MemoryAddress.o: MemoryAddress.cc MemoryAddress.hh \
		Memory.hh \
		INumberReadableWritable.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MemoryAddress.o MemoryAddress.cc

Number.o: Number.cc 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Number.o Number.cc

Defines.o: Defines.cc Defines.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Defines.o Defines.cc

Utility.o: Utility.cc Utility.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Utility.o Utility.cc

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

