#pragma once
#include "ICommunicator.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

class TcpCommunicator : public ICommunicator {
private:
    SOCKET sock;
    bool isServer;
public:
    TcpCommunicator(bool serverMode);
    ~TcpCommunicator();

    void Send(const std::string& message) override;
    std::string Receive() override;
};

