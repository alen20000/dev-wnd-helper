#include <unordered_map>
#include <functional>


class AppController {
private:

    bool m_isListing = false;
    std::unordered_map<int, std::function<void()>> menuMap;
    

    //獲取前景視窗句柄
    void handleBindForegroundWindow();
    void loop();

public:
    AppController();

    void run();

};