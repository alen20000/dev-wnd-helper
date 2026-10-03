#include "logic/MagnifierHandle.hpp"

// @brief 建構子，初始化成員變數
MagnifierHandle::MagnifierHandle() : m_hwndMag(nullptr) {}

MagnifierHandle::~MagnifierHandle() {
    void destroyMagnifierWindow();
}



void MagnifierHandle::destroyMagnifierWindow() {
	if (m_hwndMag) {
		DestroyWindow(m_hwndMag);
		m_hwndMag = nullptr;
	}
}