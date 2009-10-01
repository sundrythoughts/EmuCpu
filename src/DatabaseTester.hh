#ifndef DATABASE_TESTER_HH
#define DATABASE_TESTER_HH

#include <QObject>

namespace syb {
#include <sybdb.h>
}

class DatabaseTester : public Runnable {
	Q_OBJECT

	syb::LOGINREC *m_login;
	syb::DBPROCESS *m_dbproc;
	syb::RETCODE m_ret;

public:
	DatabaseTester () : m_login (0), m_dbproc (0) {
		syb::dbinit ();
	}

	virtual ~DatabaseTester () {
		syb::dbexit ();
	}

public slots:
	void connect (const QString &server, const QString &db, const QString &uid, const QString &pwd);
	void disconnect ();

	void spChecksumsInsert (const QString &userid, const QString &testid, int regcksum, int ramcksum);

signals:
	void error (QString err);

	void connecting ();
	void connected ();

	void disconnecting ();
	void disconnected ();
};

#endif //DATABASE_TESTER_HH

