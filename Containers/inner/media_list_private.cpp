#include "media_list_private.h"

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>

#include <Containers/media_source.h>

MediaListPrivate::MediaListPrivate(VlcInstance * instance) : QObject(instance)
{
    m_instance = instance ? instance : new VlcInstance(VlcCommon::args());
}

void MediaListPrivate::openMedia(const QString &location, bool isLocalFile)
{
    MediaSource * src = new MediaSource();
}

bool MediaListPrivate::load(const QString &path)
{
    return false;
}

bool MediaListPrivate::save(const QString &path)
{
    return false;
}
