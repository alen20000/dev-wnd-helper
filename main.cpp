#include "include/wnd_helper/wnd_helper.hpp"
#include <iostream>
#include <cstdint>

int main() {
	//UTF-8 編碼
	system("chcp 65001 > nul");
	//實例化物件
	AppController controller;

	std::cout << "入口測試";
	controller.run();


	return 0;
}