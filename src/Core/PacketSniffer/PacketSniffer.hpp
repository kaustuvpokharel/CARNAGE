#pragma once

#include <err.h>
#include <pcap.h>
#include <atomic>
#include <thread>
#include <map>
#include <string>

namespace Sniffer
{

enum class LogLevel
{
    BASIC,
    EXTENDED,
    VERBOSE
};

class PacketSniffer
{
public:
    std::map<std::string, bool> getInterfaces() const;
    void startCapture(std::string& interfaceName);
    void stopCapture();

    void setLogLevel(LogLevel level);
    LogLevel getLogLevel() const;

private:
    void captureLoop();
    void dumpPacket(const struct pcap_pkthdr* header, const u_char* data);

private:
    pcap_t* handle;
    std::atomic<bool> sniffing;
    std::thread captureThread;
    LogLevel logLevel;
};

}


