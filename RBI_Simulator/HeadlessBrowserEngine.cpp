#include "HeadlessBrowserEngine.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>

std::string HeadlessBrowserEngine::RenderHtml(const std::string& url) {
    std::string outputFile = "page_output.html";
    std::string chromePath = "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe";
    std::string command =
        "cmd /C \"\"" + chromePath +
        "\" --headless=new --disable-gpu --dump-dom \"" + url +
        "\" > " + outputFile + "\"";


    int result = std::system(command.c_str());
    if (result != 0) {
        return "<html><body><h1>Error fetching page.</h1></body></html>";
    }

    std::ifstream file(outputFile);
    if (!file.is_open()) {
        return "<html><body><h1>Unable to open output file.</h1></body></html>";
    }


    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}