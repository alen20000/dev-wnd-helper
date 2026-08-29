#include "ui\MainWindow.hpp"
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent) //初始化父類或成員變數
{
	//視窗大小預設
	setWindowTitle("測試視窗");
	resize(400, 300);

	//建立物件
	outputLabel = new QLabel("尚未執行任何動作", this);
	outputLabel->setWordWrap(true);

	f_button = new QPushButton("first_button", this);
	s_button = new QPushButton("secound_button", this);
	thi_button = new QPushButton("third_button", this);

	//排版
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(f_button);
	layout->addWidget(s_button);
	layout->addWidget(thi_button);

	//接線
	connect(f_button, &QPushButton::clicked, this, &MainWindow::onFirst);

}

void MainWindow::showMessage(const QString& text) {
	outputLabel->setText(text);
}
//觸發函式(測試用)
void MainWindow::onFirst() {
	this->showMessage("按下測試按鈕");
}


void MainWindow::onSecond() {
	// 暫時空著

}

void MainWindow::onThird() {
	// 暫時空著
}
