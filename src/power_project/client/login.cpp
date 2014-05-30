#include "stdafx.h"
#include "login.h"

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
}
//----------------------------------------------------------------------//
void CLogin::loginClicked()
{
	if (m_hClient == nullptr)
	{
		ERROR_LOG("Can't connect because client handler is nullptr");
		return;
	}

	m_hClient->send(EHEADERTYPES::CS_LOGIN,m_ui.editName->text().toStdString());
}
//---------------------------------------------------------------------//
