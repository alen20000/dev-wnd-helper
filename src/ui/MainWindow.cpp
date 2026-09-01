#include "ui\MainWindow.hpp"
#include "controller\AppController.hpp"
#include "DataTypes.hpp"
#include <QWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent) //初始化父類或成員變數
{
	//視窗大小預設
	setWindowTitle("Tool Box");
	resize(400, 300);
	
	//	頂部工具列
	QToolBar* toolBar = addToolBar("Top Toolbar");
	toolBar->setMovable(false);

	m_exit_button = new QPushButton("Exit, this",this);
	connect(m_exit_button, &QPushButton::clicked, this, &QWidget::close);

	//	中央視窗與主板
	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);
	QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);

	//互動元件
	targetInputText = new QLineEdit(this);
	targetInputText->setPlaceholderText("輸入視窗關鍵字...");
	mainLayout->addWidget(targetInputText);

	m_btnGetForegroundInfo = new QPushButton("獲取最上層視窗資訊", this);
	mainLayout->addWidget(m_exit_button);

	// 



	//排版
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(targetInputText);
	layout->addWidget(m_btnGetForegroundInfo);



	// 初始化 QTimer
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &MainWindow::checkWindowTimeout);

	//接線
	connect(m_btnGetForegroundInfo, &QPushButton::clicked, this, &MainWindow::toggleCheckForegroundWindow);
}

void MainWindow::toggleCheckForegroundWindow() {

	std::cout << "testing";
}

void MainWindow::checkWindowTimeout() {

	std::cout << "timeout";
}