#include "logic/CursorHandle.hpp"

bool CursorHandle::getCursorPos(POINT& point) const {
	return GetCursorPos(&point); // windows API函數，得到鼠標位置
}