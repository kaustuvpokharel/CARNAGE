#include "PacketSniffer.hpp"
#include <QDebug>

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
        LOG_ERROR("Failed to open inteface");
    }

    for(pcap_if_t* dev = alldevs; dev != nullptr; dev = dev->next)
    {
        if(dev->next)
        {
            interfaces.emplace_back(dev->name);
        }
    }
    LOG_ERROR("Failed to open inteface");
    pcap_freealldevs(alldevs);
    return interfaces;
}

void Sniffer::PacketSniffer::startCapture(std::string& interfaceName)
{
    //stopCapture();
    char errbuff[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(interfaceName.c_str(), 65536, 1, 1, errbuff);
    if(!handle)
    {

        LOG_ERROR("Failed to open inteface");
        qWarning() << "Failed to open interface" << interfaceName << ":" << errbuff;
        return;
    }
}

