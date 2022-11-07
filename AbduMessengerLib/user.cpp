#include "user.h"

User::User()
{

}

int User::id() const
{
    return id_;
}

void User::setId(int newId)
{
    id_ = newId;
}

void User::resetId()
{
    setId(-1);
}

const QString &User::username() const
{
    return username_;
}

void User::setUsername(const QString &newUsername)
{
    username_ = newUsername;
}

void User::resetUsername()
{
    setUsername({});
}

const QString &User::firstName() const
{
    return firstName_;
}

void User::setFirstName(const QString &newFirstName)
{
    firstName_ = newFirstName;
}

void User::resetFirstName()
{
    setFirstName({});
}

const QString &User::lastName() const
{
    return lastName_;
}

void User::setLastName(const QString &newLastName)
{
    lastName_ = newLastName;
}

void User::resetLastName()
{
    setLastName({});
}

const QString &User::createdAt() const
{
    return createdAt_;
}

void User::setCreatedAt(const QString &newCreatedAt)
{
    createdAt_ = newCreatedAt;
}

void User::resetCreatedAt()
{
    setCreatedAt({});
}

const QString &User::updatedAt() const
{
    return updatedAt_;
}

void User::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt_ = newUpdatedAt;
}

void User::resetUpdatedAt()
{
    setUpdatedAt({});
}

const QString &User::deletedAt() const
{
    return deletedAt_;
}

void User::setDeletedAt(const QString &newDeletedAt)
{
    deletedAt_ = newDeletedAt;
}

void User::resetDeletedAt()
{
    setDeletedAt({});
}
