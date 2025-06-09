# # add_subdirectory(PacketSniffer)
# # add_subdirectory(PacketParser)
# # add_subdirectory(RuleEngine)
# # add_subdirectory(PacketInjector)
# # add_subdirectory(Models)

# # Optional if you’re grouping Core
# add_library(Core INTERFACE)
# target_link_libraries(Core
#     INTERFACE PacketSniffer PacketParser RuleEngine PacketInjector Models
# )

#documentation control
file(GLOB DOC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_custom_target(readme_${DIR_NAME} SOURCES ${DOC_FILES})
