#pragma once

#include <string>
#include <windows.h> 
#include <unordered_map>
#include <functional>

class WndHandle {
private:
    HWND window_hwnd; // 儲存目標視窗的控制代碼

public:
    WndHandle();

    // 直接抓取當前最上層視窗
    static HWND bindForegroundWindow();

    // 尋找目標視窗
    bool findTargetWindow(const std::wstring& windowTitle);

    HWND getWindowHandle() const { return window_hwnd; }

};

class AppController {
private:

    std::unordered_map<int, std::function<void()>> menuMap;
    //視窗迴圈
    void loop();
    //預設:任務A
    void handleBindForegroundWindow();

public:
    AppController();

    void run();

};