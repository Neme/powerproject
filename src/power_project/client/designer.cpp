#include "stdafx.h"
#include "designer.h"


//----------------------------------------------------------------------//	
// CDesigner
//----------------------------------------------------------------------//	
CDesigner::CDesigner()
{}
//----------------------------------------------------------------------//
CDesigner::CDesigner(QMainWindow* window, QWidget* mainWidget)
: m_hMainWnd{ window }, m_hMainWidet{ mainWidget }
{}
//----------------------------------------------------------------------//
CDesigner::~CDesigner()
{
	
}
//----------------------------------------------------------------------//
void CDesigner::setWindowHandel(QMainWindow* window, QWidget* mainWidet)
{
	m_hMainWnd = window;
	m_hMainWidet = mainWidet;
}
//----------------------------------------------------------------------//
void CDesigner::designWindow()
{
	// Check of m_hMainWnd and m_hCentWidged is set
	if (m_hMainWnd == nullptr || m_hMainWidet == nullptr)
		return;

	// Load style from "data/intern/style/main/style.css"
	this->loadStyle();

	// Set window transparency
	m_hMainWnd->setAttribute(Qt::WA_TranslucentBackground);
	m_hMainWnd->setWindowFlags(Qt::FramelessWindowHint);

	// Set window shadow
	m_shadowEffect = new QGraphicsDropShadowEffect();
	m_shadowEffect->setBlurRadius(6);
	m_shadowEffect->setOffset(0, 0);
	m_shadowEffect->setColor(Qt::GlobalColor::black);
	m_hMainWidet->setGraphicsEffect(m_shadowEffect);
}
//----------------------------------------------------------------------//
void CDesigner::loadStyle()
{
	// Load style file
	QFile file("data/intern/style/main/style.css");

	if (file.open(QIODevice::ReadOnly))
	{
		m_hMainWnd->setStyleSheet(file.readAll());
	}
	else
	{ERROR_LOG("Error can't open: data/intern/style/main/style.css");}

	file.close();
}
//----------------------------------------------------------------------//
