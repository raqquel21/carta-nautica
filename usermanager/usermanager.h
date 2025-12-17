#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "users/users.h"
#include <QVector>
#include <QString>

class UserManager
{
public:
    UserManager();

    void addUser(const Users &user);
    Users* authenticate(const QString &name, const QString &password);

private:
    QVector<Users> m_users;
};

#endif // USERMANAGER_H
