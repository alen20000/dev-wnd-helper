
# require Cmake version
cmake_minimum_required(VERSION 3.15)

# ===== 專案名稱 =====
project(wnd-helper)
# ===== 前置設定 =====

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(MSVC) # MSVC 支援 utf-8
    add_compile_options(/utf-8)
endif()

# ===== 找外部套件 =====

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# =======================

# ====== 原始檔案變數 ===
set (window_sources
    "src/logic/WndHandle.cpp"
)
set(controller_sources
    "src/controller/AppController.cpp"
)
# =======================
add_executable(wnd-helper 
    main.cpp
    ${window_sources}
    ${controller_sources}
)

#   標頭檔搜尋路徑
target_include_directories(wnd-helper PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ===== 連結動態庫 =====
target_link_libraries(wnd-helper PRIVATE Qt6::Core Qt6::Widgets)
