#include "stdafx.h"
#include "Client.h"
#include <QSqlQuery>

//----------------------------------------------------------------------//
CClient::CClient(QObject* parent)
:QObject{ parent }, m_socketDesc{ 0 }
{

}
//----------------------------------------------------------------------//
CClient::~CClient()
{
	delete m_socket;
}
//----------------------------------------------------------------------//
void CClient::setSocket(int sockDesc)
{
	m_socketDesc = sockDesc;
	m_socket = new QTcpSocket(this);
	m_socket->setSocketDescriptor(sockDesc);

	// Connect signals / slots
	QObject::connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));
	QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	m_socketSteam.setDevice(m_socket);
	m_socketSteam.setByteOrder(QDataStream::LittleEndian);
	m_socketSteam.setVersion(QDataStream::Version::Qt_5_2);

	qDebug() << "CClient " << sockDesc << " tries to connected";
}
//----------------------------------------------------------------------//
void CClient::connected()
{
	qDebug() << "CClient " << m_socketDesc << " has connected";
}
//----------------------------------------------------------------------//
void CClient::disconnected()
{
	qDebug() << "CClient " << m_socketDesc << " has disconnected";
}
//----------------------------------------------------------------------//
void CClient::readyRead()
{
	// Get data from CClient
	qint16 header;
	m_socketSteam >> header;

	switch (header)
	{
	case EHEADERTYPES::CS_LOGIN: clientLogin(); break;
	default:break;
	}

}
//---------------------------------------------------------------------//
void CClient::clientLogin()
{
	qint16 senderHeader = 0;
	QString loginName = "";
	QString password = "";

	m_socketSteam >> loginName;
	m_socketSteam >> password;

	std::string s = loginName.toStdString();
	std::string ss = password.toStdString();

	QSqlQuery query;
	query.prepare("SELECT id FROM main.account WHERE name = :name AND password = :password");
	query.bindValue(":name", loginName);
	query.bindValue(":password", password);
	query.exec();

	if (query.next()/*Query = OK = login successful*/)
	{
		senderHeader = EHEADERTYPES::SC_LOGIN_SUCCESS;
		m_socket->flush();
		m_socketSteam << senderHeader;
	}
	else //  login NOT successful*/
	{
		senderHeader = EHEADERTYPES::SC_LOGIN_FAILED;
		m_socket->flush();
		m_socketSteam << senderHeader;
	}

}
