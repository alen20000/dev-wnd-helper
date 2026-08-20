#include "WinController.hpp"
#include <iostream>
#include <windows.h>

WinController::WinController() : window_hwnd(nullptr) {}

bool WinController::bindForegroundWindow() {
    // 透過處於最前端，找尋視窗與標題
    window_hwnd = ::GetForegroundWindow();

    if (window_hwnd == nullptr) {
        return false;
    }
    return true;

}


bool WinController::findTargetWindow(const std::wstring& windowTitle) {
    // 透過視窗標題尋找視窗
    window_hwnd = FindWindowW(nullptr, windowTitle.c_str());

    if (window_hwnd != nullptr) {
        std::cout << "成功找到目標視窗！\n";
        return true;
    }
    else {
        std::cout << "找不到指定的視窗。\n";
        return false;
    }
}

