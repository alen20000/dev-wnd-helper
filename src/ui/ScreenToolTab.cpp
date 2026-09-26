#include "ui/ScreenToolTab.hpp"
#define WIN32_LEAN_AND_MEAN  // 排除微軟少用、又肥的標頭檔
#define NOMINMAX //關掉微軟的全域 min/max 巨集
#include <windows.h>
#include <QVBoxLayout>
#include <QPushButton>
ScreenToolTab::ScreenToolTab(QWidget* parent)
    : QWidget(parent)
{
#pragma region UI 初始化與排版 (UI Setup)

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

#pragma endregion
}
// @brief 放大鏡切換
void ScreenToolTab::toggleMagnifier() {
	HWND hwndMagContainer = (HWND)m_magnifierDisplay->winId();  // Qt 內部不會幫每個 widget 建立獨立的window handle，而是要底層溝通時在用winID建立物件的窗柄


    qDebug() << "MagnifierDisplay HWND:" << (void*)hwndMagContainer; //測試
}