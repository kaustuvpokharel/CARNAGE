#include "PacketSniffer.hpp"
#include "Logger.hpp"
#include <QDebug>

std::map<std::string, bool> Sniffer::PacketSniffer::getInterfaces() const
{
    std::map<std::string, bool> interfaces;
    char errbuff[PCAP_ERRBUF_SIZE]; //defined in the pcap header as 256
    pcap_if_t* alldevs;
    /* pcap_if_t* is a pointer to a linked list node that describes a network interface available
    for packet capturing using libpcap, WinPcap, or Npcap.
    */

    if(pcap_findalldevs(&alldevs, errbuff) == -1)
    {
        LOG_ERROR("Failed to list interfaces: " + errbuff);
        return interfaces;
    }

    for(pcap_if_t* dev = alldevs; dev != nullptr; dev = dev->next)
    {
        pcap_t* handle = pcap_open_live(dev->name, 65536, 1, 1000, errbuff);
        if (handle) {
            interfaces.insert({dev->name, true});
            pcap_close(handle);
        } else {
            interfaces.insert({dev->name, false});
            LOG_WARN("Interface " + dev->name + " is inactive. Reason: " + errbuff);
        }

    }
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

