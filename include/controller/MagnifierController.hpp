#pragma once
   
#include <windows.h>

class MagnifierController {
public:
	MagnifierController();

	/**
	 * @brief 啟動放大鏡功能
	 * @param hwndMagContainer 放大鏡容器的窗口句柄
	 * @return 如果啟動成功，返回 true；否則返回 false
	 */
	bool startMagnifier(HWND hwndMagContainer);

private:


};