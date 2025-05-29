#pragma once
#include "ICommunicator.h"
#include <string>

class ClientBrowser {
private:
    ICommunicator* comm;
public:
    ClientBrowser(ICommunicator* comm);
    void RequestUrl(const std::string& url);
    void DisplayContent();
};