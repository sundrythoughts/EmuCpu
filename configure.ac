AC_INIT([sim8086], [0.1], [jfree143dev@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_PROG_CXX

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    data/Makefile
])

AC_DEFINE_DIR([SIM8086_DATADIR], [datadir], [Base data directory])
#AS_AC_EXPAND(PACKAGE_DATADIR, $datadir)
#AC_MSG_NOTICE(Storing data files in $PACKAGE_DATADIR)

PKG_PROG_PKG_CONFIG()
PKG_CHECK_MODULES(QT4, \
                 [QtCore >= 4.0.0 \
                  QtGui  >= 4.0.0 \
                 ],,)

PKG_CHECK_MODULES(SIGC2, \
                 [sigc++-2.0 >= 2.0.0 \
                 ],,)
PKG_CHECK_MODULES(GST, \
                 [gstreamer-0.10 >= 0.10.0 \
                 ],,)

AC_OUTPUT
