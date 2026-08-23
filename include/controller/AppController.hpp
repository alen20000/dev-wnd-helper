#include <unordered_map>
#include <functional>


class AppController {
private:

    std::unordered_map<int, std::function<void()>> menuMap;

    void loop();
    //獲取前景視窗句柄
    void handleBindForegroundWindow();

public:
    AppController();

    void run();

};