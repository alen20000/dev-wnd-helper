#include "ui\MainWindow.hpp"
#include "controller\AppController.hpp"
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
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

	f_button = new QPushButton("first_button", this);
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

	//接線
	connect(f_button, &QPushButton::clicked, this, &MainWindow::onFirst);

}
// 功能:在UI的顯示欄顯示
void MainWindow::showMessage(const QString& text) {
	outputLabel->setText(text);
}
//觸發函式(測試用)
void MainWindow::onFirst() {
	QString userInput = targetInputText->text();
	if (userInput.isEmpty()) {
		this->showMessage("請先輸入視窗標題");
		return;
	}

	std::wstring windowTitle = userInput.toStdWString();
	AppController controller;

	std::wstring resultTitle = controller.handleBindForegroundWindow(windowTitle);

	this->showMessage(QString::fromStdWString(resultTitle));
}


void MainWindow::onSecond() {
	// 暫時空著

}

void MainWindow::onThird() {
	// 暫時空著
}
