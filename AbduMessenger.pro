TEMPLATE = subdirs

SUBDIRS += \
    AbduMessengerClient \
    AbduMessengerDesktop \
    AbduMessengerLib \
    AbduMessengerServer

AbduMessengerClient.subdirs     = AbduMessengerClient/
AbduMessengerDesktop.subdirs    = AbduMessengerDesktop/
AbduMessengerLib.subdirs        = AbduMessengerLib/
AbduMessengerServer.subdirs     = AbduMessengerServer/

AbduMessengerClient.depends     = AbduMessengerLib
AbduMessengerDesktop.depends    = AbduMessengerLib
AbduMessengerDesktop.depends    = AbduMessengerClient
AbduMessengerServer.depends     = AbduMessengerLib
