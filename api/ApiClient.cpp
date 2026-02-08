//
// Created by Danylo Shkurko on 01.02.2026.
//
#define CPPHTTPLIB_OPENSSL_SUPPORT
#define CLIENT "api.github.com"

#include "ApiClient.h"

#include "httplib.h"
#include <nlohmann/json.hpp>

std::map<std::string, std::vector<Event>> ApiClient::fetch(const std::string &name, const std::string &api) {
    httplib::SSLClient cl(CLIENT);

    httplib::Headers headers = {
        {"Authorization", "Bearer " + api},
        {"X-GitHub-Api-Version", "2022-11-28"}
    };

    auto resp = cl.Get("/users/" + name + "/events", headers);

    if (resp->status != 200) {
        throw R"(Unable to receive events form github, please check username!)";
    }

    auto json = nlohmann::json::parse(resp->body);

    std::map<std::string, std::vector<Event>> events;

    for (auto &i: json) {
        std::string actor = i.at("actor").at("display_login");

        std::string typeTemp = i.at("type");
        std::stringstream type;
        type << typeTemp[0];

        for (int c = 1; c < typeTemp.size(); c++) {
            if (isupper(typeTemp.at(c))) {
                type << " " << typeTemp[c];
            } else {
                type << typeTemp[c];
            }
        }
        std::string typeStr = type.str();

        std::string repo = i.at("repo").at("name");
        repo.erase(repo.begin(), repo.begin() + actor.size() + 1);

        std::string createdAt = i.at("created_at");
        tm date{};
        strptime(createdAt.c_str(), "%Y-%m-%dT%H:%M:%SZ", &date);

        std::string when = std::to_string(date.tm_year + 1900) + "-" + std::to_string(date.tm_mon) + "-" +
                           std::to_string(date.tm_mday) + " at " + std::to_string(date.tm_hour) + ":" + std::to_string(
                               date.tm_min);

        Event event(actor, typeStr, repo, when);

        events[typeStr].push_back(event);
    }
    return events;
}
