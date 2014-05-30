#pragma once

class CDesigner
{
public:
	CDesigner();
	CDesigner(QMainWindow* window, QWidget* mainWidet);
	~CDesigner();
	
	void setWindowHandel(QMainWindow* window, QWidget* mainWidget);
	void designWindow();
private:
	void loadStyle();

	QMainWindow* m_hMainWnd;
	QWidget* m_hMainWidet;
	QPainter m_Painter;

	//Shadow
	QGraphicsDropShadowEffect* m_shadowEffect;
};