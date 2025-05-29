#pragma once
#include <string>

class ICommunicator {
public:
    virtual void Send(const std::string& message) = 0;
    virtual std::string Receive() = 0;
    virtual ~ICommunicator() = default;
};
