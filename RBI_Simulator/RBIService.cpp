#include "RBIService.h"
#include <iostream>

RBIService::RBIService(ICommunicator* c, IBrowserEngine* e) : comm(c), engine(e) {}

void RBIService::Run() {
    std::cout << "[Server] Waiting for URL...\n";
    std::string url = comm->Receive();
    std::cout << "[Server] Received URL: " << url << "\n";
    std::string result = engine->RenderHtml(url);
    comm->Send(result);
    std::cout << "[Server] Response sent.\n";
}