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


#include "LoaderWidget.hh"
#include <iostream>
#include <QSqlError>

void
LoadFileThread::run () {
	m_loader.initialize ();
	m_loader.load (m_file_name.toAscii ().data ());
	emit checksum_values (m_loader.checksum_registers (), m_loader.checksum_memory ());
}

void
LoadFileThread::open_file (const QString &filename) {
	m_file_name = filename;

	start ();
}

void
LoadDatabaseThread::run () {
	m_db.setHostName ("css.cs.bju.edu");
	m_db.setDatabaseName("sim86");
	//m_db.setDatabaseName ("Driver=/usr/lib/qt4/plugins/sqldrivers/libqsqlodbc.so;Server=css;Database=sim86;User ID=sim86;Password=sim86fall2009");
	//m_db.setDatabaseName ("Driver=/usr/lib/odbc/libtdsodbc.so;Server=css.cs.bju.edu;Database=sim86;User ID=sim86;Password=sim86fall2009;Trusted_Connection=False;");
	m_db.setUserName("sim86");
	m_db.setPassword("sim86fall2009");

	if (!m_db.open ()) {
		emit test_results ("Test", "Incorrect");
		qDebug () << "Error: " << m_db.lastError ().text ();
	}
	else {
		emit test_results ("Test", "Correct");
	}
}

void
LoadDatabaseThread::open_database () {
	start ();
}

void
LoaderWidget::file_checksum_values (int reg, int mem) {
	m_lnedit_reg_checksum->setText (QString::number (reg));
	m_lnedit_mem_checksum->setText (QString::number (mem));
}

void
LoaderWidget::choose_file () {
	QString filename = QFileDialog::getOpenFileName (this, "Load file...");
	if (!filename.isNull ()) {
		m_lnedit_file_name->setText (filename);
		m_load_file_thread.open_file (filename);
	}
}

void
LoaderWidget::database_test_results (QString test, QString res) {
	QStringList slist;
	slist << test << res;
	m_tree_db_results->addTopLevelItem (new QTreeWidgetItem (slist));
}

void
LoaderWidget::connect_to_database () {
	m_load_database_thread.open_database ();
}

