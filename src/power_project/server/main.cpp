#include "stdafx.h"
#include "server.h"
#include "../utility/config.h"
#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
	//Set filename for log and config file
	QQW::CLog::get(true).setFilename("server_log.txt");
	QQW::CConfig::get(true).setFilename("data/server_config.json");

	QCoreApplication a(argc, argv);

	std::cout << "Welcome PowerProject || v0.1" << std::endl;

	CServer server;
	server.startServer();

	return a.exec();
}
