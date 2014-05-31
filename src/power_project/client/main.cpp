#include "stdafx.h"
#include <QtWidgets/QApplication>
#include "powerproject.h"
#include "login.h"
#include "client.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CClient client;
	CPowerProject powerProject;
	CLogin login;
	login.setClientHandler(&client);

	QObject::connect(&login, SIGNAL(loginSuccess()), &powerProject, SLOT(start()));

	login.show();
	//powerProject.show();
	return a.exec();
}
