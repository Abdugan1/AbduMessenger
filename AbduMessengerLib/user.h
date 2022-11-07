#ifndef USER_H
#define USER_H

#include <AbduMessengerLib_global.h>

#include <QString>

class ABDUMESSENGERLIB_EXPORT User
{
public:
    explicit User();

    int id() const;
    void setId(int newId);
    void resetId();

    const QString &username() const;
    void setUsername(const QString &newUsername);
    void resetUsername();

    const QString &firstName() const;
    void setFirstName(const QString &newFirstName);
    void resetFirstName();

    const QString &lastName() const;
    void setLastName(const QString &newLastName);
    void resetLastName();

    const QString &createdAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    void resetCreatedAt();

    const QString &updatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
    void resetUpdatedAt();

    const QString &deletedAt() const;
    void setDeletedAt(const QString &newDeletedAt);
    void resetDeletedAt();

private:
    int id_ = -1;
    QString username_;
    QString firstName_;
    QString lastName_;
    QString createdAt_;
    QString updatedAt_;
    QString deletedAt_;
};

#endif // USER_H
