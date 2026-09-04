#include "logic/WndHandle.hpp"
#include "DataTypes.hpp"
#include <iostream>
#include <vector>
//測試用


int main() {
	// 強制切換 Windows 主控台為 UTF-8 編碼
	system("chcp 65001 > nul");

	// 設定全域地區支援繁體中文 UTF-8
	std::locale::global(std::locale("zh_TW.UTF-8"));
	std::cout << "測試開始" << std::endl;
	std::vector<WindowDetailInfo> windows = WndHandle::listAllTopLevelWindows();
	for (const auto& window : windows) {
		std::wcout << L"視窗句柄: " << window.windowHandle << L", 標題: " << window.windowTitle << std::endl;
	}
	return 0;
}