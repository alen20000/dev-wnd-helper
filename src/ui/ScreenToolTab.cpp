#include "ui/ScreenToolTab.hpp"

#include <QVBoxLayout>
#include <QPushButton>
#include <windows.h>



ScreenToolTab::ScreenToolTab(QWidget* parent)
    : QWidget(parent), m_isMagnifier(false)
{
#pragma region UI 初始化與排版 (UI Setup)

	// 初始化更新用計時器
    m_updateTimer = new QTimer(this);

    // Btn
    QPushButton* m_maginifer = new QPushButton("Magnifier", this);
    connect(m_maginifer, &QPushButton::clicked, this, &ScreenToolTab::toggleMagnifier);

    // 視窗容器
	m_magnifierDisplay = new QWidget(this);
    m_magnifierDisplay->setStyleSheet("background-color: gray;");

    #pragma region 排版
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_maginifer);
    layout->addWidget(m_magnifierDisplay);
    #pragma endregion

    // Bind
	connect(m_updateTimer, &QTimer::timeout, [this]() {
		if (m_isMagnifier && hwndMagContainer) {

		}
	});

#pragma endregion
}
// @brief 放大鏡切換
void ScreenToolTab::toggleMagnifier() {
	HWND hwndMagContainer = (HWND)m_magnifierDisplay->winId();  // Qt 內部不會幫每個 widget 建立獨立的window handle，而是要底層溝通時在用winID建立物件的窗柄
    m_isMagnifier = !m_isMagnifier;

    if (m_isMagnifier) {
        // 啟動放大鏡
        qDebug() << "MagnifierDisplay HWND:" << (void*)hwndMagContainer; //測試
 
        int w = m_magnifierDisplay->width();
        int h = m_magnifierDisplay->height();
 
        m_controller.startMagnifier(hwndMagContainer,w,h);
    }


}