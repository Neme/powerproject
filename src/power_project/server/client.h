#pragma  once
#include <QObject>
#include <QTcpSocket>

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

public slots:
	void connected();
	void disconnected();
	void readyRead();

};