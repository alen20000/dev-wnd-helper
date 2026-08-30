#include <unordered_map>
#include <functional>
#include <string>

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
    std::wstring handleBindForegroundWindow(const std::wstring& windowTitle);
    //啟動控制器
    void run();

};