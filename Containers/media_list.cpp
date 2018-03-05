#include "media_list.h"

#include <VLCQtCore/Instance.h>

#include "Data/media_list_private.h"
#include "Filters/filter_manager.h"
#include "media_source.h"

#include <QVariant>

#include <QDebug>

MediaList::MediaList(VlcInstance *instance, const QString &name)
    : QObject(instance)
{
    m_data = new MediaListPrivate(instance);
    m_name = name;

    connect(m_data, &MediaListPrivate::reloaded, this, &MediaList::reloaded);
    connect(m_data, &MediaListPrivate::added, this, [this](MediaSource * src)
    {
        m_sources.append(src);
        emit reloaded();
    });
}

MediaList::MediaList(const QString &path, VlcInstance *instance)
    : QObject(instance)
{
    //m_instance = instance;
    m_data = new MediaListPrivate(instance);

    m_data->load(path);

    connect(m_data, &MediaListPrivate::reloaded, this, &MediaList::reloaded);
    connect(m_data, &MediaListPrivate::added, this, [this](MediaSource * src)
    {
        m_sources.append(src);
        emit reloaded();
    });
    //m_name = m_data->name();
    qDebug() << "MediaList";
}

MediaList::~MediaList()
{
    qDebug() << name();
//    for(MediaSource * src : m_sources)
//    {

//        delete src;
//    }
//    m_sources.clear();

//    m_buffer.clear();
    qDebug() << QString("~MediaList: {size: %1}").arg(m_data->size());
}

void MediaList::openLocalFile(const QString &path)
{
    qDebug() << QString("OpenLocalFile: %1").arg(path);
    m_data->openMedia(QUrl(path).path(), true);
}

void MediaList::openLocalFile(const QUrl &path)
{
    qDebug() << QString("OpenLocalFileURL: %1").arg(path.fileName());
    m_data->openMedia(path.fileName(), true);
}

void MediaList::openUrl(const QUrl &url)
{
    m_data->openMedia(url.fileName(), false);
}

void MediaList::sort(const Vlc::Meta &type)
{
    Q_UNUSED(type)
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
    return m_sources.at(idx);
}

void MediaList::clearSources()
{
    //m_data->clear();
}

bool MediaList::saveListAs(const QString &path) const
{
    return m_data->save(path);
}

bool MediaList::saveListDefaultLocation() const
{
    return m_data->save("");
}

bool MediaList::loadListFrom(const QString &path)
{
    return m_data->load(path);
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

QString MediaList::name() const
{
    return m_name;
}

void MediaList::setName(const QString &name)
{
    m_name = name;
}



