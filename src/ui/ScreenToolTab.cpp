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

void ScreenToolTab::toggleMagnifier() {
    HWND parentHwnd = (HWND)m_magnifierDisplay->winId();
    // 預設:放大鏡切換

    qDebug() << "MagnifierDisplay HWND:" << (void*)parentHwnd; //測試
}