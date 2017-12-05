#include "media_source.h"
#include <VLCQtCore/Media.h>

MediaSource::MediaSource(QObject *parent) : QObject(parent)
{
    m_media = nullptr;
}
