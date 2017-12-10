#include "media_list.h"

#include <VLCQtCore/Instance.h>

#include "media_source.h"

MediaList::MediaList(VlcInstance *instance)
    : QObject(instance)
{

}

MediaList::MediaList(const QString &path, VlcInstance *instance)
    : QObject(instance)
{

}

MediaList::~MediaList()
{
//    for(MediaSource * src : m_sources)
//    {
//        delete src;
//    }
//    m_sources.clear();

//    m_buffer.clear();
}

void MediaList::openLocalFile(const QString &path)
{
    MediaSource * src = new MediaSource(path, true, m_instance);

    m_sources.append(src);

}

void MediaList::saveListAs(const QString &path) const
{

}

void MediaList::loadListFrom(const QString &path)
{

}


