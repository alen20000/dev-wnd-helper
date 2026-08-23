#pragma once
#include "logic/WndHandle.hpp"
#include <iostream>
#include <windows.h>

WndHandle::WndHandle() : window_hwnd(nullptr) {}

HWND WndHandle::bindForegroundWindow() {
    // 透過處於最前端，找尋視窗與標題
    return ::GetForegroundWindow();
}


bool WndHandle::findTargetWindow(const std::wstring& windowTitle) {
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

