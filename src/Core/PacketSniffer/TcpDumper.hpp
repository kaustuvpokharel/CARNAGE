#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <pcap.h>

#ifndef ETHER_HDR_LEN
#define  ETHER_HDR_LEN 14
#endif

namespace Sniffer
{

class TcpDumper
{


public:
    static constexpr uint8_t FIN = 0x01; //00000001
    static constexpr uint8_t SYN = 0x02; //00000010
    static constexpr uint8_t RST = 0x04; //00000100
    static constexpr uint8_t PUSH = 0x08; //00001000
    static constexpr uint8_t ACK = 0x10; //00010000
    static constexpr uint8_t URG = 0x20; //00100000
    unsigned short srcPort;
    unsigned short desPort;
    unsigned int seq;
    unsigned int ack;
    unsigned char reserved;
    unsigned char offset;
    unsigned char flags;
    unsigned short window;
    unsigned short checksum;
    unsigned short urgent;
    unsigned int packetDataLength;
    unsigned int headerLength;
    unsigned int headerSize;

public:
    std::vector<std::string> dumpTcp();

private:
    void tcpCapture(u_char *userArgs, const struct pcap_pkthdr* capHeader, const u_char* packet);
    void decodeEthernet(const u_char* headerStart);
    void decodeIp(const u_char *headerStart);

};

}
