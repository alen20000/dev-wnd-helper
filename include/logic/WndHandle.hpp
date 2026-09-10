#pragma once
#include "DataTypes.hpp"
#include <string>
#include <windows.h> 
#include <utility>
#include <vector>

/**
 * @brief 
 *
 * 這個類別封裝了 Win32 視窗操作的底層細節，
 * 讓上層(controller)不需要直接接觸 HWND 或 Win32 API。
 */
class WndHandle {
private:
    HWND window_hwnd; // 儲存目標視窗的控制代碼

public:
    WndHandle();

    /**
     * @brief 抓取當前最上層(前景)視窗的控制代碼與標題
     * @return pair，first 為 HWND，second 為視窗標題；
     *         若找不到前景視窗則回傳 {nullptr, L""}
     */
    static std::pair<HWND, std::wstring> bindForegroundWindow();


    /**
     * @brief 列出目前所有符合篩選條件的頂層視窗
     * @return 每個元素包含視窗控制代碼與標題的清單
     * @note 篩選規則：排除不可見、無標題、工具列、有母視窗的視窗
     */
    static std::vector<WindowDetailInfo> listAllTopLevelWindows();


    /**
	 * @brief 找出指定標題的視窗控制代碼
     * @return 
     * @note 
     */
    static HWND getWindowHandle(const std::wstring& windowTitle);

};

