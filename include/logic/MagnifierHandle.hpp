#pragma once
#define WIN32_LEAN_AND_MEAN  
#define NOMINMAX     
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
	bool initialize(HWND parentHwnd);

private:

	// @brief 掛勾Qt視窗內的 magnifier 視窗
	HWND m_hMagWnd;
};