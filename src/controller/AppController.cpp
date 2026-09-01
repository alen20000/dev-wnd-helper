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
#include <limits> 
AppController::AppController() {



}

WindowDetailInfo AppController::handleBindForegroundWindow(const std::wstring& windowTitle) {

	HWND lastHwnd = nullptr;
	bool m_isListing = true;

	//自定義結構容器
	WindowDetailInfo detailInfo{};

	while (m_isListing) {
		auto [hwnd, title] = WndHandle::bindForegroundWindow();

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