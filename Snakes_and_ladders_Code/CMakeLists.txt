cmake_minimum_required(VERSION 3.5)

project(Snakes_and_ladders LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#SET(GUI_TYPE WIN32)
#add_executable(Snakes_and_ladders $(GUI_TYPE) ${PROJECT_SOURCES})

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()



find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
	game.cpp
	game.h
	game.ui
	chooseplayers.cpp
	chooseplayers.h
        chooseplayers.ui
        board_Path.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Snakes_and_ladders WIN32
        ${PROJECT_SOURCES})
    #add_executable(Snakes_and_ladders WIN32 ${PROJECT_SOURCES})

else()
    if(ANDROID)
        add_library(Snakes_and_ladders SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Snakes_and_ladders
            ${PROJECT_SOURCES})
        qt_add_executable(Snakes_and_ladders WIN32 ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Snakes_and_ladders PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
