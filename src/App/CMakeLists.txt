add_executable(CARNAGE
    main.cpp
    AppController.cpp
    AppController.h
)

target_link_libraries(CARNAGE
    Qt6::Core
    Qt6::Quick
    Qt6::Qml
    PacketSniffer
    PacketParser
    RuleEngine
    PacketInjector
    Models
    Core
    ${PCAP_LIBRARY}
)
