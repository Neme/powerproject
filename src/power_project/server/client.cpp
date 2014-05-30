#include "stdafx.h"
#include "Client.h"

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
	QDataStream inSteam(m_socket);
	inSteam.setByteOrder(QDataStream::LittleEndian);
	qint16 header;
	inSteam >> header;
	
	QString loginName = "";
	inSteam >> loginName;


	std::cout << "Test " << header << " " << loginName.toStdString() << std::endl;

	if (loginName == "rudi")
	{
		m_socket->write("1DONE");

	}
	// Process data

	// Send something back
	//m_socket->write("Your message: "+ *data);

}
