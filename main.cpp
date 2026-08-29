#include "controller/AppController.hpp"
#include "ui/MainWindow.hpp"
#include <QApplication>
int main(int argc, char* argv[]) {

	//實例化物件
	QApplication app(argc, argv);  //Qt盡量優先
	AppController controller;

	MainWindow window;
	window.show();

	// 回傳觸發 .exec() 啟動迴圈  
	return app.exec();
}