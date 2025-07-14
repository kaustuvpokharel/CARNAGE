#include "TcpDumper.hpp"

void Sniffer::TcpDumper::tcpCapture(u_char *userArgs, const pcap_pkthdr *capHeader, const u_char *packet)
{
    u_char *pct_data;

    //Here is where we could use capHeader to get the size of the packet but we will keep this logic in the packetSniffer itself, or dumpTcp function or here if no option.

    decodeEthernet(packet);
    decodeIp(packet+ETHER_HDR_LEN);
    headerLength = decodeTcp(packet+ETHER_HDR_LEN//+sizeof);

}

void Sniffer::TcpDumper::decodeEthernet(const u_char *headerStart)
{

}

void Sniffer::TcpDumper::decodeIp(const u_char *headerStart)
{

}
