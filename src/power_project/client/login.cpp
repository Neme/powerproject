#include "stdafx.h"
#include "login.h"
#include <QDataStream>
#include <QByteArray>
//----------------------------------------------------------------------//
CLogin::CLogin(QWidget *parent)
: QMainWindow{ parent }
{
	m_ui.setupUi(this);
	this->setMouseTracking(true);

	// Setup design
	m_designer.setWindowHandel(this, m_ui.mainWidget);
	m_designer.designWindow();

	m_ui.mainWidget->loadUI();

	QObject::connect(m_ui.btnLogin, SIGNAL(clicked()), this, SLOT(loginClicked()));

}
//----------------------------------------------------------------------//
CLogin::~CLogin()
{

}
//----------------------------------------------------------------------//
void CLogin::setClientHandler(CClient* handler)
{
	m_hClient = handler;
	QObject::connect(m_hClient, SIGNAL(receiveLogin(int)),
		this, SLOT(login(int)));
}
//----------------------------------------------------------------------//
void CLogin::loginClicked()
{
	if (m_hClient == nullptr)
	{
		ERROR_LOG("Can't connect because client handler is nullptr");
		return;
	}
	m_ui.btnLogin->setEnabled(true);

	// encrypt password using md5 algorithm
	QString md5Password = QString(QCryptographicHash::hash(
		(m_ui.editPassword->text().toStdString().c_str()),
		QCryptographicHash::Md5).toHex());

	qint16 header = EHEADERTYPES::CS_LOGIN;
	m_hClient->getSteam() << header;
	m_hClient->getSteam() << m_ui.editName->text();
	m_hClient->getSteam() << md5Password;

	
}
//---------------------------------------------------------------------//
void CLogin::login(int isOkay)
{
	if (isOkay == EHEADERTYPES::SC_LOGIN_SUCCESS)
	{
		emit loginSuccess();
		this->close();
	}
	else
	{
		m_ui.lblError->setText("<font color = '#FF0000'>Error< / font>");
	}

	m_ui.btnLogin->setEnabled(true);

}

//---------------------------------------------------------------------//
