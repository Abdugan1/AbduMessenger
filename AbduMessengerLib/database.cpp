#include "database.h"
#include "databaseconstants.h"

#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

Database::Database(QObject *parent)
    : QObject{parent}
    , QSqlDatabase{}
{
    init();
}

void Database::init()
{
    connectToDatabase();
    createTables();
}

void Database::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    if (db.isValid()) {
        qFatal("Database::connectToDatabase: Database is not valid");
    }

    const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (writeDir.mkpath(".")) {
        qFatal("Database::connectToDatabase: Make writable directory failed");
    }

    const QString fileName = writeDir.absolutePath() + "/AbduMessenger.sqlite3";
    db.setDatabaseName(fileName);
    if (!db.open()) {
        QFile::remove(fileName);
        qFatal("Database::connectToDatabase: Database open failed");
    }
}

void Database::createTables()
{
    createUsersTable();
    createMessagesTable();
    createConversationsTable();
    createParticipiantsTable();
}

void Database::createUsersTable()
{
    using namespace db::users;
    using namespace fieldnames;
    const QString execute = QString("CREATE TABLE IF NOT EXISTS " + TableName + "(" +
                                        Id + " INTEGER PRIMARY KEY," +
                                        Username + " TEXT," +
                                        FirstName + " TEXT," +
                                        LastName + " TEXT," +
                                        CreatedAt + " TEXT," +
                                        UpdatedAt + " TEXT," +
                                        DeletedAt + " TEXT" +
                                    ")");

    QSqlQuery query;
    if (!query.exec(execute)) {
        qFatal("Database::createUsersTable: Cannot create table");
    }
}

void Database::createMessagesTable()
{
    using namespace db::messages;
    using namespace fieldnames;
    const QString execute = QString("CREATE TABLE IF NOT EXISTS " + TableName + "(" +
                                        Id + " INTEGER PRIMARY KEY," +
                                        SenderId + " INTEGER," +
                                        ConversationId + " INTEGER," +
                                        Content + " TEXT," +
                                        Type + " TEXT," +
                                    "   FOREIGN KEY(" + SenderId + ") REFERENCES " + db::users::TableName + "(" + db::users::fieldnames::Id + ")," +
                                    "   FOREIGN KEY(" + ConversationId + ") REFERENCES " + db::users::TableName + "(" + db::conversations::fieldnames::Id + ")"
                                    );

    QSqlQuery query;
    if (!query.exec(execute)) {
        qFatal("Database::createMessagesTable: Cannot create table");
    }
}

void Database::createConversationsTable()
{
    using namespace db::conversations;
    using namespace fieldnames;
    const QString execute = QString("CREATE TABLE IF NOT EXISTS " + TableName + "(" +
                                        Id + " INTEGER PRIMARY KEY," +
                                        Title + " TEXT," +
                                        CreatorId + " INTEGER," +
                                        CreatedAt + " TEXT," +
                                        UpdatedAt + " TEXT," +
                                        DeletedAt + " TEXT," +
                                    "   FOREIGN KEY (" + CreatorId + ") REFERENCES " + db::users::TableName + "(" + db::users::fieldnames::Id + ")"
                                    );

    QSqlQuery query;
    if (!query.exec(execute)) {
        qFatal("Database::createConversationsTable: Cannot create table");
    }
}

void Database::createParticipiantsTable()
{
    using namespace db::participiants;
    using namespace fieldnames;
    const QString execute = QString("CREATE TABLE IF NOT EXISTS " + TableName + "(" +
                                        Id + " INTEGER PRIMARY KEY," +
                                        ConversationId + " INTEGER," +
                                        UserId + " INTEGER," +
                                        Type + " TEXT,"
                                    "   FOREIGN KEY(" + ConversationId + ") REFERENCES " + db::conversations::TableName + "(" + db::conversations::fieldnames::Id + ")," +
                                    "   FOREIGN KEY(" + UserId + ") REFERENCES " + db::users::TableName + "(" + db::users::fieldnames::Id + ")"
                                    );

    QSqlQuery query;
    if (!query.exec(execute)) {
        qFatal("Database::createParticipiantsTable: Cannot create table");
    }
}
