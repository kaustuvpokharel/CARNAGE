add_executable(App
    main.cpp
    AppController.cpp
    AppController.h
)

target_include_directories(App
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/Core
)

target_link_libraries(App
    PRIVATE
        Qt6::Core
        Qt6::Quick
        Qt6::Qml
        Core
        Theme
        UIModule
        ${PCAP_LIBRARY}
)

# Documentation control
file(GLOB DOC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_custom_target(readme_${DIR_NAME} SOURCES ${DOC_FILES})
