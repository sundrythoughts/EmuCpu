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


/**
@file LoaderWidget.hh
@brief 
*/

#ifndef JAF__LOADER_WIDGET_HH
#define JAF__LOADER_WIDGET_HH

#include <QtCore>
#include <QtGui>
#include <QtUiTools>
#include <QSqlDatabase>
#include "ui_LoaderWidget.h"

#include "Loader.hh"


/**
*/
class LoadFileThread : public QThread {
	Q_OBJECT

	QString m_file_name;
	Loader m_loader;

protected:
	virtual void run ();

public:
	LoadFileThread (QObject *parent = 0) : QThread (parent) {
	}

public slots:
	void open_file (const QString &filename);

signals:
	void checksum_values (int reg, int mem);
};


/**
*/
class LoadDatabaseThread : public QThread {
	Q_OBJECT

	QSqlDatabase m_db;

protected:
	virtual void run ();

public:
	LoadDatabaseThread (QObject *parent = 0) : QThread (parent) {
		m_db = QSqlDatabase::addDatabase ("QTDS");
	}

public slots:
	void open_database ();

signals:
	void test_results (QString num, QString res);
};


/**
*/
class LoaderWidget : public QWidget, protected Ui::LoaderWidget {
	Q_OBJECT

	LoadFileThread m_load_file_thread;
	LoadDatabaseThread m_load_database_thread;

private slots:
	void file_checksum_values (int reg, int mem);

	void choose_file ();

	void database_test_results (QString test, QString res);

	void connect_to_database ();

public:
	LoaderWidget (QWidget *parent = 0) : QWidget (parent) {
		setupUi (this);

		connect (m_btn_open, SIGNAL(clicked ()), this, SLOT(choose_file ()));
		connect (&m_load_file_thread, SIGNAL(checksum_values (int, int)), this, SLOT(file_checksum_values (int, int)));

		connect (m_btn_db_open, SIGNAL(clicked ()), this, SLOT(connect_to_database ()));
		connect (&m_load_database_thread, SIGNAL(test_results (QString, QString)), this, SLOT(database_test_results (QString, QString)));
	}

	virtual ~LoaderWidget () {
		m_load_file_thread.quit ();
		m_load_database_thread.quit ();
	}
};

#endif //JAF__LOADER_WIDGET_HH

