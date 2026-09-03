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


	m_btnGetForegroundInfo = new QPushButton("頂層視窗檢測", centralWidget);
	leftLayout->addWidget(m_btnGetForegroundInfo);
	connect(m_btnGetForegroundInfo, &QPushButton::clicked, this, &MainWindow::toggleCheckForegroundWindow);

	leftLayout->addStretch(); //

	// 右側垂直版(欄位)
	QVBoxLayout* rightLayout = new QVBoxLayout();

	targetInputText = new QLineEdit(); //輸入欄位
	rightLayout->addWidget(targetInputText);
	targetInputText->setPlaceholderText("輸入視窗關鍵字...");
	

	outputText = new QPlainTextEdit(); //輸出欄位
	rightLayout->addWidget(outputText);
	outputText->setReadOnly(true); // 設定為唯讀，禁止互動
	//  QTimer 代替原本CLI的輪詢
	m_timer = new QTimer(this);
	connect(m_timer, &QTimer::timeout, this, &MainWindow::doCheckForegroundWindow);


	//合併版面
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);




}
// 檢查前景視窗的按鈕開關:用計時器去觸發API函式
void MainWindow::toggleCheckForegroundWindow() {
	m_isMonitoring = !m_isMonitoring;  //True/False 交替

	if (m_isMonitoring) {
		//開啟檢測
		m_btnGetForegroundInfo->setText("停止檢測"); //更改按鈕文字
		m_timer->start(100); 
		outputText->appendPlainText("--- 開始檢測頂層視窗 ---");

	}
	else {
		m_btnGetForegroundInfo->setText("頂層視窗檢測");
		m_timer->stop();
		outputText->appendPlainText("--- 停止檢測頂層視窗 ---");
	}

}

void MainWindow::doCheckForegroundWindow() {

	WindowDetailInfo result = m_controller.handleBindForegroundWindow();
	outputText->appendPlainText(QString::fromStdWString(result.windowTitle));
}