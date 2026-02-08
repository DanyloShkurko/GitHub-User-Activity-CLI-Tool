//
// Created by Danylo Shkurko on 05.02.2026.
//

#include "Event.h"

Event::Event(std::string& actor, std::string& type, std::string& repo, std::string& when): actor(actor), type(type), repo(repo), when(when) {}

std::string Event::getActor() const {
    return actor;
}
std::string Event::getType() const {
    return type;
}
std::string Event::getRepo() const {
    return repo;
}
std::string Event::whenHappened() const {
    return when;
}
