#include "ui/ScreenToolTab.hpp"
#include <QVBoxLayout>
#include <QPushButton>
ScreenToolTab::ScreenToolTab(QWidget* parent)
    : QWidget(parent)
{


    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Btn
    QPushButton* m_maginifer = new QPushButton("Magnifier", this);
    layout->addWidget(m_maginifer);
}

void ScreenToolTab::toggleMagnifier() {
    // 預設:放大鏡切換
}