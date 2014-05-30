#include "stdafx.h"
#include "server.h"
#include "../utility/config.h"
//----------------------------------------------------------------------//
CServer::CServer() 
:m_port{0}
{
	m_port = QQW::CConfig::get().getValue<int>("Network.Port");
}
//----------------------------------------------------------------------//
CServer::~CServer()
{
	//for (auto itr : m_clients)
		//delete *(*itr->second);
	m_clients.clear();

}
//----------------------------------------------------------------------//
void CServer::startServer()
{
	if (this->listen(QHostAddress::Any, m_port))
	{
		std::cout << "Server has been started" << std::endl;
	}
	else{ ERROR_LOG("Can't listen to port: " + m_port); }
}
//----------------------------------------------------------------------//
void CServer::incomingConnection(qintptr description)
{
	//Create new client
	CClient* client = new CClient();
	client->setSocket(description);

	// search for free id
	for (auto id = 0; id < MAX_USER_COUT; id++)
	{
		if (m_clients.find(id) == m_clients.end())
		{
			// Insert the id to client map
			m_clients.insert(std::make_pair(id, client));
			break;
		}
	}
	
	
}
