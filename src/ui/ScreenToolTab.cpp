#include "ui/ScreenToolTab.hpp"

#include <QVBoxLayout>
#include <QPushButton>
#include <windows.h>

#include <iostream>


ScreenToolTab::ScreenToolTab(QWidget* parent)
    : QWidget(parent), m_isMagnifier(false), hwndMagContainer(nullptr)
{
#pragma region UI 初始化與排版 (UI Setup)

    // 初始化更新用計時器
    m_updateTimer = new QTimer(this);

    // Btn
    QPushButton* m_maginifer = new QPushButton("Magnifier", this);
    connect(m_maginifer, &QPushButton::clicked, this, &ScreenToolTab::toggleMagnifier);

    // 視窗容器
    m_magnifierDisplay = new QWidget(this);

    m_magnifierDisplay->setMinimumSize(500, 500);
    m_magnifierDisplay->setMaximumSize(500, 500);

    m_magnifierDisplay->setAttribute(Qt::WA_NativeWindow, true); // 強制讓該widget 擁有自己的原生窗口句柄
    m_magnifierDisplay->setAttribute(Qt::WA_StyledBackground, true);
    m_magnifierDisplay->setStyleSheet("background-color: #2b2b2b; border: 2px solid #555;");


#pragma region 排版
    QVBoxLayout* m_layout = new QVBoxLayout(this);
    m_layout->addWidget(m_maginifer);
    m_layout->addWidget(m_magnifierDisplay, 0, Qt::AlignCenter);;// 0:不搶占空間；Qt::AlignCenter:置中對齊
#pragma endregion

    //Bind Event
    connect(m_updateTimer, &QTimer::timeout, [this]() {

        if (m_isMagnifier && hwndMagContainer) {

            int width = m_magnifierDisplay->width();
            int height = m_magnifierDisplay->height();

            // 放大倍率
            float zoomLevel = 4.0f;

            m_controller.updateMagnifier(width, height, zoomLevel);
        }
        });

#pragma endregion
}
// @brief 放大鏡切換
void ScreenToolTab::toggleMagnifier() {

    hwndMagContainer = (HWND)m_magnifierDisplay->winId();  //向Qt索取該widget的原生窗口句柄
    m_isMagnifier = !m_isMagnifier;

    if (m_isMagnifier) {
        // 啟動放大鏡
        qDebug() << "Main Widget HWND:" << (HWND)this->winId();
        qDebug() << "Display Widget HWND:" << (HWND)m_magnifierDisplay->winId();
        qDebug() << "啟動放大鏡";

        int w = m_magnifierDisplay->width();
        int h = m_magnifierDisplay->height();

        m_controller.startMagnifier(hwndMagContainer, w, h);

        // 每 30ms 更新一次 → 1000 / 30 ≈ 33 FPS
        m_updateTimer->start(30);
    }
    else {
        m_updateTimer->stop();
        m_controller.stopMagnifier();
    }


}