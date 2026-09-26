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

	bool initialize(HWND parentHwnd);
};