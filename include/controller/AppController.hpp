#include <unordered_map>
#include <functional>


class AppController {
private:

    bool m_isListing = false;
    std::unordered_map<int, std::function<void()>> menuMap;
    // 管理CLI顯示內容
    void showMenu();

    //獲取前景視窗句柄
    void handleBindForegroundWindow();

    //進入迴圈
    void loop();

public:
    AppController();

    //啟動控制器
    void run();

};