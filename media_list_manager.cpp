#include "media_list_manager.h"

#include <VLCQtCore/Instance.h>

#include "Containers/media_list.h"
#include <QDebug>

#include <experimental/filesystem>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include <settings/settings.h>

using namespace std::experimental;

MediaListManager::MediaListManager(VlcInstance *instance, Settings * settings)
    : QObject(instance)
{
    qDebug() << "MediaListManager()";
    m_settings = settings;

    m_instance = instance;
    m_selectedList = nullptr;
    if(!load()) createList();
}

MediaListManager::~MediaListManager()
{
    save();
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
    qDebug() << "Trying select " << name;

    for(MediaList * list : m_playlists)
    {
        if(list->name() == name)
        {
            select(list);
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

    createList(list);
}

void MediaListManager::createList(MediaList *list)
{
    if(list)
    {
        int counter = 0;
        for(MediaList * it_list : m_playlists)
        {
            if(it_list->name().contains(list->name())) counter++;
        }
        if(counter)
        {
            QString name = list->name() + QString(" %1").arg(counter);
            list->setName(name);
        }

        m_playlists.append(list);
        emit namesChanged();
        select(list);
    }
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

int MediaListManager::currentIdx() const
{
    int i = 0;
    for(const MediaList * list : m_playlists)
    {
        if(list == m_selectedList) return i;
        i++;
    }
    return -1;
}

void MediaListManager::rename(int idx, const QString & name)
{
    m_playlists.at(idx)->setName(name);

    emit namesChanged();
}

void MediaListManager::rename(const QString &old_name, const QString &new_name)
{
    for(MediaList * list : m_playlists)
    {
        if(list->name() == old_name)
        {
            list->setName(new_name);
            emit namesChanged();
        }
    }
}

bool MediaListManager::load()
{
    qDebug() << "MediaListManager::load()";
    filesystem::path pls_path(m_settings->playlistsPath().toStdString());
    for(const filesystem::directory_entry & entry : filesystem::directory_iterator(pls_path))
    {
        filesystem::path path = entry.path();
        std::string str = path.string();
        if(str.substr(str.size() - 4) == ".pls")
        {
            QString pls_path = QString::fromStdString(str);
            QFile in(pls_path);

            if(in.open(QIODevice::ReadOnly))
            {
                QByteArray data = in.readAll();
                QJsonDocument doc;
                if(m_settings->saveMode() == Settings::SaveMode::Binary)
                {
                    doc = QJsonDocument::fromBinaryData(data);
                }
                else if(m_settings->saveMode() == Settings::SaveMode::Json)
                {
                    doc = QJsonDocument::fromJson(data);
                }

                MediaList * list = new MediaList(m_instance, tr(""));
                if(list->loadFromJson(doc.object()))
                {
                    connect(list, &MediaList::nameChanged, this, &MediaListManager::namesChanged);
                    createList(list);
                }
                else
                {
                    delete list;
                }
                in.close();
            }
        }
    }

    return !m_playlists.empty();
}

bool MediaListManager::save()
{
    QString path = m_settings->playlistsPath();
    filesystem::path pls_path( path.toStdString() );
    if(!filesystem::exists(pls_path))
    {
        if(!filesystem::create_directory(pls_path)) return false;
    }

    for(const MediaList * list : m_playlists)
    {
        QJsonDocument list_document(list->saveToJson());

        QFile out(QString("%1/pl_%2.pls").arg(path).arg(list->name()));

        if(out.open(QIODevice::WriteOnly))
        {
            if(m_settings->saveMode() == Settings::SaveMode::Binary)
            {
                out.write(list_document.toBinaryData());
            }
            else if(m_settings->saveMode() == Settings::SaveMode::Json)
            {
                out.write(list_document.toJson());
            }
            out.close();
        }
    }

    return true;
}

void MediaListManager::select(MediaList *list)
{
    if(m_selectedList != list)
    {
        m_selectedList = list;

        emit currentListChanged();
    }
}
