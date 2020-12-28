cmake_minimum_required(VERSION 3.5)

project(QIFS LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets Gui REQUIRED)

set(SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

  ${CMAKE_CURRENT_SOURCE_DIR}/transformfunction.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/transformfunction.h
  ${CMAKE_CURRENT_SOURCE_DIR}/ifscalccore.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ifscalccore.h

  ${CMAKE_CURRENT_SOURCE_DIR}/ifsinput.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsinput.h
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsinput.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/transformfunctiondisplay.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/transformfunctiondisplay.h
  ${CMAKE_CURRENT_SOURCE_DIR}/transformfunctiondisplay.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsrenderdialog.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsrenderdialog.h
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsrenderdialog.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsrenderingwidget.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/ifsrenderingwidget.h
)

if(ANDROID)
  add_library(QIFS SHARED
    ${SOURCES}
  )
else()
  add_executable(QIFS
    ${SOURCES}
  )
endif()

target_link_libraries(QIFS PRIVATE Qt5::Widgets Qt5::Gui)
