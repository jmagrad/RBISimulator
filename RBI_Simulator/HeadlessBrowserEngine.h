#pragma once
#include "IBrowserEngine.h"


class HeadlessBrowserEngine : public IBrowserEngine {
public:
    std::string RenderHtml(const std::string& url) override;
};

