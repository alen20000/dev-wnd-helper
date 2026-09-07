
# require Cmake version
cmake_minimum_required(VERSION 3.15)

# ===== 名稱 =====
project(manual_check.cpp)
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
add_executable(manual_check.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/manual_check.cpp

    ${window_sources}


)

#   標頭檔搜尋路徑
target_include_directories(manual_check.cpp PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)


