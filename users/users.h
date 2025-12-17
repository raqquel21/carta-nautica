#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QDate>
#include <QImage>

class Users
{
public:
    Users();
    Users(const QString &name, const QString &mail, const QString &password,
          const QImage &avatar, const QDate &birthDate);

    QString name() const;
    QString mail() const;
    QString password() const;
    QImage avatar() const;
    QDate birthDate() const;

private:
    QString m_name;
    QString m_mail;
    QString m_password;
    QImage m_avatar;
    QDate m_birthDate;
};

#endif // USERS_H
