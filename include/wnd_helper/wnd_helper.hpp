#pragma once
#include <string>
#include <windows.h> 

class WinController {
private:
    HWND window_hwnd; // 儲存目標視窗的控制代碼

public:
    WinController();

    // 直接抓取當前最上層視窗
    bool bindForegroundWindow();

    // 尋找目標視窗
    bool findTargetWindow(const std::wstring& windowTitle);

    HWND getWindowHandle() const { return window_hwnd; }

};

