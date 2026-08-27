#include "controller/AppController.hpp"
#include <iostream>
#include <cstdint>

int main() {
	//UTF-8 編碼
	system("chcp 65001 > nul");
	//實例化物件
	AppController controller;


	controller.run();


	return 0;
}