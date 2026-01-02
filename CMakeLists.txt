cmake_minimum_required(VERSION 4.1.2)

project(Enigma)

if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")
endif()


find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

qt6_wrap_ui(UI_HEADERS ui/mainwindow.ui)

set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    src/mainwindow.h
)

set(UIS
    ui/mainwindow.ui
)

qt_add_executable(Enigma
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

target_include_directories(Enigma PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/ui
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(Enigma PRIVATE
    Qt6::Widgets
)