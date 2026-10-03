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

void MagnifierHandle::updateMagnifier(HWND hwndMagContainer, int width, int height, float zoomLevel) {

	// 防呆檢查，確保放大鏡視窗已經建立
	if (!m_hwndMag) {
		return;
	}
	
	POINT Pt; // 定義一個 POINT 結構來存儲滑鼠座標

	if (!GetCursorPos(&Pt)) return; // 防呆

	// 計算放大鏡視窗的大小;float 轉為 int
	int srcWidth = static_cast<int>(width/ zoomLevel);
	int srcHeight = static_cast<int>(height/ zoomLevel);

	RECT sourceRect; // 定義一個矩形
	sourceRect.left = Pt.x - (srcWidth / 2);
	sourceRect.top = Pt.y - (srcHeight / 2);
	sourceRect.right = sourceRect.left + srcWidth;
	sourceRect.bottom = sourceRect.top + srcHeight;

	MagSetWindowSource(hwndMagContainer, sourceRect);

	MAGTRANSFORM transform;
	memset(&transform, 0, sizeof(transform));
	transform.v[0][0] = zoomLevel;
	transform.v[1][1] = zoomLevel;
	transform.v[2][2] = 1.0f;
	MagSetWindowTransform(hwndMagContainer, &transform);
}