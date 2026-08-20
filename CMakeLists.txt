
cmake_minimum_required(VERSION 3.15)


project(GetGameWindow)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# left MSVC support UTF-8
if(MSVC)
    add_compile_options(/utf-8)
endif()


add_executable(GetGameWindow 
    main.cpp
    src/WinController.cpp
    src/WinController.hpp
)
target_include_directories(GetGameWindow PRIVATE src)
