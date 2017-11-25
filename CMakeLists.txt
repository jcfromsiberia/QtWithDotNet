cmake_minimum_required(VERSION 3.5.0)

set(PROJECT_NAME QtWithDotNET)

project(${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets)

set(SOURCES main.cpp widget.cpp)
set(FORMS widget.ui)
set(HEADERS widget.h dotnetform.h)

set(MANAGED_SOURCES dotnetform.cpp)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${FORMS} ${HEADERS} ${MANAGED_SOURCES})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Setup .NET magic
set_source_files_properties(${MANAGED_SOURCES}
    PROPERTIES
    COMPILE_FLAGS "/clr"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_ROOTNAMESPACE ${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_GLOBAL_KEYWORD "ManagedCProj")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.0")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DOTNET_REFERENCES "System" "System.Drawing" "System.Windows.Forms")

string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
