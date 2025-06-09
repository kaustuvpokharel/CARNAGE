#pragma once

#include <err.h>
#include <pcap.h>
#include <vector>
#include <atomic>
#include <thread>
#include <string>
#include <sstream>
#include <memory>
#include "Logger.hpp"


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
    std::vector<std::string> getInterfaces() const;
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


