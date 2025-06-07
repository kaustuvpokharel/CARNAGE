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

# qt_add_qml_module(CARNAGE
#     URI CARNAGE
#     VERSION 1.0
#     QML_FILES main.qml
# )

# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# set_target_properties(CARNAGE PROPERTIES
# #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CARNAGE
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# include(GNUInstallDirs)
# install(TARGETS CARNAGE
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
