#ifndef ABDUMESSENGERCLIENT_GLOBAL_H
#define ABDUMESSENGERCLIENT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ABDUMESSENGERCLIENT_LIBRARY)
#  define ABDUMESSENGERCLIENT_EXPORT Q_DECL_EXPORT
#else
#  define ABDUMESSENGERCLIENT_EXPORT Q_DECL_IMPORT
#endif

#endif // ABDUMESSENGERCLIENT_GLOBAL_H
