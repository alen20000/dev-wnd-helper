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

	tb_exitBtn = new QPushButton("離開", toolBar);
	toolBar->addWidget(tb_exitBtn);
	connect(tb_exitBtn, &QPushButton::clicked, this, &QWidget::close);

	//	中央視窗與主板
	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);
	QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);


	// 左側垂直版(按鈕)
	QVBoxLayout* leftLayout = new QVBoxLayout();


	m_btnGetForegroundInfo = new QPushButton("獲取最上層視窗資訊", centralWidget);
	leftLayout->addWidget(m_btnGetForegroundInfo);
	connect(m_btnGetForegroundInfo, &QPushButton::clicked, this, &MainWindow::toggleCheckForegroundWindow);

	leftLayout->addStretch();

	// 右側垂直版(欄位)
	QVBoxLayout* rightLayout = new QVBoxLayout();

	targetInputText = new QLineEdit();
	rightLayout->addWidget(targetInputText);
	targetInputText->setPlaceholderText("輸入視窗關鍵字...");


	//合併版面
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);


	// 初始化 QTimer
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &MainWindow::checkWindowTimeout);


}

void MainWindow::toggleCheckForegroundWindow() {

	std::cout << "testing";
}

void MainWindow::checkWindowTimeout() {

	std::cout << "timeout";
}