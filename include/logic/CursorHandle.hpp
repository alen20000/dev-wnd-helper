#pragma once
#include <Windows.h>
class CursorHandle {

public:

    /**
    * @brief 獲取游標位置
    * @param point 用於返回游標位置的POINT結構
    * @return 如果成功獲取游標位置則返回true，否則返回false
    */
	bool getCursorPos(POINT& point) const;

private:

};