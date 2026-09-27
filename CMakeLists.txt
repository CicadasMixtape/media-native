cmake_minimum_required(VERSION 4.3)

project(media_native)

set(CMAKE_CXX_STANDARD 20)

find_package(JNI REQUIRED)
find_package(CppWinRT CONFIG REQUIRED)

if (JNI_FOUND)
    message(STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message(STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

add_library(media_native SHARED main.cpp media.h)

target_include_directories(media_native PRIVATE ${JNI_INCLUDE_DIRS})

target_link_libraries(media_native PRIVATE ${JNI_LIBRARIES} Microsoft::CppWinRT WindowsApp.lib)