#include "stdafx.h"
#include "powerproject.h"
#include "designer.h"
#include "mainWidget.h"
//----------------------------------------------------------------------//
CPowerProject::CPowerProject(QWidget *parent)
	: QMainWindow(parent)
{
	m_ui.setupUi(this);
	this->setMouseTracking(true);
	m_ui.contentWidget->setMouseTracking(true);

	// Setup design
	m_designer.setWindowHandel(this, m_ui.mainWidget);
	m_designer.designWindow();


	m_ui.mainWidget->loadUI();
	m_ui.naviWidget->loadUI();

}
//----------------------------------------------------------------------//
CPowerProject::~CPowerProject()
{
	
}
//---------------------------------------------------------------------//
void CPowerProject::start()
{
	this->show();
}

//----------------------------------------------------------------------//
