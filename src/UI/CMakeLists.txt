qt_add_qml_module(UIModule
    URI CARNAGE
    VERSION 1.0
    QML_FILES
        Main/main.qml
        Pages/Login.qml
        Pages/Home.qml
        Components/Header.qml
        RESOURCES QmlResources.qrc
)


#documentation control
file(GLOB DOC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_custom_target(readme_${DIR_NAME} SOURCES ${DOC_FILES})
