#include "media_source.h"
#include <VLCQtCore/Media.h>

MediaSource::MediaSource(const QString &location, bool localFile, VlcInstance *instance)
    : VlcMedia(location, localFile, instance)
{

}

MediaSource::MediaSource(const QString &location, VlcInstance *instance)
    : VlcMedia(location, instance)
{

}

MediaSource::~MediaSource()
{

}

const QJsonObject &MediaSource::toJson() const
{
    QJsonObject obj;

    return obj;
}
