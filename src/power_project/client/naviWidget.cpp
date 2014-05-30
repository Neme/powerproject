#include "stdafx.h"
#include "naviWidget.h"


#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/detail/json_parser_error.hpp>

//----------------------------------------------------------------------//	
CNaviWidget::CNaviWidget(QWidget* parent)
:QWidget{ parent }
{
	
}
//----------------------------------------------------------------------//	
CNaviWidget::~CNaviWidget()
{

}
//----------------------------------------------------------------------//
void CNaviWidget::loadUI()
{
	m_lblProjName = new QLabel("TestProject",this);
	m_lblProjName->setObjectName("lblProjectName");
	m_lblProjName->setFont(QFont("Arial", 18));
	m_lblProjName->setGeometry(66, 8, 200, 50);
	
	m_lblUserName = new QLabel("@Nemme", this);
	m_lblUserName->setObjectName("lblUserName");
	m_lblUserName->setFont(QFont("Arial", 10));
	m_lblUserName->setGeometry(66, 40, 100, 20);

	m_imgLogo = new QImage("data/test/logo.png");

	fillList();
}
//----------------------------------------------------------------------//
void CNaviWidget::paintEvent(QPaintEvent * event)
{
	// Draw
	m_Painter.begin(this);

	m_Painter.setRenderHint(QPainter::RenderHint::Antialiasing);
	m_Painter.setPen(Qt::PenStyle::NoPen);

	// Background
	m_Painter.setBrush(QColor::fromRgb(50, 50, 57));
	m_Painter.drawRoundedRect(15, 14,
		240, this->geometry().height()-28,
		10, 10);

	// Image background base
	m_Painter.setBrush(QColor::fromRgb(30, 30, 37));
	m_Painter.drawRoundedRect(22, 21,
		40, 40,
		5, 5);

	if (m_imgLogo != nullptr)
		m_Painter.drawImage(22, 21, *m_imgLogo);


	m_Painter.end();
}
//----------------------------------------------------------------------//	
void CNaviWidget::fillList()
{
	using boost::property_tree::json_parser_error;
	using boost::property_tree::ptree;

	ptree pt;

	try
	{
		read_json("data/navigation.json", pt);
	}
	catch (json_parser_error& e)
	{
		ERROR_LOG(e.what());
		return;
	}

	int index = 0;
	BOOST_FOREACH(ptree::value_type const &v, pt.get_child("Navigation"))
	{
		std::string titel = v.second.get<std::string>("titel");
		std::string icon = "data/intern/style/icon/" + v.second.get<std::string>("icon");
		std::string script = "data/intern/scripts/" + v.second.get<std::string>("script");
		int user = v.second.get<int>("user");
		

		CNaviItemWidged* item = new CNaviItemWidged(this, titel);
		item->setGeometry(15, index * 35 + 100 + index * 1, 230, 35);
		item->setIcon(icon);
		m_ItemList.push_back(item);
		index++;
	}
}
//----------------------------------------------------------------------//	
// CNaviItemWidged
//----------------------------------------------------------------------//	
CNaviItemWidged::CNaviItemWidged(QWidget* parent, const std::string& title) 
:QWidget{ parent }, m_title{ title }, m_isHover{ false }
{
	m_lblTitel = new QLabel(QString::fromStdString(title), this);
	m_lblTitel->setObjectName("lblNaviItemTitel");
	m_lblTitel->setFont(QFont("Arial", 12));
	m_lblTitel->setGeometry(30, 7, 100, 20);
}
//----------------------------------------------------------------------//	
CNaviItemWidged::~CNaviItemWidged()
{
	delete m_lblTitel;
	delete m_icon;
}
//----------------------------------------------------------------------//	
void CNaviItemWidged::paintEvent(QPaintEvent * event)
{
	// Draw
	m_Painter.begin(this);

	m_Painter.setRenderHint(QPainter::RenderHint::Antialiasing);
	m_Painter.setPen(Qt::PenStyle::NoPen);

	// Background
	m_Painter.setBrush(m_isHover ? QColor::fromRgb(80, 80, 90) : QColor::fromRgb(60, 60, 70));
	m_Painter.drawRect(
		0,
		0,
		this->geometry().width(),
		this->geometry().height());


	if (m_icon != nullptr)
		m_Painter.drawImage(10, 10, *m_icon);

	m_Painter.end();
}
//----------------------------------------------------------------------//	
void CNaviItemWidged::setIcon(const std::string& icon)
{
	m_icon = new QImage(QString::fromStdString(icon));
}
//----------------------------------------------------------------------//	
void CNaviItemWidged::enterEvent(QEvent* event)
{
	m_isHover = true;
	this->repaint();
}
//----------------------------------------------------------------------//	
void CNaviItemWidged::leaveEvent(QEvent* event)
{
	m_isHover = false;
	this->repaint();

}
//----------------------------------------------------------------------//	
