
# require Cmake version
cmake_minimum_required(VERSION 3.15)

project(wnd-helper)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# let MSVC could support UTF-8
if(MSVC)
    add_compile_options(/utf-8)
endif()

set (WINDOW_SOURCES
    "src/logic/WndHandle.cpp"
)
set(CONTROLLER
    "src/controller/AppController.cpp"
)
add_executable(wnd-helper 
    main.cpp
    ${WINDOW_SOURCES}
    ${CONTROLLER}
)



target_include_directories(wnd-helper PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
