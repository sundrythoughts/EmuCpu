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

#include <QThread>
#include <string>

namespace syb {
#include <sybdb.h>
}

class CpuComponents;
class DatabaseTesterPrivate;

class DatabaseTester {
	DatabaseTesterPrivate *p;

public:
	/** */
	DatabaseTester ();

	/** */
	virtual ~DatabaseTester ();

public:
	/** */
	void connectTo (CpuComponents &cpu);

	/**
	@brief Connect to the database.
	@param server Server name.
	@param db Database name.
	@param uid User name.
	@param pwd Password.
	*/
	void connect (const QString &server = "css.cs.bju.edu", const QString &db = "sim86",
	              const QString &uid = "sim86", const QString &pwd = "sim86fall2009");

	/** Disconnect from the database. */
	void disconnect ();

	/** */
	bool isConnected ();

	/**
	@brief Execute the ChecksumsInsert stored procedure.
	@param userid User ID of to use.
	@param testid Name of the file being executed.
	@param regcksum Checksum of the registers.
	@param ramcksum Checksum of the Memory.
	*/
	void spChecksumsInsert (const QString &userid, const QString &testid, int regcksum, int ramcksum);

	/**
	@param userid UserID nvarchar(50): Your login ID
	@param testid TestID nvarchar(50): The name of the test routine being run (e.g. "test1.obj")
	*/
	void spExecInsert (const std::string &userid, const std::string &testid);

	/** An error has occured. */
	void error (QString err);

	/** Connecting to database. */
	void connecting ();

	/** Connection to database has been achieved. */
	void connected ();

	/** Disconnecting from database. */
	void disconnecting ();

	/** Connection to database has been terminated. */
	void disconnected ();
};

#endif //JAF__DATABASE_TESTER_HH

