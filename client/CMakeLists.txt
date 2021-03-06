cmake_minimum_required(VERSION 3.7)
project(Client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

if (NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

include_directories(include)

set(SOURCE_FILES source/app.cpp source/mainwindow.cpp include/mainwindow.h source/photoset.cpp include/photoset.h source/photosetscontroller.cpp include/photosetscontroller.h include/streamdisplay.h source/streamdisplay.cpp)
add_executable(Client ${SOURCE_FILES})

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)
qt5_use_modules(Client Core Widgets Gui)

add_subdirectory(libs/localfilemanager)
include_directories(libs/localfilemanager/include)
target_link_libraries(Client localfilemanager)

add_subdirectory(libs/uiutility)
include_directories(libs/uiutility/include)
target_link_libraries(Client uiutilitylib)

add_subdirectory(libs/photostream)
include_directories(libs/photostream/include)
target_link_libraries(Client photostream)

add_subdirectory(libs/clientnetwork)
include_directories(libs/clientnetwork/include)
target_link_libraries(Client clientnetwork)
