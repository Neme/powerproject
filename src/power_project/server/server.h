#pragma once
#include <qtcpserver.h>
#include "client.h"
#include "database.h"

#define MAX_USER_COUT 1000

class CServer : public QTcpServer
{
public:
	CServer();
	~CServer();
	void startServer();

private:
	int m_port;
	void incomingConnection(qintptr description) override;

	std::map<int /*ID*/, std::shared_ptr<CClient> /*Pointer to client*/> m_clients;

	// Database
	CDatabase *m_database;

public slots:
	void clientDisconnected();
};
