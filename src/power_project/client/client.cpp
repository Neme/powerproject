#include "stdafx.h"
#include "client.h"

//----------------------------------------------------------------------//
CClient::CClient(QObject* parent /*= nullptr*/, const std::string& ip, int port)
: m_ip{ ip }, m_port{ port }
{
	// Create sockets
	m_socket = new QTcpSocket(this);
	m_socket->abort(); // for safety reasons

	// Connect socket to host
	m_socket->connectToHost(QString::fromStdString(ip), port);


	// Signal / Slot
	connect(m_socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(m_socket, SIGNAL(connected()), this, SLOT(connected()));
	connect(m_socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
	// Error handling
	connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)),
		this, SLOT(error(QAbstractSocket::SocketError)));

	// Set ioDevice
	m_socketSteam.setDevice(m_socket);
	m_socketSteam.setVersion(QDataStream::Qt_5_2);
	m_socketSteam.setByteOrder(QDataStream::LittleEndian);

}
//----------------------------------------------------------------------//
CClient::~CClient()
{
	delete m_socket;
}
//----------------------------------------------------------------------//
void CClient::connected()
{

}
//----------------------------------------------------------------------//
void CClient::disconnected()
{

}
//----------------------------------------------------------------------//
void CClient::readyRead()
{
	// Clear old data in m_socket
	m_socket->flush();

	// Get header see: EHEADERTYPES
	quint16 headerType;
	m_socketSteam >> headerType;

	switch (headerType)
	{
	case EHEADERTYPES::SC_LOGIN_FAILED: emit receiveLogin(EHEADERTYPES::SC_LOGIN_FAILED); break;
	case EHEADERTYPES::SC_LOGIN_SUCCESS: emit receiveLogin(EHEADERTYPES::SC_LOGIN_SUCCESS); break;
	default:break;
	}
}
//----------------------------------------------------------------------//
// from: http://qt-project.org/doc/qt-4.8/qabstractsocket.html#SocketError-enum
void CClient::error(QAbstractSocket::SocketError error)
{
	switch (error)
	{
	case QAbstractSocket::ConnectionRefusedError: {
		ERROR_LOG("The connection was refused by the peer (or timed out)."); break; }
	case QAbstractSocket::RemoteHostClosedError: {
		ERROR_LOG("The remote host closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent."); break; }
	case QAbstractSocket::HostNotFoundError: {
		ERROR_LOG("The host address was not found."); break; }
	case QAbstractSocket::SocketAccessError: {
		ERROR_LOG("The socket operation failed because the application lacked the required privileges."); break; }
	case QAbstractSocket::SocketResourceError: {
		ERROR_LOG("The local system ran out of resources (e.g., too many sockets)."); break; }
	case QAbstractSocket::SocketTimeoutError: {
		ERROR_LOG("The socket operation timed out."); break; }
	case QAbstractSocket::DatagramTooLargeError: {
		ERROR_LOG("The datagram was larger than the operating system's limit (which can be as low as 8192 bytes)."); break; }
	case QAbstractSocket::NetworkError: {
		ERROR_LOG("An error occurred with the network (e.g., the network cable was accidentally plugged out)."); break; }
	case QAbstractSocket::AddressInUseError: {
		ERROR_LOG("The address specified to QUdpSocket::bind() is already in use and was set to be exclusive."); break; }
	case QAbstractSocket::SocketAddressNotAvailableError: {
		 ERROR_LOG("The address specified to QUdpSocket::bind() does not belong to the host."); break; }
	case QAbstractSocket::UnsupportedSocketOperationError: {
		 ERROR_LOG("The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support)."); break; }
	case QAbstractSocket::ProxyAuthenticationRequiredError: {
		ERROR_LOG("The socket is using a proxy, and the proxy requires authentication."); break; }
	case QAbstractSocket::SslHandshakeFailedError: {
		ERROR_LOG("The SSL/TLS handshake failed, so the connection was closed (only used in QSslSocket) (This value was introduced in 4.4.)"); break; }
	case QAbstractSocket::UnfinishedSocketOperationError: {
		ERROR_LOG("Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background). (This value was introduced in 4.4.)"); break; }
	case QAbstractSocket::ProxyConnectionRefusedError: {
		ERROR_LOG("Could not contact the proxy server because the connection to that server was denied (This value was introduced in 4.5.)"); break; }
	case QAbstractSocket::ProxyConnectionClosedError: {
		ERROR_LOG("The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established) (This value was introduced in 4.5.)"); break; }
	case QAbstractSocket::ProxyConnectionTimeoutError: {
		ERROR_LOG("The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase. (This value was introduced in 4.5.)"); break; }
	case QAbstractSocket::ProxyNotFoundError: {
		ERROR_LOG("The proxy address set with setProxy() (or the application proxy) was not found. (This value was introduced in 4.5.)"); break; }
	case QAbstractSocket::ProxyProtocolError: {
		ERROR_LOG("The connection negotiation with the proxy server because the response from the proxy server could not be understood. (This value was introduced in 4.5.)"); break; }
	case QAbstractSocket::UnknownSocketError: {
		ERROR_LOG("An unidentified error occurred."); break; }
	}
}
//---------------------------------------------------------------------//

