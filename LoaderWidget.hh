#ifndef LOADER_WIDGET_HH
#define LOADER_WIDGET_HH

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

#endif //LOADER_WIDGET_HH

