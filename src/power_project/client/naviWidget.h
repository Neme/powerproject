#pragma once

class CNaviItemWidged : public QWidget
{
	Q_OBJECT

public:
	CNaviItemWidged(QWidget* parent, const std::string& title);
	~CNaviItemWidged();

	void paintEvent(QPaintEvent* event) override;
	void enterEvent(QEvent* event) override;
	void leaveEvent(QEvent* event) override;

	void setIcon(const std::string& icon);
private:
	QPainter m_Painter;

	bool m_isHover;

	std::string m_title;
	QLabel* m_lblTitel;
	QImage* m_icon;
};

class CNaviWidget : public QWidget
{
	Q_OBJECT

public:
	CNaviWidget(QWidget* parent);
	~CNaviWidget();
	void paintEvent(QPaintEvent * event) override;
	void loadUI();

private:
	QPainter m_Painter;

	// Projectinfo
	QLabel* m_lblProjName;
	QLabel* m_lblUserName;
	QImage* m_imgLogo;

	// Items
	std::list<CNaviItemWidged*> m_ItemList;
	void fillList();

};