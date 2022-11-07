#include "databaseconstants.h"

namespace db {

    namespace users {

        const QString TableName = "users";

        namespace fieldnames {
            const QString Id        = "id";
            const QString Username  = "username";
            const QString FirstName = "first_name";
            const QString LastName  = "last_name";
            const QString CreatedAt = "created_at";
            const QString UpdatedAt = "updated_at";
            const QString DeletedAt = "deleted_at";
        } // fieldnames

    } // users

    namespace messages {

    const QString TableName = "messages";

    namespace fieldnames {
        const QString Id             = "id";
        const QString SenderId       = "sender_id";
        const QString ConversationId = "conversation_id";
        const QString Content        = "content";
        const QString Type           = "type";
    } // fieldnames

    } // messages


    namespace conversations {

    const QString TableName = "conversations";

    namespace fieldnames {
        const QString Id        = "id";
        const QString Title     = "title";
        const QString CreatorId = "creator_id";
        const QString CreatedAt = "created_at";
        const QString UpdatedAt = "updated_at";
        const QString DeletedAt = "deleted_at";
    } // fieldnames

    } // conversations


    namespace participiants {

    const QString TableName = "participiants";

    namespace fieldnames {
        const QString Id             = "id";
        const QString ConversationId = "conversation_id";
        const QString UserId         = "user_id";
        const QString Type           = "type";
    } // fieldnames

    } // participiants

} // db
