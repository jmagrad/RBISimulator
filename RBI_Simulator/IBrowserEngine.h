#pragma once
#include <string>

class IBrowserEngine {
public:
    virtual std::string RenderHtml(const std::string& url) = 0;
    virtual ~IBrowserEngine() = default;
};