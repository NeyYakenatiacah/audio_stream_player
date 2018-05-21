#include "media_list.h"

#include <VLCQtCore/Instance.h>

#include "Data/media_list_private.h"
#include "Filters/filter_manager.h"
#include "media_source.h"

#include <QVariant>

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

MediaList::MediaList(VlcInstance *instance, const QString &name)
    : QObject(instance)
{
    qDebug() << "MediaList() " << name;
    m_data = new MediaListPrivate(name, instance);
    m_name = name;

    initConnections();
}

MediaList::MediaList(const QString &path, VlcInstance *instance)
    : QObject(instance)
{
    //m_instance = instance;
    m_data = new MediaListPrivate(instance);

    if(m_data->load(path))
    {
        m_name = m_data->name();
    }
    else
    {
        m_name = "temp";
    }

    initConnections();
}

MediaList::~MediaList()
{
    qDebug() << name();
    qDebug() << QString("~MediaList: {size: %1}{size: %2}").arg(m_data->size()).arg(m_sources.size());
}

QJsonObject MediaList::saveToJson() const
{
    return m_data->jsonExport();
}

bool MediaList::loadFromJson(const QJsonObject &json)
{
    if(m_data->jsonImport(json))
    {

        m_name = m_data->name();
        qDebug() << "loaded: " << m_name;
        return true;
    }

    return false;
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
    return QQmlListProperty<MediaSource>(this, this,
                                         &MediaList::append_source,
                                         &MediaList::source_count,
                                         &MediaList::source_at,
                                         &MediaList::clear_sources);
}

void MediaList::appendSource(MediaSource *src)
{
    qDebug() << "AppendSource()";
    if(src) m_data->openMedia(src);
}

int MediaList::count() const
{
    return m_sources.count();
}

MediaSource *MediaList::source(int idx) const
{
    if(idx < 0) return m_sources.at(0);
    else if(idx >= m_sources.size()) return m_sources.at(m_sources.size() - 1);
    else return m_sources.at(idx);
}

void MediaList::removeSource(int idx)
{
    if(idx >= 0 && idx < m_sources.size())
        m_data->removeMedia(m_sources.at(idx));
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
    qDebug() << "append_sources";
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
    m_data->setName(name);
}

void MediaList::initConnections()
{
    connect(m_data, &MediaListPrivate::reloaded, this, &MediaList::reloaded);
    connect(m_data, &MediaListPrivate::reloaded, this, [this]()
    {
        m_sources.clear();
        for(auto it = m_data->begin(); it != m_data->end(); ++it)
        {
            m_sources << *it;
        }
    });
    connect(m_data, &MediaListPrivate::removed, this, [this](MediaSource * src)
    {
        for(auto it = m_sources.begin(); it != m_sources.end(); ++it)
        {
            if(*it == src) m_sources.erase(it);
        }
        emit reloaded();
    });
    connect(m_data, &MediaListPrivate::nameChanged, this, &MediaList::nameChanged);
    connect(m_data, &MediaListPrivate::added, this, [this](MediaSource * src)
    {
        m_sources.append(src);
        emit reloaded();
    });
}



