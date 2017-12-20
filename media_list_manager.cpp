#include "media_list_manager.h"

#include <VLCQtCore/Instance.h>

#include "Containers/media_list.h"
MediaListManager::MediaListManager(VlcInstance * instance) : QObject(instance)
{
    m_instance = instance;
    m_selectedList = nullptr;
}

QStringList MediaListManager::names() const
{
    QStringList playlists;

    for(const MediaList * list : m_playlists)
    {
        playlists << list->name();
    }

    return playlists;
}

void MediaListManager::select(const QString & name)
{
    for(MediaList * list : m_playlists)
    {
        if(list->name() == name) select(list);
    }
}

void MediaListManager::createList(const QString &name)
{
    MediaList * list = new MediaList(m_instance, name);
    m_playlists.append(list);

    select(list);
}

void MediaListManager::loadList(const QString &path)
{
    MediaList * list = new MediaList(path, m_instance);
    m_playlists.append(list);

    select(list);
}

MediaList *MediaListManager::currentList() const
{
    return m_selectedList;
}

void MediaListManager::select(MediaList *list)
{
    m_selectedList = list;

    emit currentListChanged();
}
