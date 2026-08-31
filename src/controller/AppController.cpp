#define WIN32_LEAN_AND_MEAN  //預防加載到windos肥大的標頭檔
#define NOMINMAX //禁止使用微軟的max巨集

#include "controller/Appcontroller.hpp"
#include "logic/WndHandle.hpp"
#include "DataTypes.hpp"
#include <iostream>	
#include <cstdint>
#include <unordered_map>
#include <windows.h>
#include <vector>
#include <limits> // 需要引入這個來用 std::numeric_limits
AppController::AppController() {

	// UTF-8 eecoding
	system("chcp 65001 > nul");
	// 要印中文，就要用寬字元；要印寬字元，就要改 local，所以要加下面這行，不然就全空白給你，也不報錯
	std::locale::global(std::locale("zh_TW.UTF-8"));

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

WindowDetailInfo AppController::handleBindForegroundWindow(const std::wstring& windowTitle) {

	HWND lastHwnd = nullptr;
	bool m_isListing = true;

	//自定義結構容器
	WindowDetailInfo detailInfo{};

	while (m_isListing) {
		auto [hwnd, title] = WndHandle::bindForegroundWindow();

		if (hwnd != lastHwnd) {
			detailInfo.windowHandle = hwnd;
			// 文字處理
			size_t pos = title.find_last_of(L"\\");
			if (pos != std::wstring::npos) {
				title = title.substr(pos + 1); 
			}
			detailInfo.windowTitle = title;
			lastHwnd = hwnd;
			break;
		}
		Sleep(200);
	}
	return detailInfo;
}

void AppController::handleFindTargetWindow() {

	WndHandle myWindow;
	std::wstring windowTitle;

	std::cout << "輸入要找尋視窗標題:";

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::wcin, windowTitle);

	if (myWindow.findTargetWindow(windowTitle)) {
		std::cout << "有視窗";
	}
	else {
		std::cout << "沒有視窗";
	}
}	