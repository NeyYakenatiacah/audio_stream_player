#include "media_source.h"
#include <QJsonObject>
//#include <VLCQtCore/Media.h>
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

MediaSource::~MediaSource()
{
    emit prepareToRemove();

    delete m_metaManager;
}

MediaSource *MediaSource::fromJson(const QJsonObject &json, VlcInstance *instance)
{
    if(json.contains(QStringLiteral("path")))
    {
        QString location = json[QStringLiteral("path")].toString();

        return new MediaSource(location, true, instance);
    }
    else if(json.contains(QStringLiteral("url")))
    {
        QString location = json[QStringLiteral("url")].toString();

        return new MediaSource(location, instance);
    }
    else
    {
        return nullptr;
    }
}

const QJsonObject MediaSource::toJson() const
{
    QJsonObject obj;

    return obj;
}

void MediaSource::select() const
{

}

// Properties

QString MediaSource::title() const
{
    return m_metaManager->title();
}

void MediaSource::setTitle(const QString &title)
{
    if(title != this->title()) m_metaManager->setTitle(title);
}

QString MediaSource::artist() const
{
    return m_metaManager->artist();
}

void MediaSource::setArtist(const QString &artist)
{
    if(artist != this->artist()) m_metaManager->setArtist(artist);
}

QString MediaSource::genre() const
{
    return m_metaManager->genre();
}

void MediaSource::setGenre(const QString &genre)
{
    if(genre != this->genre()) m_metaManager->setGenre(genre);
}

QString MediaSource::copyright() const
{
    return m_metaManager->copyright();
}

void MediaSource::setCopyright(const QString &copyright)
{
    if(copyright != this->copyright()) m_metaManager->setCopyright(copyright);
}

QString MediaSource::album() const
{
    return m_metaManager->album();
}

void MediaSource::setAlbum(const QString &album)
{
    if(album != this->album()) m_metaManager->setAlbum(album);
}

int MediaSource::trackNumber() const
{
    return m_metaManager->number();
}

void MediaSource::setTrackNumber(int trackNumber)
{
    if(trackNumber != this->trackNumber()) m_metaManager->setNumber(trackNumber);
}

QString MediaSource::description() const
{
    return m_metaManager->description();
}

void MediaSource::setDescription(const QString &description)
{
    if(description != this->description()) m_metaManager->setDescription(description);
}

QString MediaSource::rating() const
{
    return m_metaManager->rating();
}

int MediaSource::year() const
{
    return m_metaManager->year();
}

void MediaSource::setYear(int year)
{
    if(year != this->year()) m_metaManager->setYear(year);
}

QString MediaSource::setting() const
{
    return m_metaManager->setting();
}

void MediaSource::setSetting(const QString &setting)
{
    //m_metaManager->set
    //m_setting = setting;
}

QString MediaSource::url() const
{
    return m_metaManager->url();
}

QString MediaSource::language() const
{
    return m_metaManager->language();
}

void MediaSource::setLanguage(const QString &language)
{
    if(language != this->language()) m_metaManager->setLanguage(language);
}

QString MediaSource::publisher() const
{
    return m_metaManager->publisher();
}

void MediaSource::setPublisher(const QString &publisher)
{
    if(publisher != this->publisher()) m_metaManager->setPublisher(publisher);
}

QString MediaSource::encoder() const
{
    return m_metaManager->encoder();
}

void MediaSource::setEncoder(const QString &encoder)
{
    if(encoder != this->encoder()) m_metaManager->setEncoder(encoder);
}

QString MediaSource::artwork() const
{
    return m_metaManager->artwork();
}

QString MediaSource::trackID() const
{
    return m_metaManager->id();
}

void MediaSource::init()
{
    connect(this, &MediaSource::metaChanged, this, [this](const Vlc::Meta &meta)
    {
        switch(meta)
        {
        case Vlc::Meta::Title:
            emit titleChanged();
            break;

        case Vlc::Meta::Artist:
            emit artistChanged();
            break;

        case Vlc::Meta::Genre:
            emit genreChanged();
            break;

        case Vlc::Meta::Copyright:
            emit copyrightChanged();
            break;

        case Vlc::Meta::Album:
            emit albumChanged();
            break;

        case Vlc::Meta::TrackNumber:
            emit trackNumberChanged();
            break;

        case Vlc::Meta::Description:
            emit descriptionChanged();
            break;

        case Vlc::Meta::Rating:
            emit ratingChanged();
            break;

        case Vlc::Meta::Date:
            emit yearChanged();
            break;

        case Vlc::Meta::Setting:
            emit settingChanged();
            break;

        case Vlc::Meta::URL:
            emit urlChanged();
            break;

        case Vlc::Meta::Language:
            emit languageChanged();
            break;

        case Vlc::Meta::NowPlaying:
            emit nowPlaying();
            break;

        case Vlc::Meta::Publisher:
            emit publisherChanged();
            break;

        case Vlc::Meta::EncodedBy:
            emit encoderChanged();
            break;

        case Vlc::Meta::ArtworkURL:
            emit artworkChanged();
            break;

        case Vlc::Meta::TrackID:
            emit trackIDChanged();
            break;
        }
    });
}
