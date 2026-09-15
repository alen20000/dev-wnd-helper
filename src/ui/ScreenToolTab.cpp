#include "ui/ScreenToolTab.hpp"
#include <QVBoxLayout>
#include <QPushButton>
ScreenToolTab::ScreenToolTab(QWidget* parent)
    : QWidget(parent)
{
#pragma region UI 初始化與排版 (UI Setup)

    // Btn
    QPushButton* m_maginifer = new QPushButton("Magnifier", this);
    

    // 視窗容器
	QWidget* MagnifierDisplay = new QWidget(this);
    MagnifierDisplay->setStyleSheet("background-color: gray;");

    #pragma region 排版
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_maginifer);
    layout->addWidget(MagnifierDisplay);
    #pragma endregion

#pragma endregion
}

void ScreenToolTab::toggleMagnifier() {
    // 預設:放大鏡切換
}