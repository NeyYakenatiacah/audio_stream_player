#include "media_list.h"

#include <VLCQtCore/Instance.h>

#include "Data/media_list_private.h"
#include "media_source.h"

MediaList::MediaList(VlcInstance *instance)
    : QObject(instance)
{

}

MediaList::MediaList(const QString &path, VlcInstance *instance)
    : QObject(instance)
{
    //m_instance = instance;
    m_data = new MediaListPrivate(instance);
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
    m_data->openMedia(path, true);
}

void MediaList::openUrl(const QString &url)
{
    m_data->openMedia(path, false);
}

void MediaList::search(const QString &tag)
{

}

bool MediaList::saveListAs(const QString &path) const
{
    m_data->save(path);
}

bool MediaList::loadListFrom(const QString &path)
{
    m_data->load(path);
}


