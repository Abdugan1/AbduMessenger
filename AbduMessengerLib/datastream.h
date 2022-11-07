#ifndef DATASTREAM_H
#define DATASTREAM_H

#include "AbduMessengerLib_global.h"
#include <QDataStream>

class ABDUMESSENGERLIB_EXPORT DataStream : public QDataStream
{
public:
    explicit DataStream(QIODevice *device);
};

#endif // DATASTREAM_H
