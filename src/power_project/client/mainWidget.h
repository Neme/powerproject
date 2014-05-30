#pragma once
#include "naviWidget.h"

class CMainWidget : public QWidget
{
	Q_OBJECT

	public:
		CMainWidget(QMainWindow* mainWnd);
		~CMainWidget();

		void paintEvent(QPaintEvent * event) override;
		void loadUI();

	private:
		//Painter for drawing
		QPainter m_Painter;

		//Handler to main window
		QMainWindow* m_hMainWnd;

		// Resize icon
		QImage* m_imgWindowDrag;
		bool m_isOnResize;

		//Titelbar
		QPushButton* m_btnClose;
		int m_titelBarHeight;
		


		//Events
		void mouseMoveEvent(QMouseEvent* event) override;
		void mousePressEvent(QMouseEvent* event) override;
		void mouseReleaseEvent(QMouseEvent* event) override;
		void resizeEvent(QResizeEvent* event) override;

		// Move Window
		bool m_isWindowBarPressed;
		QPoint m_mousePos;

	private slots:
		void buttonCloseClicked();
};