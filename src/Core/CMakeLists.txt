add_subdirectory(PacketSniffer)
add_subdirectory(PacketParser)
add_subdirectory(RuleEngine)
add_subdirectory(PacketInjector)
add_subdirectory(Models)

add_library(Core INTERFACE)

target_link_libraries(Core
    INTERFACE PacketSniffer PacketParser RuleEngine PacketInjector Models
)
