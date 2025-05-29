#pragma once
#include "ICommunicator.h"
#include "IBrowserEngine.h"

class RBIService {
private:
    ICommunicator* comm;
    IBrowserEngine* engine;
public:
    RBIService(ICommunicator* comm, IBrowserEngine* engine);
    void Run();
};
