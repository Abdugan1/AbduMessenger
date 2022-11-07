#include "datastream.h"

DataStream::DataStream(QIODevice *device)
    : QDataStream{device}
{
    setVersion(QDataStream::Qt_5_15);
}
