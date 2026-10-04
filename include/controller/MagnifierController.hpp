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
	
	/**
	 * @brief 更新放大鏡的顯示內容
	 * @param hwndMagContainer 放大鏡容器的窗口句柄
	 * @param width 放大鏡容器的寬度
	 * @param height 放大鏡容器的高度
	 * @param zoomLevel 放大鏡的縮放級別
	 * @return 如果更新成功，返回 true；否則返回 false
	 */

	bool updateMagnifier(int width, int height, float zoomLevel);
	// 初始化
	MagnifierHandle m_magnifierHandle;
private:


};