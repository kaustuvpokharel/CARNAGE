add_subdirectory(App)
add_subdirectory(Core)
add_subdirectory(UI)

#documentation control
file(GLOB DOC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_custom_target(readme_${DIR_NAME} SOURCES ${DOC_FILES})
