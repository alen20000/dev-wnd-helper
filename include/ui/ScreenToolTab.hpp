#pragma once
#include "controller/MagnifierController.hpp"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>

class ScreenToolTab : public QWidget {
	Q_OBJECT

public:
    explicit ScreenToolTab(QWidget* parent = nullptr);
    ~ScreenToolTab() = default;
private slots:
	/* * @brief 「放大鏡」按鈕點擊事件，切換放大鏡功能
	 */
	void toggleMagnifier();

private:

	//Layout
	QVBoxLayout* layout;

	//Btn
	QPushButton* m_maginifer;

	//Display
	QWidget* m_magnifierDisplay;

	//Flag
	bool m_isMagnifier = false;

	// Qt物件窗柄
	HWND hwndMagContainer;

	// Magnifier 更新計時器
	QTimer* m_updateTimer;

	//初始化
	MagnifierController m_controller;
};