#ifndef DATABASE_H
#define DATABASE_H

#include "AbduMessengerLib_global.h"
#include <QObject>
#include <QSqlDatabase>

class ABDUMESSENGERLIB_EXPORT Database : public QObject, public QSqlDatabase
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);

private:
    void init();

    void connectToDatabase();

    void createTables();
    void createUsersTable();
    void createMessagesTable();
    void createConversationsTable();
    void createParticipiantsTable();

};

#endif // DATABASE_H
