#pragma once

#include <unordered_map>
#include <functional>
#include <string>
#include "DataTypes.hpp"
class AppController {
private:
    HWND m_lastHwnd = nullptr;



public:
    AppController();

    //獲取前景視窗句柄
    WindowDetailInfo handleBindForegroundWindow(); 
    void handleFindTargetWindow();

};