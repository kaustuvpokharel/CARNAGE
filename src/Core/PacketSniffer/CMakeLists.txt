add_library(PacketSniffer STATIC
    PacketSniffer.cpp
    PacketSniffer.hpp

    #Dumper modules
    # ProtocolDumper.cpp
    # ProtocolDumper.hpp
    # HexDumper.cpp
    # HexDumper.hpp
    # EthernetDumper.cpp
    # EthernetDumper.hpp
    # ArpDumper.cpp
    # ArpDumper.hpp
    # IPv4Dumper.cpp
    # IPv4Dumper.hpp
    # IPv6Dumper.cpp
    # IPv6Dumper.hpp
    TcpDumper.cpp
    TcpDumper.hpp
    # UdpDumper.cpp
    # UdpDumper.hpp
    # IcmpDumper.cpp
    # IcmpDumper.hpp
    # AppHintDumper.cpp
    # AppHintDumper.hpp

    #timestampCatcher
    # TimeStampFormatter.cpp
    # TimeStampFormatter.hpp
)
target_link_libraries(PacketSniffer
    PRIVATE Qt6::Core
)

target_include_directories(PacketSniffer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}        # So you can include "PacketSniffer.hpp"
        ${CMAKE_CURRENT_SOURCE_DIR}/..     # So you can include "Core/Logger.h"
)


