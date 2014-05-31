#pragma  once
#include <QObject>
#include <QTcpSocket>

enum EHEADERTYPES
{
	CS_NONE = 0,

	CS_LOGIN = 1,
	SC_LOGIN_SUCCESS = 2,
	SC_LOGIN_FAILED = 3,
};

class CClient : public QTcpSocket
{
	Q_OBJECT

public:
	CClient(QObject* parent = nullptr, const std::string& ip = "127.0.0.1", int port = 21525);
	~CClient();

	QDataStream& getSteam() { return m_socketSteam; }
	

private slots:
	void connected();
	void disconnected();
	void readyRead();
	void error(QAbstractSocket::SocketError error);
	

signals:
	void receiveLogin(int);

private:
	QTcpSocket* m_socket;
	QDataStream m_socketSteam;

	std::string m_ip;
	int m_port;
};