#pragma once

#include <iostream>
#include <sstream>
#include <windows.h>

struct WindowDetailInfo {
    HWND windowHandle;         
    std::wstring windowTitle;  
};