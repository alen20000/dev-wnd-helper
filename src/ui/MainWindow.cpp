#include "ui\MainWindow.hpp"
#include "controller\AppController.hpp"
#include "DataTypes.hpp"
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent) //初始化父類或成員變數
{
	//視窗大小預設
	setWindowTitle("測試視窗");
	resize(400, 300);

	//建立物件
	outputLabel = new QLabel("尚未執行任何動作", this);
	outputLabel->setWordWrap(true);

	targetInputText = new QLineEdit(this);

	f_button = new QPushButton("獲取最上層視窗資訊", this);
	s_button = new QPushButton("secound_button", this);
	thi_button = new QPushButton("third_button", this);
	m_exit_button = new QPushButton("Exit, this",this);

	//排版
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(targetInputText);
	layout->addWidget(f_button);
	layout->addWidget(s_button);
	layout->addWidget(thi_button);
	layout->addWidget(m_exit_button);
	layout->addWidget(outputLabel);

	// 初始化 QTimer
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &MainWindow::checkWindowTimeout);

	//接線
	connect(f_button, &QPushButton::clicked, this, &MainWindow::toggleCheckForegroundWindow);

}
// 功能:在UI的顯示欄顯示
void MainWindow::showMessage(const QString& text) {
	outputLabel->setText(text);
}
//觸發函式(測試用)
// 切換開關邏輯
void MainWindow::toggleCheckForegroundWindow() {
	if (!m_isMonitoring) {
		m_isMonitoring = true;
		f_button->setText("停止監聽視窗");
		m_timer->start(200); // 每 200ms 觸發一次
		showMessage(QString::fromUtf8("開始監聽前景視窗..."));
	}
	else {
		m_isMonitoring = false;
		m_timer->stop();
		f_button->setText("獲取最上層視窗資訊");
		showMessage(QString::fromUtf8("已停止監聽。"));
	}
}

void MainWindow::checkWindowTimeout() {

}


void MainWindow::onSecond() {
	// 暫時空著

}

void MainWindow::onThird() {
	// 暫時空著
}
