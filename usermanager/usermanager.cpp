#include "usermanager.h"

UserManager::UserManager() {}

void UserManager::addUser(const Users &user) {
    m_users.append(user);
}

Users* UserManager::authenticate(const QString &name, const QString &password) {
    for (Users &u : m_users) {
        if (u.name() == name && u.password() == password)
            return &u;
    }
    return nullptr;
}
