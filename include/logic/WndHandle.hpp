#pragma once
#include "DataTypes.hpp"
#include <string>
#include <windows.h> 
#include <utility>
#include <vector>
class WndHandle {
private:
    HWND window_hwnd; // 儲存目標視窗的控制代碼

public:
    WndHandle();

    // 直接抓取當前最上層視窗
    static std::pair<HWND, std::wstring> bindForegroundWindow();


    // 顯示目前所有頂層視窗
    static std::vector<WindowDetailInfo> listAllTopLevelWindows();

    // 尋找目標視窗
    bool findTargetWindow(const std::wstring& windowTitle);

    HWND getWindowHandle() const { return window_hwnd; }

};

