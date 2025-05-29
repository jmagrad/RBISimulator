// main.cpp
#include <iostream>
#include "TcpCommunicator.h"
#include "HeadlessBrowserEngine.h"
#include "RBIService.h"
#include "ClientBrowser.h"

int main() {
    std::cout << "Mini RBI Simulator" << std::endl;

    int mode = 0;
    std::cout << "Enter mode: 1 = Server, 2 = Client: ";
    std::cin >> mode;

    if (mode == 1) {
        // Run RBI Server
        TcpCommunicator serverComm(true); 
        HeadlessBrowserEngine engine;
        RBIService server(&serverComm, &engine);
        server.Run();
    }
    else if (mode == 2) {
        // Run Client
        TcpCommunicator clientComm(false);
        ClientBrowser client(&clientComm);
        std::string url;
        std::cout << "Enter URL to fetch: ";
        std::cin >> url;
        client.RequestUrl(url);
        client.DisplayContent();
    }
    else {
        std::cout << "Invalid mode!" << std::endl;
    }

    return 0;
}
