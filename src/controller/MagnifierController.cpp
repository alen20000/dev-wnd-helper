#include "controller/MagnifierController.hpp"

#include <iostream>

bool MagnifierController::startMagnifier(HWND hwndMagContainer,int width, int height) {

	if (!m_magnifierHandle.initialize()) {
		std::cerr << "初始化失敗" << std::endl;
		return false;
	}
	if (!m_magnifierHandle.createMagnifierWindow(hwndMagContainer, width, height)) {
		std::cerr << "創建放大鏡視窗失敗" << std::endl;
		return false;
	}
    return true;
}

bool MagnifierController::updateMagnifier(int width, int height, float zoomLevel) {

	m_magnifierHandle.updateMagnifier(width, height, zoomLevel);
	return true;
}

bool MagnifierController::stopMagnifier() {

	m_magnifierHandle.destroyMagnifierWindow();
	return true;
}