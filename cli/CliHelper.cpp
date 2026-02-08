//
// Created by Danylo Shkurko on 01.02.2026.
//

#include "CliHelper.h"

#include <iostream>
#include <sstream>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define API "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"


void CliHelper::help() {
    std::cout << "Example usage:" << std::endl;
    std::cout << "\t github-activity <username>" << std::endl;
}

std::string CliHelper::getInfo(std::string &&username) {
    std::stringstream ss;
    try {
        const std::map<std::string, std::vector<Event>> events = ApiClient::fetch(username, API);

        for (const auto&  e: events) {
            std::string title = e.first;
            title.erase(title.end() - 5, title.end());
            ss << title << ": " << std::endl;
            for (const auto& info : e.second) {
                ss << "\t -> " << info.getActor() << " made a " << BLUE << e.first << RESET << " on " << YELLOW << info.
                        getRepo() << RESET << " at " <<
                        info.whenHappened() << std::endl;
            }
        }

    } catch (const std::string& ex) {
        std::cerr << RED << ex << RESET << std::endl;
    }
    return ss.str();
}
