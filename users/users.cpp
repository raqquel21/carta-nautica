#include "users.h"

Users::Users() {}

Users::Users(const QString &name, const QString &mail, const QString &password,
             const QImage &avatar, const QDate &birthDate)
    : m_name(name), m_mail(mail), m_password(password), m_avatar(avatar), m_birthDate(birthDate)
{}

QString Users::name() const { return m_name; }
QString Users::mail() const { return m_mail; }
QString Users::password() const { return m_password; }
QImage Users::avatar() const { return m_avatar; }
QDate Users::birthDate() const { return m_birthDate; }
