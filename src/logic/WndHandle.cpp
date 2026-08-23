#pragma once
#include "logic/WndHandle.hpp"
#include <iostream>
#include <windows.h>
#include <string>
#include <utility>
WndHandle::WndHandle() : window_hwnd(nullptr) {}

std::pair<HWND, std::wstring> WndHandle::bindForegroundWindow(){
    // 透過處於最前端，找尋視窗與標題
    HWND hwnd = ::GetForegroundWindow();

    if (hwnd == nullptr) {
        return { nullptr, L"" };  // "L" 表示空的寬字元字串 
    }
    wchar_t buffer[256];
    int length = GetWindowTextW(hwnd, buffer, 256);
    
    if (length > 0) {
        return { hwnd, std::wstring(buffer) }; // 自動轉成現代的 std::wstring
    };

    return { hwnd, L"" };
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

