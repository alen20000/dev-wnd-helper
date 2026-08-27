#include "controller/Appcontroller.hpp"
#include "logic/WndHandle.hpp"
#include <iostream>	
#include <cstdint>
#include <unordered_map>
#include <windows.h>
#include <vector>

AppController::AppController() {

	// UTF-8 eecoding
	system("chcp 65001 > nul");
	// 要印中文，就要用寬字元；要印寬字元，就要改 local，所以要加下面這行，不然就全空白給你，也不報錯
	std::locale::global(std::locale("zh_TW.UTF-8"));
	menuMap[1] = [this]() {this->handleBindForegroundWindow();};

}

void AppController::run() {
	loop();
}

void AppController::loop() {
	int choice = 0;

	while (true) {
		// show menu

		// get inpput
		showMenu();

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

//先用最簡單的，未來改UI，則改在hpp宣告，用push_back動態添加
void AppController::showMenu() {
	std::vector<std::wstring>menuTests = {
		(L"1. 綁定前景視窗"),
		(L"2. 尋找目標視窗"),
		(L"4. 離開程式")
	};

	for (const auto& text : menuTests) {
		std::wcout << text << std::endl;
	}

	std::cout << "請輸入:";

}

void AppController::handleBindForegroundWindow() {
	HWND lastHwnd = nullptr;

	bool m_isListing = true;
	while (m_isListing) {
		auto [hwnd, title] = WndHandle::bindForegroundWindow();
		if (hwnd != lastHwnd) {

			// 如果標題裡面包含路徑的斜線 '\'，我們就隻取最後面那一段乾淨的名字
			size_t pos = title.find_last_of(L"\\");
			if (pos != std::wstring::npos) {
				title = title.substr(pos + 1); // 把路徑切掉，只留檔名或最後的名稱
			}

			std::wcout << L"窗柄為:" << reinterpret_cast<uintptr_t>(hwnd) 
						<< L"窗口名稱:"<< title<< std::endl;

			lastHwnd = hwnd;
		}
		Sleep(200);
	}
}