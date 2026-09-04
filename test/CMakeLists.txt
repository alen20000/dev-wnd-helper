
# require Cmake version
cmake_minimum_required(VERSION 3.15)

# ===== 專案名稱 =====
project(wnd-helper-testing)
# ===== 前置設定 =====

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(MSVC) # MSVC 支援 utf-8
    add_compile_options(/utf-8)
endif()

# =======================

# ====== 原始檔案變數 ===
set (window_sources
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/logic/WndHandle.cpp"
)
set(controller_sources
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/controller/AppController.cpp"
)
set(ui_sources
    "${CMAKE_CURRENT_SOURCE_DIR}/../src/ui/MainWindow.cpp"
)
# =======================
add_executable(wnd-helper-testing
    ${CMAKE_CURRENT_SOURCE_DIR}/test_main.cpp

    ${window_sources}


)

#   標頭檔搜尋路徑
target_include_directories(wnd-helper-testing PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)


