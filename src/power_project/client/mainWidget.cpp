#include "stdafx.h"
#include "mainWidget.h"
#include "../utility/config.h"
//----------------------------------------------------------------------//	
CMainWidget::CMainWidget(QMainWindow* mainWnd)
:m_isWindowBarPressed{ false }, m_hMainWnd{ mainWnd }, m_titelBarHeight{ 0 }
, m_isOnResize{ false }
{
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->setMouseTracking(true);
	m_titelBarHeight = QQW::CConfig::get().getValue<int>("GUI.Window.TitelbarHeight");
}
//----------------------------------------------------------------------//	
CMainWidget::~CMainWidget()
{
	delete m_btnClose;
}
//----------------------------------------------------------------------//	
void CMainWidget::loadUI()
{

	// Window title bar
	m_btnClose = new QPushButton(this);
	m_btnClose->setObjectName("btnClose");
	m_btnClose->setParent(this);
	m_btnClose->setGeometry(this->geometry().width() - 38, 20, 16, 16);
	m_btnClose->show();

	//Load resize icon
	m_imgWindowDrag = new QImage("data/intern/style/img/drag.png");


	// signal/slot connections
	// Close button
	QObject::connect(m_btnClose, SIGNAL(clicked()), this, SLOT(buttonCloseClicked()));

}
void CMainWidget::paintEvent(QPaintEvent * event)
{


	// Draw
	m_Painter.begin(this);

	// not use antialiasing when resizing (performance reason)
	if (!m_isOnResize)m_Painter.setRenderHint(QPainter::RenderHint::Antialiasing);

	m_Painter.setPen(Qt::PenStyle::NoPen);
	//--------------------------------------//
	// Background
	m_Painter.setBrush(QColor::fromRgb(240, 240, 255));
	m_Painter.drawRoundedRect(15, 15,
		this->geometry().width() - 30, this->geometry().height() - 30,
		10, 10);
	//--------------------------------------//
	// Draw Window title bar
	m_Painter.setBrush(QColor::fromRgb(60, 60, 65));
	m_Painter.drawRoundedRect(15, 14,
		this->geometry().width() - 30, m_titelBarHeight,
		10, 10);
	m_Painter.fillRect(
		15, 25,
		this->geometry().width() - 30, m_titelBarHeight-10,
		QColor::fromRgb(60, 60, 65));
	//--------------------------------------//
	// Draw resize icon
	m_Painter.drawImage(
		this->geometry().width() - 35, 
		this->geometry().height() - 35, 
		*m_imgWindowDrag);
	//--------------------------------------//


	m_Painter.end();
}
//----------------------------------------------------------------------//
void CMainWidget::mouseMoveEvent(QMouseEvent* event)
{

	// Move window
	if (m_isWindowBarPressed)
	{
		m_hMainWnd->move(event->screenPos().toPoint() - m_mousePos);
	}

	//---------------------------------//
	//Resize
	else if (event->pos().y() > this->geometry().height() - 35 &&
		event->pos().x() > this->geometry().width() - 35)
	{
		m_hMainWnd->setCursor(Qt::CursorShape::SizeFDiagCursor);
	}
	else
	{
		m_hMainWnd->setCursor(Qt::CursorShape::ArrowCursor);
	}
	if (m_isOnResize)
	{
		int dx = (event->pos().x() <= 300) ? 300 : event->pos().x();
		int dy = (event->pos().y() <= 300) ? 300 : event->pos().y();
		m_hMainWnd->resize(dx,dy);
	}
	//---------------------------------//

	QWidget::mouseMoveEvent(event);
}
//----------------------------------------------------------------------//
void CMainWidget::mousePressEvent(QMouseEvent* event)
{

	if (event->button() & Qt::MouseButton::LeftButton)
	{
		// Check if user press on window title bar
		m_mousePos = event->windowPos().toPoint();
		if (event->pos().y() < 60)
		{
			m_isWindowBarPressed = true;
		}
		// Resize
		else if (event->pos().y() > this->geometry().height() - 35 &&
			event->pos().x() > this->geometry().width() - 35)
		{
			m_isOnResize = true;
		}
	}

	QWidget::mousePressEvent(event);
	
}
//----------------------------------------------------------------------//
void CMainWidget::mouseReleaseEvent(QMouseEvent* event)
{
	m_isWindowBarPressed = false;

	if (m_isOnResize)
	{
		m_isOnResize = false;
		//Repaint to enable antialiasing
		this->repaint();
	}
	
	QWidget::mouseReleaseEvent(event);
	
}
//----------------------------------------------------------------------//
void CMainWidget::resizeEvent(QResizeEvent* event)
{
	m_btnClose->setGeometry(this->geometry().width() - 38, 20, 16, 16);
	this->repaint();
	QWidget::resizeEvent(event);

}
//----------------------------------------------------------------------//
void CMainWidget::buttonCloseClicked()
{
	m_hMainWnd->close();
}
