#include "controller/Appcontroller.hpp"
#include "logic/WndHandle.hpp"
#include <iostream>	
#include <cstdint>
#include <unordered_map>
#include <windows.h>

AppController::AppController() {

	// UTF-8 eecoding
	system("chcp 65001 > nul");
	menuMap[1] = [this]() {this->handleBindForegroundWindow();};

}

void AppController::run() {
	loop();
}

void AppController::handleBindForegroundWindow() {
	HWND lastHwnd = nullptr;

	bool m_isListing = true;
	while (m_isListing) {
		HWND hwnd = WndHandle::bindForegroundWindow();
		if (hwnd != lastHwnd) {
			std::cout << "窗柄為:" << reinterpret_cast<uintptr_t>(hwnd) << std::endl;
			lastHwnd = hwnd;
		}
		Sleep(200);
	}
}

void AppController::loop() {
	int choice = 0;

	while (true) {
		// show menu

		// get inpput
		std::cout << "請輸入:\n";
		std::cin >> choice;
		// evaluating what user want
		if (choice == 4) break;

		if (menuMap.count(choice)) {
			menuMap[choice]();
		}
		else {
			std::cout << "錯誤輸入";
		}

		Sleep(50);
	}

}