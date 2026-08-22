
#include "include/wnd_helper/wnd_helper.hpp"
#include <iostream>	
#include <cstdint>
#include <unordered_map>

AppController::AppController() {

	// UTF-8 eecoding
	system("chcp 65001 > nul");
	menuMap[1] = [this]() {this->doTaskA();};

}

void AppController::run() {
	loop();
};

void AppController::doTaskA() {
	std::cout << "TEST";
};
void AppController::loop() {
	int choice = 0;

	while (true) {
		// show menu

		// get inpput
		std::cin >> choice;
		// evaluating what user want

		if (choice == 4) break;

		if (menuMap.count(choice)) {
			menuMap[choice];
		}
		else {
			std::cout << "錯誤輸入";
		}

	}

};