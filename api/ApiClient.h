//
// Created by Danylo Shkurko on 01.02.2026.
//

#ifndef GITHUB_USER_ACTIVITY_APICLIENT_H
#define GITHUB_USER_ACTIVITY_APICLIENT_H
#include <map>
#include "../event/Event.h"


class ApiClient {
private:
public:
    ApiClient() = default;
    ~ApiClient() = default;

    static std::map<std::string, std::vector<Event>> fetch(const std::string &name, const std::string &api);
};


#endif //GITHUB_USER_ACTIVITY_APICLIENT_H