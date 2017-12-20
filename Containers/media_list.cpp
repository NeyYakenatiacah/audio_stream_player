#include "media_list.h"

#include <VLCQtCore/Instance.h>

#include "Data/media_list_private.h"
#include "Filters/filter_manager.h"
#include "media_source.h"

#include <QVariant>

MediaList::MediaList(VlcInstance *instance)
    : QObject(instance)
{
    m_data = new MediaListPrivate(instance);

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
   m_data->openMedia(url, false);
}

void MediaList::sort(const Vlc::Meta &type)
{

}

void MediaList::search(const Vlc::Meta &type, const QString &tag)
{
    m_filterManager->append(type, QVariant(tag));
}

QQmlListProperty<MediaSource> MediaList::sources()
{
    //return QQmlListProperty<MediaSource>(this, m_sources);
    return QQmlListProperty<MediaSource>(this, this,
                                         &MediaList::append_source,
                                         &MediaList::source_count,
                                         &MediaList::source_at,
                                         &MediaList::clear_sources);
}

void MediaList::appendSource(MediaSource *src)
{
    if(src) m_data->openMedia(src);
}

int MediaList::count() const
{
    return m_sources.count();
}

MediaSource *MediaList::source(int idx) const
{
    return m_sources.at(idx)
}

void MediaList::clearSources()
{
    //m_data->clear();
}

bool MediaList::saveListAs(const QString &path) const
{
    m_data->save(path);
}

bool MediaList::loadListFrom(const QString &path)
{
    m_data->load(path);
}

void MediaList::append_source(QQmlListProperty<MediaSource> *list, MediaSource *src)
{
    qobject_cast<MediaList *>(list->object)->appendSource(src);
}

int MediaList::source_count(QQmlListProperty<MediaSource> *list)
{
    return qobject_cast<MediaList *>(list->object)->count();
}

MediaSource *MediaList::source_at(QQmlListProperty<MediaSource> *list, int idx)
{
    return qobject_cast<MediaList *>(list->object)->source(idx);
}

void MediaList::clear_sources(QQmlListProperty<MediaSource> *list)
{
    qobject_cast<MediaList *>(list->object)->clearSources();
}



