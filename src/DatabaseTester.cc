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

#include "CpuComponents.hh"
#include "ExecutionUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Instruction.hh"

#include <iostream>

class DatabaseTesterPrivate {
public:
	CpuComponents *m_cpu_comps;
	ExecutionUnit *m_eunit;
	BusInterfaceUnit *m_biu;
	Instruction *m_inst;

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
	delete p;
}

void
DatabaseTester::connectTo (CpuComponents &cpu) {
	p->m_cpu_comps = &cpu;
	p->m_eunit = &cpu.getExecutionUnit ();
	p->m_biu = &cpu.getBusInterfaceUnit ();
	p->m_inst = &cpu.getInstruction ();
}

void
DatabaseTester::connect (const QString &server, const QString &db, const QString &uid, const QString &pwd) {
	if (isConnected ()) {
		//FIXME - already connected
		std::cerr << "DEBUG: already connected" << std::endl;
		return;
	}

	if ((p->m_login = syb::dblogin ()) == 0) {
		//FIXME - no memory
		std::cerr << "DEBUG: no memory for database" << std::endl;
		return;
	}

	syb::DBSETLUSER(p->m_login, uid.toAscii ().data ());
	syb::DBSETLPWD(p->m_login, pwd.toAscii ().data ());

	if ((p->m_dbproc = syb::dbopen (p->m_login, server.toAscii ().data ())) == 0) {
		//FIXME - unable to open database server
		std::cerr << "DEBUG: unable to open database server" << std::endl;
		return;
	}

	if ((p->m_ret = syb::dbuse (p->m_dbproc, db.toAscii ().data ())) == FAIL) {
		//FIXME - database name doesn't exist on server
		std::cerr << "DEBUG: database name doesn't exist on server" << std::endl;
		return;
	}
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

bool
DatabaseTester::isConnected () {
	return p->m_dbproc;
}

void
DatabaseTester::spChecksumsInsert (const QString &userid, const QString &testid, int regcksum, int ramcksum) {
	if (!isConnected ()) {
		return;
	}

	syb::dbfcmd (p->m_dbproc, "exec ChecksumsInsert \"%s\", \"%s\", %d, %d", userid.toAscii ().data (), testid.toAscii ().data (), regcksum, ramcksum);
	p->m_ret = syb::dbsqlexec (p->m_dbproc);
}

void
DatabaseTester::spExecInsert (const std::string &userid, const std::string &testid) {
	if (!isConnected ()) {
		return;
	}

	syb::dbfcmd (p->m_dbproc,
	             //"exec ExecInsertIgnoreFlags \"%s\", \"%s\", %d, \"%s\", %d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d\n",
	             "exec ExecInsertIgnoreFlags \"%s\", \"%s\", %d, \"%s\", %d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d\n",
	             userid.c_str (),
	             testid.c_str (),
	             p->m_cpu_comps->getInstCounter (),
	             p->m_inst->disassembly ().toString ().c_str (),
	             p->m_inst->getAddrMode (),
	             QString::number (p->m_eunit->getRegAX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegBX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegCX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegDX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegSP (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegBP (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegSI (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegDI (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegCS (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegDS (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegSS (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegES (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getRegIP (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             //QString::number (p->m_eunit->getRegFlags (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             0); //no ram checksum

	p->m_ret = syb::dbsqlexec (p->m_dbproc);
	if (p->m_ret == false) {
		std::cerr << "FAILED: ExecInsertIgnoreFlags (" << userid << ", " << testid << ")" << std::endl;
	}

#if 0
	std::printf ("exec ExecInsert \"%s\", \"%s\", %d, \"%s\", %d, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %d\n",
	             userid.c_str (),
	             testid.c_str (),
	             p->m_cpu_comps->getInstCounter (),
	             p->m_inst->disassembly ().toString ().c_str (),
	             p->m_inst->getAddrMode (),
	             QString::number (p->m_eunit->getRegAX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegBX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegCX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegDX (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegSP (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegBP (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegSI (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegDI (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegCS (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegDS (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegSS (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getSegRegES (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_biu->getRegIP (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             QString::number (p->m_eunit->getRegFlags (), 16).rightJustified (4, '0').toUpper ().toAscii ().data (),
	             0); //no ram checksum
#endif

}

