#include "stdafx.h"
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "../utility/config.h"
//---------------------------------------------------------------------//
CDatabase::CDatabase(QObject* parent /*= nullptr*/)
:QObject{ parent }
{
	// from http://qt-project.org/doc/qt-5/sql-driver.html#supported-databases
	m_database = &QSqlDatabase::addDatabase(QString::fromStdString(PPCONFIG(std::string, "Database.Type")));
	m_database->setDatabaseName(QString::fromStdString(PPCONFIG(std::string, "Database.Location")));

	
	bool isOpen = m_database->open();
	if (!isOpen)
	{ERROR_LOG("Can't open database: " + m_database->lastError().text().toStdString());}

}
//---------------------------------------------------------------------//
CDatabase::~CDatabase()
{
	m_database->close();
}
