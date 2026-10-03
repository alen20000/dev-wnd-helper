#pragma once

#include "DataTypes.hpp"
#include <unordered_map>
#include <functional>
#include <string>
#include <vector>

#include <windows.h>
/**
 * @brief
 * 主司應用程式、視窗的控制器
 */
class AppController {
private:
    HWND m_lastHwnd = nullptr;



public:
    AppController() = default;

    //獲取前景視窗句柄
    WindowDetailInfo handleBindForegroundWindow(); 
    
    std::vector<WindowDetailInfo> getAllWindows();

    HWND getWindowByTitle(const std::wstring& windowTitle);

};