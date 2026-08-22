#include "include/wnd_helper/wnd_helper.hpp"
#include <iostream>
#include <cstdint>

int main() {
	//UTF-8 編碼
	system("chcp 65001 > nul");
	//實例化物件
	WinController controller;
	//變數
	int choice = 0;
	std::wstring win_title;

	std::cout << "\n=======命令面板=======\n";
	std::cout << "1. 抓取當前最上層視窗";
	std::cout << "2. 尋找指定視窗";
	std::cout << "輸入操作(1-2):";
	std::cin >> choice;

	if (choice == 1) {
		controller.bindForegroundWindow();
		std::cout << (long long)controller.getWindowHandle() << std::endl;
	}
	else if (choice == 2) {
		std::cout << "輸入窗口名稱:";
		std::wcin.ignore();
		std::getline(std::wcin, win_title);
		controller.findTargetWindow(win_title);
	};


	return 0;
}