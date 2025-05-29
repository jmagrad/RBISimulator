#include "ClientBrowser.h"
#include <iostream>

ClientBrowser::ClientBrowser(ICommunicator* c) : comm(c) {}

void ClientBrowser::RequestUrl(const std::string& url) {
    comm->Send(url);
}

void ClientBrowser::DisplayContent() {
    std::string response = comm->Receive();
    std::cout << "\n--- Rendered Content ---\n";
    std::cout << response << "\n------------------------\n";
}