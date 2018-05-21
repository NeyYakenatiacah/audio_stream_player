#include "media_list_private.h"

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>

#include <Containers/media_source.h>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDebug>

MediaListPrivate::MediaListPrivate(VlcInstance * instance) : QObject(instance)
{
    m_instance = instance ? instance : new VlcInstance(VlcCommon::args());
}

MediaListPrivate::MediaListPrivate(const QString &name, VlcInstance *instance)
{
    m_instance = instance ? instance : new VlcInstance(VlcCommon::args());
    m_name = name;
}

MediaListPrivate::~MediaListPrivate()
{
    //if(!this->parent()) delete m_instance;
    qDebug() << "MLP~~";
//    for(MediaSource * src : m_sources)
//    {
//        delete src;
//    }
}

void MediaListPrivate::openMedia(const QString &location, bool isLocalFile)
{
    MediaSource * src = new MediaSource(location, isLocalFile, m_instance);

    openMedia(src);
}

void MediaListPrivate::openMedia(MediaSource *src)
{
    if(src->parsed())
    {
        m_sources.append(src);

        connect(src, &MediaSource::prepareToRemove, this, [this]()
        {
            MediaSource * source = qobject_cast<MediaSource*>(this->sender());
            m_sources.removeAll(source);
        });

        emit added(src);
    }
}

void MediaListPrivate::removeMedia(MediaSource *src)
{
    int idx = 0;
    for(auto it = m_sources.begin(); it != m_sources.end(); ++it)
    {
        if((*it) == src)
        {
            m_sources.erase(it);
            emit removed(src);
            delete src;
        }
        idx++;
    }
}

QList<MediaSource *>::const_iterator MediaListPrivate::begin() const
{
    return m_sources.constBegin();
}

QList<MediaSource *>::const_iterator MediaListPrivate::end() const
{
    return m_sources.constEnd();
}

int MediaListPrivate::size() const
{
    return m_sources.size();
}

bool MediaListPrivate::load(const QString &path)
{
    Q_UNUSED(path)

    emit reloaded();

    return false;
}

bool MediaListPrivate::save(const QString &path)
{
    QFile out(path);

    if(out.open(QIODevice::WriteOnly))
    {
        QJsonArray array;

        for(const MediaSource * src : m_sources)
        {
            QJsonObject obj = src->toJson();
            array.append(obj.value(QStringLiteral("media")));
        }

        QJsonObject obj;
        obj["name"] = m_name;
        obj["list"] = array;

        QJsonDocument doc(obj);

        out.write(doc.toJson());

        out.close();

        return true;
    }

    return false;
}

QJsonObject MediaListPrivate::jsonExport() const
{
    QJsonArray array;

    for(const MediaSource * src : m_sources)
    {
        QJsonObject obj = src->toJson();
        array << obj;
    }

    QJsonObject obj;
    qDebug() << "Save: name: " << m_name;
    obj["name"] = m_name;
    qDebug() << "Save: size: " << array.size() << " " << m_sources.size();
    obj["list"] = array;

    return obj;
}

bool MediaListPrivate::jsonImport(const QJsonObject &obj)
{
    qDebug() << "JsonImport";
    if(obj.contains("name"))
    {
        m_name = obj["name"].toString();
    }
    else
    {
        return false;
    }

    if(obj.contains("list"))
    {
        QJsonArray array = obj["list"].toArray();

        for(const QJsonValue & val : array)
        {
            QJsonObject obj = val.toObject();
            MediaSource * src = MediaSource::fromJson(obj, m_instance);

            m_sources << src;
        }
    }
    emit reloaded();
    return true;
}

QString MediaListPrivate::name() const
{
    return m_name;
}

void MediaListPrivate::setName(const QString &name)
{
    m_name = name;
    emit nameChanged();
}
