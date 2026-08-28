#pragma once
#define WIN32_LEAN_AND_MEAN  // 排除微軟少用、又肥的標頭檔
#define NOMINMAX //關掉微軟的全域 min/max 巨集
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
    // 輸入窗口標題，判斷有沒有這窗口
    // Args:
    //      窗口標題
    //Return:
    //      true|false
    window_hwnd = FindWindowW(nullptr, windowTitle.c_str());

    if (window_hwnd != nullptr) {

        return true;
    }
    else {

        return false;
    }
}

