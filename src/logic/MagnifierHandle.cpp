#include "logic/MagnifierHandle.hpp"

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

bool MagnifierHandle::createMagnifierWindow(HWND hwndParent) {
	m_hwndMag = CreateWindowEx(
		0, // Extended window style
		WC_MAGNIFIER, // API 對定義好的視窗常數
		TEXT("MagnifierWindow"), // Window title
		WS_CHILD | WS_VISIBLE, // Window style
		0, 0, // 滑鼠位置
		120, 120, // 視窗寬高
		hwndParent, // Parent window handle
		NULL, // 子視窗選單
		NULL, 
		NULL 
	);
	return m_hwndMag != nullptr;
}