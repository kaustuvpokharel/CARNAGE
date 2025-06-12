qt_add_qml_module(Theme
    URI THEME
    VERSION 1.0
    RESOURCES Theme.qrc
    SOURCES
        ThemeManager.cpp
        ThemeManager.hpp
        RESOURCES fonts.qrc
)

target_link_libraries(Theme
    PRIVATE Qt6::Core
    PRIVATE Qt6::Qml
    PRIVATE Qt6::Gui
)

target_include_directories(Theme PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
