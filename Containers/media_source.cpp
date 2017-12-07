#include "media_source.h"
#include <QJsonObject>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MetaManager.h>

MediaSource::MediaSource(const QString & location, bool localFile, VlcInstance * instance)
    : VlcMedia(location, localFile, instance)
{
    m_metaManager = new VlcMetaManager(this);
}

MediaSource::MediaSource(const QString & location, VlcInstance * instance)
    : VlcMedia(location, instance)
{
    m_metaManager = new VlcMetaManager(this);
}

MediaSource::MediaSource(const QJsonObject & json, VlcInstance * instance)
{
    if(json.contains(QStringLiteral("path")))
    {
        QString location = json[QStringLiteral("path")].toString();

        VlcMedia(location, true, instance);
    }
    else if(json.contains(QStringLiteral("url")))
    {
        QString location = json[QStringLiteral("url")].toString();

        VlcMedia(location, instance);
    }
    else
    {
        QString("", instance);
    }

    m_metaManager = new VlcMetaManager(this);

}

MediaSource::~MediaSource()
{
    delete m_metaManager;
}

const QJsonObject &MediaSource::toJson() const
{
    QJsonObject obj;

    return obj;
}

void MediaSource::init()
{
    connect(this, &MediaSource::metaChanged, this, [this](const Vlc::Meta &meta)
    {
        if(meta == Vlc::Meta::Title)
        {

        }
        else if(meta == Vlc::Meta::Album)
        {

        }
        else if(meta == Vlc::Meta::Artist)
        {

        }
    });
}
