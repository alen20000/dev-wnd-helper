#pragma once
#include "logic/MagnifierHandle.hpp"

#include <windows.h>

class MagnifierController {
public:
	MagnifierController() = default;

	/**
	 * @brief 啟動放大鏡功能
	 * @param hwndMagContainer 放大鏡容器的窗口句柄
	 * @return 如果啟動成功，返回 true；否則返回 false
	 */
	bool startMagnifier(HWND hwndMagContainer, int width, int height);


	// 初始化
	MagnifierHandle m_magnifierHandle;
private:


};