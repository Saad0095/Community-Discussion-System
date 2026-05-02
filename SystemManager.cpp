#include "SystemManager.h"

SystemManager* SystemManager::instance = nullptr;

SystemManager::SystemManager() {}

SystemManager* SystemManager::getInstance() {
    if (!instance)
        instance = new SystemManager();
    return instance;
}

vector<User*>& SystemManager::getUsers() { return users; }
vector<Community*>& SystemManager::getCommunities() { return comms; }

SystemManager::~SystemManager() {
    for (auto u : users) delete u;
    for (auto c : comms) delete c;
}