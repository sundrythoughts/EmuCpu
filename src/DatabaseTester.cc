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


#include "DatabaseTester.hh"

class DatabaseTesterPrivate {
public:
	syb::LOGINREC *m_login;
	syb::DBPROCESS *m_dbproc;
	syb::RETCODE m_ret;

	DatabaseTesterPrivate () : m_login (0), m_dbproc (0) {
	}
};

DatabaseTester::DatabaseTester () {
	p = new DatabaseTesterPrivate ();
	syb::dbinit ();
}

DatabaseTester::~DatabaseTester () {
	syb::dbexit ();
}

void
DatabaseTester::connect (const QString &server, const QString &db, const QString &uid, const QString &pwd) {
	Q_EMIT connecting ();

	if (p->m_login || p->m_dbproc) {
		//FIXME - already connected
		Q_EMIT connected ();
		return;
	}

	if ((p->m_login = syb::dblogin ()) == 0) {
		//FIXME - no memory
		Q_EMIT error ("Out of memory");
		return;
	}

	syb::DBSETLUSER(p->m_login, uid.toAscii ().data ());
	syb::DBSETLPWD(p->m_login, pwd.toAscii ().data ());

	if ((p->m_dbproc = syb::dbopen (p->m_login, server.toAscii ().data ())) == 0) {
		//FIXME - unable to open database server
		Q_EMIT error ("Unable to open database server");
		return;
	}

	if ((p->m_ret = syb::dbuse (p->m_dbproc, db.toAscii ().data ())) == FAIL) {
		//FIXME - database name doesn't exist on server
		Q_EMIT error ("Database name does not exist");
		return;
	}

	Q_EMIT connected ();
}

void
DatabaseTester::disconnect () {
	if (p->m_dbproc) {
		syb::dbclose (p->m_dbproc);
		p->m_dbproc = 0;
	}

	if (p->m_login) {
		syb::dbloginfree (p->m_login);
		p->m_login = 0;
	}
}

void
DatabaseTester::spChecksumsInsert (const QString &userid, const QString &testid, int regcksum, int ramcksum) {
	syb::dbfcmd (p->m_dbproc, "exec ChecksumsInsert \"%s\", \"%s\", %d, %d", userid.toAscii ().data (), testid.toAscii ().data (), regcksum, ramcksum);
	p->m_ret = syb::dbsqlexec (p->m_dbproc);
}

void
DatabaseTester::run () {
	//FIXME - implement this
}

