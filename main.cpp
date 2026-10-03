#include "controller/AppController.hpp"
#include "ui/MainWindow.hpp"
#include <QApplication>
int main(int argc, char* argv[]) {
	// 命令提示字元強制切換為 UTF-8 編碼
	system("chcp 65001 > nul");
	//實例化物件
	QApplication app(argc, argv);  //Qt盡量優先
	AppController controller;

	MainWindow window;
	window.show();

	// 回傳觸發 .exec() 啟動迴圈  
	return app.exec();
}