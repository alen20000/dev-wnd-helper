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

WindowDetailInfo AppController::handleBindForegroundWindow() {
	//獲取前景視窗與句柄


	//自定義結構容器
	WindowDetailInfo detailInfo{};


	auto [hwnd, title] = WndHandle::bindForegroundWindow();

	detailInfo.windowHandle = hwnd;


	if (hwnd == m_lastHwnd) {
		detailInfo.windowHandle = nullptr;
		detailInfo.windowTitle = L"";
		return detailInfo;

	}
	m_lastHwnd = hwnd;
	// 文字處理
	size_t pos = title.find_last_of(L"\\");
	if (pos != std::wstring::npos) {
		title = title.substr(pos + 1); 
	}
	detailInfo.windowTitle = title;
	return detailInfo;

}

std::vector<WindowDetailInfo> AppController::getAllWindows() {
	//得到所有可見視窗語句柄
	std::vector<WindowDetailInfo> windowList;
	windowList = WndHandle::listAllTopLevelWindows();
	return windowList;
}


HWND AppController::getWindowByTitle(const std::wstring& windowTitle) {

	HWND hwnd = WndHandle::getWindowHandle(windowTitle);
	return hwnd;
}	