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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


add_executable(IESAA
    src/IESAA.cpp
    src/IESAA.h

    src/IESAAError.cpp
    src/IESAAError.h

    src/IProfile.cpp
    src/IProfile.h

    src/FieldWidgets.h
    src/FieldWidgets.cpp

    src/AssociativePair.inl
    src/AssociativePair.h

    src/DefaultFieldDataBase.cpp
    src/DefaultFieldDataBase.h

    src/FieldWidgets/IFieldWidget.h
    src/FieldWidgets/FieldLineEdit.cpp
    src/FieldWidgets/FieldLineEdit.h

    src/IField.cpp
    src/IField.inl
    src/IField.h

    src/LocalDB.cpp
    src/LocalDB.inl
    src/LocalDB.h

    src/FieldTableManager.cpp
    src/FieldTableManager.h

    src/DefaultFieldsCreator.cpp
    src/DefaultFieldsCreator.h

    src/FieldCreator.cpp
    src/FieldCreator.h
    src/NamesSetsManager.cpp
    src/NamesSetsManager.h

    src/windows/IESAAWindow.cpp
    src/windows/IESAAWindow.h
    ui/IESAAWindow.ui

    src/windows/AuthorizationWindow/AuthorizationWindow.cpp
    src/windows/AuthorizationWindow/AuthorizationWindow.h
    src/windows/AuthorizationWindow/MessageBar.cpp
    src/windows/AuthorizationWindow/MessageBar.h
    ui/AuthorizationWindow.ui

    src/windows/SettingsWindow/SettingsWindow.cpp
    src/windows/SettingsWindow/SettingsWindow.h
    ui/SettingsWindow.ui

    src/windows/PFCreationWindow/PFCreationWindow.cpp
    src/windows/PFCreationWindow/PFCreationWindow.h
    src/windows/PFCreationWindow/PFCreationHelper.cpp
    src/windows/PFCreationWindow/PFCreationHelper.h
    ui/PFCreationWindow.ui

    src/windows/LogsWindow/LogsWindow.cpp
    src/windows/LogsWindow/LogsWindow.h
    ui/LogsWindow.ui

    src/windows/AboutIESAAWindow/AboutIESAAWindow.cpp
    src/windows/AboutIESAAWindow/AboutIESAAWindow.h
    ui/AboutIESAAWindow.ui

    src/windows/ProfileCreationWindow/ProfileCreationWindow.cpp
    src/windows/ProfileCreationWindow/ProfileCreationWindow.h
    src/windows/ProfileCreationWindow/ProfileCreationHelper.cpp
    src/windows/ProfileCreationWindow/ProfileCreationHelper.h
    ui/ProfileCreationWindow.ui

    src/windows/GroupManagementWindow/GroupManagementWindow.cpp
    src/windows/GroupManagementWindow/GroupManagementWindow.h
    ui/GroupManagementWindow.ui

    src/windows/StaffWindow/StaffWindow.cpp
    src/windows/StaffWindow/StaffWindow.h
    ui/StaffWindow.ui

    src/windows/StatisticsWindow/StatisticsWindow.cpp
    src/windows/StatisticsWindow/StatisticsWindow.h
    ui/StatisticsWindow.ui

    src/windows/PostCreationWindow/PostCreationWindow.cpp
    src/windows/PostCreationWindow/PostCreationWindow.h
    ui/PostCreationWindow.ui

    src/windows/EmployeeDefinitionWindow/EmployeeDefinitionWindow.cpp
    src/windows/EmployeeDefinitionWindow/EmployeeDefinitionWindow.h
    ui/EmployeeDefinitionWindow.ui

    res/Res.qrc

    libs/ONF_v0.0.0/include/IdManagement.h
)

target_include_directories(IESAA PRIVATE src)

target_link_libraries(IESAA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
