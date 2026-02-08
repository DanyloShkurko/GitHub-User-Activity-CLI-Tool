//
// Created by Danylo Shkurko on 05.02.2026.
//

#ifndef GITHUB_USER_ACTIVITY_EVENT_H
#define GITHUB_USER_ACTIVITY_EVENT_H
#include <string>


class Event {
private:
    std::string actor;
    std::string type;
    std::string repo;
    std::string when;
public:
    Event(std::string& actor, std::string& type, std::string & repo, std::string& when);
    Event() = default;
    ~Event() = default;

    std::string getActor() const;
    std::string getType() const;
    std::string getRepo() const;
    std::string whenHappened() const;
};


#endif //GITHUB_USER_ACTIVITY_EVENT_H