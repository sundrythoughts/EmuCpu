/*
 * sim8086 -- Emulates an Intel 8086 processor
 * Copyright (C) 2009  Joseph Freeman (jfree143dev AT gmail DOT com)
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef JAF__DATABASE_TESTER_HH
#define JAF__DATABASE_TESTER_HH

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

#endif //JAF__DATABASE_TESTER_HH

