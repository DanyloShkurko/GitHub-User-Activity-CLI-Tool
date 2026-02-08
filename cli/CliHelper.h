//
// Created by Danylo Shkurko on 01.02.2026.
//

#ifndef GITHUB_USER_ACTIVITY_CLIHELPER_H
#define GITHUB_USER_ACTIVITY_CLIHELPER_H
#include <string>

#include "../api/ApiClient.h"


class CliHelper {
private:
    std::shared_ptr<ApiClient> apiClient;
public:
    explicit CliHelper(const std::shared_ptr<ApiClient> &apiClient): apiClient(apiClient){}
    ~CliHelper() = default;

    static void help();

    static std::string getInfo(std::string &&username);
};


#endif //GITHUB_USER_ACTIVITY_CLIHELPER_H