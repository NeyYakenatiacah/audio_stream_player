#include "media_list_manager.h"

#include <VLCQtCore/Instance.h>

#include "Containers/media_list.h"

MediaListManager::MediaListManager(VlcInstance * instance) : QObject(instance)
{
    m_instance = instance;
    m_selectedList = nullptr;
    createList();
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
        if(list->name() == name)
        {
            select(list);
            emit currentListChanged();
        }
    }
}

void MediaListManager::createList()
{
    static int counter;
    createList(QString("Playlist #%1").arg(++counter));
}

void MediaListManager::createList(const QString &name)
{
    if(name.isEmpty()) return createList();

    MediaList * list = new MediaList(m_instance, name);
    m_playlists.append(list);

    emit namesChanged();
    select(list);
}

void MediaListManager::loadList(const QString &path)
{
    MediaList * list = new MediaList(path, m_instance);
    m_playlists.append(list);

    emit namesChanged();
    select(list);
}

MediaList *MediaListManager::currentList() const
{
    return m_selectedList;
}

void MediaListManager::rename(int idx, const QString & name)
{
    m_playlists.at(idx)->setName(name);
}

void MediaListManager::rename(const QString &old_name, const QString &new_name)
{
    for(MediaList * list : m_playlists)
    {
        if(list->name() == old_name) list->setName(new_name);
    }
}

void MediaListManager::select(MediaList *list)
{
    m_selectedList = list;

    emit currentListChanged();
}
