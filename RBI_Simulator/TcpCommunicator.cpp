#include "TcpCommunicator.h"
#include <iostream>

#define PORT "54000"

TcpCommunicator::TcpCommunicator(bool serverMode) : isServer(serverMode) {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (isServer) {
        struct addrinfo hints = {}, * res;
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        getaddrinfo(NULL, PORT, &hints, &res);
        SOCKET listenSock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        bind(listenSock, res->ai_addr, (int)res->ai_addrlen);
        listen(listenSock, SOMAXCONN);
        sock = accept(listenSock, NULL, NULL);
        closesocket(listenSock);
        freeaddrinfo(res);
    }
    else {
        struct addrinfo hints = {}, * res;
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        getaddrinfo("127.0.0.1", PORT, &hints, &res);
        sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        connect(sock, res->ai_addr, (int)res->ai_addrlen);
        freeaddrinfo(res);
    }
}

TcpCommunicator::~TcpCommunicator() {
    closesocket(sock);
    WSACleanup();
}

void TcpCommunicator::Send(const std::string& message) {
    send(sock, message.c_str(), (int)message.length(), 0);
}

std::string TcpCommunicator::Receive() {
    char buffer[4096];
    int bytesReceived = recv(sock, buffer, 4096, 0);
    if (bytesReceived > 0)
        return std::string(buffer, bytesReceived);
    return "";
}