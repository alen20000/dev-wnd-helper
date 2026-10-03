#pragma once

#include <windows.h>
#include <magnification.h>

/**
 * @brief
 *
 * 這個類別封裝了 windows 內建 Magnification API 的核心邏輯類別
 */

class MagnifierHandle {
public:
	MagnifierHandle();
	~MagnifierHandle();

	// @brief 初始化 magnifier 
	bool initialize();

	// @brief 銷毀 magnifier 視窗
	void destroyMagnifierWindow();

	// @brief 建立視窗
	bool createMagnifierWindow(HWND m_hwndParent, int width, int height);

	// @brief 更新 magnifier
	void updateMagnifier(HWND hwndMagContainer, int width, int height, float zoomLevel);

private:

	// @brief 父視窗的句柄
	HWND m_hwndMag;
};