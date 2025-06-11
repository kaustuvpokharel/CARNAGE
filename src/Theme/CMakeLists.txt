qt_add_qml_module(Theme
    URI THEME
    VERSION 1.0
    RESOURCES Theme.qrc
    SOURCES
        ThemeManager.cpp
        ThemeManager.hpp
)

target_link_libraries(Theme
    PRIVATE Qt6::Core
    PRIVATE Qt6::Qml
)

target_include_directories(Theme PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
