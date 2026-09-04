#pragma once

#include "DataTypes.hpp"
#include <unordered_map>
#include <functional>
#include <string>
class AppController {
private:
    HWND m_lastHwnd = nullptr;



public:
    AppController();

    //獲取前景視窗句柄
    WindowDetailInfo handleBindForegroundWindow(); 
    void handleFindTargetWindow();

};