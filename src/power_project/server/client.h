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

class CClient : public QObject
{
	Q_OBJECT

public:
	CClient(QObject* parent = nullptr);
	~CClient();

	void setSocket(int sockDesc);

private:
	QTcpSocket* m_socket;
	int m_socketDesc;

	int m_clientUID;

	QDataStream m_socketSteam;

public slots:
	void connected();
	void disconnected();
	void readyRead();


	void clientLogin();
};