#pragma once

#include "DataTypes.hpp"
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>
#include <windows.h>

class AppController {
private:
    HWND m_lastHwnd = nullptr;



public:
    AppController();

    //獲取前景視窗句柄
    WindowDetailInfo handleBindForegroundWindow(); 
    
    std::vector<WindowDetailInfo> getAllWindows();

    HWND getWindowByTitle(const std::wstring& windowTitle);

};