#include "controller/MagnifierController.hpp"

#include <iostream>

bool MagnifierController::startMagnifier(HWND hwndMagContainer,int width, int height) {
    // Implementation for starting magnifier
	std::cout << "TEST:" << hwndMagContainer << std::endl;
	
	if (!m_magnifierHandle.initialize()) {
		std::cerr << "初始化失敗" << std::endl;
		return false;

	}
	
	if (!m_magnifierHandle.createMagnifierWindow(hwndMagContainer, width, height)) {
		std::cerr << "創建放大鏡視窗失敗" << std::endl;
		return false;
	}
	std::cout << "放大鏡啟動成功" << std::endl;
    return true;
}

bool MagnifierController::updateMagnifier(int width, int height, float zoomLevel) {

	m_magnifierHandle.updateMagnifier(width, height, zoomLevel);
	return true;
}