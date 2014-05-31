#pragma  once
#include <QObject>
#include <QSqlDatabase>

class CDatabase : public QObject
{
	Q_OBJECT

public:
	CDatabase(QObject* parent = nullptr);
	~CDatabase();

private:
	QSqlDatabase* m_database;


};