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
	f_button = new QPushButton("first_button", this);
	s_button = new QPushButton("secound_button", this);
	thi_button = new QPushButton("third_button", this);

	//排版
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(f_button);
	layout->addWidget(s_button);
	layout->addWidget(thi_button);
}