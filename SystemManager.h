#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <vector>
#include "User.h"
#include "Community.h"

class SystemManager {
    static SystemManager* instance;

    vector<User*> users;
    vector<Community*> comms;

    SystemManager();

public:
    static SystemManager* getInstance();

    vector<User*>& getUsers();
    vector<Community*>& getCommunities();

    ~SystemManager();
};

#endif