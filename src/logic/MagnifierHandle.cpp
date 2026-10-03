#include "logic/MagnifierHandle.hpp"
#include <algorithm>
// @brief 建構子，初始化成員變數
MagnifierHandle::MagnifierHandle() : m_hwndMag(nullptr) {}

MagnifierHandle::~MagnifierHandle() {
    destroyMagnifierWindow();
}

bool MagnifierHandle::initialize() {
	return MagInitialize();
}

void MagnifierHandle::destroyMagnifierWindow() {
	if (m_hwndMag) {
		DestroyWindow(m_hwndMag);
		m_hwndMag = nullptr;
	}
}

bool MagnifierHandle::createMagnifierWindow(HWND hwndParent, int width, int height) {

	// 計算放大鏡視窗的大小
	int size = std::min(width, height);
	int x = (width - size) / 2;
	int y = (height - size) / 2;

	// 建立放大鏡視窗
	m_hwndMag = CreateWindowEx(
		0, // Extended window style
		WC_MAGNIFIER, // API 對定義好的視窗常數
		TEXT("MagnifierWindow"), // Window title
		WS_CHILD | WS_VISIBLE, // Window style
		x, y, // top-left 座標
		size, size, // 視窗寬高
		hwndParent, // Parent window handle
		NULL, // 子視窗選單
		NULL, 
		NULL 
	);
	return m_hwndMag != nullptr;
}