#   === Базовая настройка ===
cmake_minimum_required(VERSION 3.5)
project(IESAA LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

#   =====================

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

#set(TS_FILES localization/IESAA_ru_RU.ts)



add_executable(IESAA
  src/IESAA.cpp

  src/windows/IESAAWindow.cpp
  src/windows/IESAAWindow.h
  ui/IESAAWindow.ui

  src/windows/AuthorizationWindow.cpp
  src/windows/AuthorizationWindow.h
  ui/AuthorizationWindow.ui

  res/Res.qrc

#  ${TS_FILES}
)

target_include_directories(IESAA PRIVATE src/windows)

target_link_libraries(IESAA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

#qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ../../${TS_FILES})
