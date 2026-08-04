cmake_minimum_required(VERSION 4.1.2)

project(Enigma)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
    src/enigma/EnigmaConfig.cpp
    src/enigma/EnigmaMachine.cpp
    src/enigma/Plugboard.cpp
    src/enigma/Reflector.cpp
    src/enigma/Rotor.cpp
    src/enigma/RotorHolder.cpp
)

set(HEADERS
    src/mainwindow.h
    src/enigma/Alphabet.h
    src/enigma/AlphabetMappings.h
    src/enigma/EnigmaConfig.h
    src/enigma/EnigmaMachine.h
    src/enigma/Plugboard.h
    src/enigma/Reflector.h
    src/enigma/Rotor.h
    src/enigma/RotorHolder.h
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