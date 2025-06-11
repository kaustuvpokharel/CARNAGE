cmake_minimum_required(VERSION 3.16)
project(CARNAGE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Core Quick REQUIRED)

#find libpcap
find_path(PCAP_INCLUDE_DIR pcap.h)
find_library(PCAP_LIBRARY pcap)

if (NOT PCAP_INCLUDE_DIR OR NOT PCAP_LIBRARY)
    message(FATAL_ERROR "Libpcap not found. Please install it (eg. brew install libpcap)")
endif()

#include libpcap headers
include_directories(
    ${PCAP_INCLUDE_DIR}
)

#include subdirectories
add_subdirectory(src)
add_subdirectory(tests)


#documentation control
file(GLOB DOC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_custom_target(readme_${DIR_NAME} SOURCES ${DOC_FILES})

message(STATUS "📚 Documentation files:")
file(GLOB_RECURSE ALL_READMES "*/README.md")
foreach(README ${ALL_READMES})
    message(STATUS " - ${README}")
endforeach()


# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
include(GNUInstallDirs)
set_target_properties(App PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_ICON_FILE icon.icns
    MACOSX_BUNDLE_BUNDLE_VERSION 0.1
    MACOSX_BUNDLE_SHORT_VERSION_STRING 0.1
)
