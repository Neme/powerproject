#pragma  once
#include <QObject>
#include <QTcpSocket>

enum EHEADERTYPES
{
	CS_NONE = 0,

	CS_LOGIN = 1,
};

class CClient : public QTcpSocket
{
	Q_OBJECT

public:
	CClient(QObject* parent = nullptr, const std::string& ip = "127.0.0.1", int port = 21525);
	~CClient();

	void send(qint16 type, const std::string& data);

private slots:
	void connected();
	void disconnected();
	void readyRead();
	void error(QAbstractSocket::SocketError error);
	

signals:
	void receive(int type);

private:
	QTcpSocket* m_socket;

	std::string m_ip;
	int m_port;

};