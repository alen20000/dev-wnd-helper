#include "ui\MainWindow.hpp"
#include "controller\AppController.hpp"
#include "DataTypes.hpp"
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent) //初始化父類或成員變數
{
	//視窗大小預設
	setWindowTitle("Tool Box");
	resize(400, 300);

	//建立物件

	targetInputText = new QLineEdit(this);

	m_btnGetForegroundInfo = new QPushButton("獲取最上層視窗資訊", this);
	m_exit_button = new QPushButton("Exit, this",this);



	//排版
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(targetInputText);
	layout->addWidget(m_btnGetForegroundInfo);
	layout->addWidget(m_exit_button);


	// 初始化 QTimer
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &MainWindow::checkWindowTimeout);

	//接線
	connect(m_btnGetForegroundInfo, &QPushButton::clicked, this, &MainWindow::toggleCheckForegroundWindow);
	connect(m_exit_button, &QPushButton::clicked, this, &QWidget::close);
}

void MainWindow::toggleCheckForegroundWindow() {

	std::cout << "testing";
}

void MainWindow::checkWindowTimeout() {

	std::cout << "timeout";
}