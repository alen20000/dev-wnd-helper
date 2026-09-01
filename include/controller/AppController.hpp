#pragma once

#include <unordered_map>
#include <functional>
#include <string>
#include "DataTypes.hpp"
class AppController {
private:

    bool m_isListing = false;
    std::unordered_map<int, std::function<void()>> menuMap;
    // 管理CLI顯示內容
    void showMenu();


    void handleFindTargetWindow();

    //進入迴圈
    void loop();

public:
    AppController();

    //獲取前景視窗句柄
    WindowDetailInfo handleBindForegroundWindow(const std::wstring& windowTitle);
    //啟動控制器
    void run();

};