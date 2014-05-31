#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_powerproject.h"
#include "designer.h"
#include "client.h"

class CPowerProject : public QMainWindow
{
	Q_OBJECT

public:
	CPowerProject(QWidget *parent = 0);
	~CPowerProject();

private:
	Ui::CPowerProjectClass m_ui;
	CDesigner m_designer;
	CClient* m_client;

public slots:
	void start();
};
