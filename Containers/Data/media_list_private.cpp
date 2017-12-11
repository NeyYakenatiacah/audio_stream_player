#include "media_list_private.h"

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>

#include <Containers/media_source.h>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

MediaListPrivate::MediaListPrivate(VlcInstance * instance) : QObject(instance)
{
    m_instance = instance ? instance : new VlcInstance(VlcCommon::args());
}

MediaListPrivate::~MediaListPrivate()
{
    if(!this->parent()) delete m_instance;
}

void MediaListPrivate::openMedia(const QString &location, bool isLocalFile)
{
    MediaSource * src = new MediaSource(location, isLocalFile, m_instance);

    connect(src, &MediaSource::prepareToRemove, this, [this]()
    {
        MediaSource * source = qobject_cast<MediaSource*>(this->sender());
        m_sources.removeAll(source);
    });

    m_sources.append(src);

    emit added(src);
}

QList<MediaSource *>::const_iterator MediaListPrivate::begin() const
{
    return m_sources.constBegin();
}

QList<MediaSource *>::const_iterator MediaListPrivate::end() const
{
    return m_sources.constEnd();
}

bool MediaListPrivate::load(const QString &path)
{
    Q_UNUSED(path)

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
        obj["list"] = array;

        QJsonDocument doc(obj);

        out.write(doc.toJson());

        out.close();

        return true;
    }

    return false;
}
