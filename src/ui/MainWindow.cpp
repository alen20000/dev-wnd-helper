#include "ui\MainWindow.hpp
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent) //初始化父類或成員變數
{
	//視窗大小預設
	setWindowTitle("測試視窗");
	resize(400, 300);
}