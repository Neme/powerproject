#pragma once

#include <QtWidgets/QDialog>
#include "ui_login.h"
#include "designer.h"
#include "client.h"

class CLogin : public QMainWindow
{
	Q_OBJECT

public:
	CLogin(QWidget *parent = 0);
	~CLogin();

	void setClientHandler(CClient* handler);

private:
	Ui::CLoginClass m_ui;
	CDesigner m_designer;
	CClient *m_hClient;

private slots:
	void loginClicked();
};
