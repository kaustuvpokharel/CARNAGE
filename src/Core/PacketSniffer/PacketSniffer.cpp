#include "PacketSniffer.hpp"

std::vector<std::string> Sniffer::PacketSniffer::getInterfaces() const
{
    std::vector<std::string> interfaces;
    char errbuff[PCAP_ERRBUF_SIZE]; //defined in the pcap header as 256
    pcap_if_t* alldevs;
    /* pcap_if_t* is a pointer to a linked list node that describes a network interface available
    for packet capturing using libpcap, WinPcap, or Npcap.
    */

    if(pcap_findalldevs(&alldevs, errbuff) == -1)
    {
        std::cerr<<"[Error] Finding devices: "<< errbuff << std::endl;
    }

    for(pcap_if_t* dev = alldevs; dev != nullptr; dev = dev->next)
    {
        if(dev->next)
        {
            interfaces.emplace_back(dev->name);
        }
    }

    pcap_freealldevs(alldevs);
    return interfaces;
}
