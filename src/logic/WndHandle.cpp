#pragma once
#define WIN32_LEAN_AND_MEAN  // 排除微軟少用、又肥的標頭檔
#define NOMINMAX //關掉微軟的全域 min/max 巨集
#include "logic/WndHandle.hpp"
#include "DataTypes.hpp"
#include <iostream>
#include <windows.h>
#include <string>
#include <utility>
#include <vector>

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


// 匿名空間
namespace  {
    struct EnumContext {
        std::vector<WindowDetailInfo> windows;
    };
    //微軟作業系統的 回傳函式
    BOOL CALLBACK InternalEnumProc(HWND hwnd, LPARAM lParam) {

        // 過濾背景視窗
		if (IsWindowVisible(hwnd)) {
			wchar_t buffer[256];
			int length = GetWindowTextW(hwnd, buffer, 256);
			if (length > 0) {
				EnumContext* context = reinterpret_cast<EnumContext*>(lParam);
				context->windows.push_back({ hwnd, std::wstring(buffer) });
			}
		}
		return TRUE; // 繼續列舉
    };
}
std::vector<WindowDetailInfo> WndHandle::listAllTopLevelWindows() {
	// 顯示目前所有頂層視窗
    EnumContext context;
    EnumWindows(InternalEnumProc, reinterpret_cast<LPARAM>(&context));
    return context.windows;
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

