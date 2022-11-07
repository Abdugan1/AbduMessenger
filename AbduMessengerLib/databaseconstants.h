#ifndef DATABASECONSTANTS_H
#define DATABASECONSTANTS_H

#include <QString>

namespace db {

    namespace users {

        extern const QString TableName;

        namespace fieldnames {
            extern const QString Id;
            extern const QString Username;
            extern const QString FirstName;
            extern const QString LastName;
            extern const QString CreatedAt;
            extern const QString UpdatedAt;
            extern const QString DeletedAt;
        } // fieldnames

        namespace fieldnums {
            enum {
                Id,
                Username,
                FirstName,
                LastName,
                CreatedAt,
                UpdatedAt,
                DeletedAt,
            };
        } // fieldnums

    } // users


    namespace messages {

    extern const QString TableName;

    namespace fieldnames {
        extern const QString Id;
        extern const QString SenderId;
        extern const QString ConversationId;
        extern const QString Content;
        extern const QString Type;
    } // fieldnames

    namespace fieldnums {

        enum {
            Id,
            SenderId,
            ConversationId,
            Content,
            Type
        };

    } // fieldnums

    } // messages


    namespace conversations {

    extern const QString TableName;

    namespace fieldnames {
        extern const QString Id;
        extern const QString Title;
        extern const QString CreatorId;
        extern const QString CreatedAt;
        extern const QString UpdatedAt;
        extern const QString DeletedAt;
    } // fieldnames

    namespace fieldnums {
        enum {
            Id,
            Title,
            CreatorId,
            CreatedAt,
            UpdatedAt,
            DeletedAt,
        };
    } // fieldnums

    } // conversations


    namespace participiants {

    extern const QString TableName;

    namespace fieldnames {
        extern const QString Id;
        extern const QString ConversationId;
        extern const QString UserId;
        extern const QString Type;
    } // fieldnames

    namespace fieldnums {
        enum {
            Id,
            ConversationId,
            UserId,
            Type,
        };
    } // fieldnums

    } // participiants

} // db

#endif // DATABASECONSTANTS_H
