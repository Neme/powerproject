#pragma once
#include <qtcpserver.h>
#include "client.h"

#define MAX_USER_COUT 1000

class CServer : public QTcpServer
{
public:
	CServer();
	~CServer();
	void startServer();

private:
	int m_port;
	std::map<int /*ID*/, CClient* /*Pointer to client*/> m_clients;

	void incomingConnection(qintptr description) override;

public slots:
	void clientDisconnected();
};
