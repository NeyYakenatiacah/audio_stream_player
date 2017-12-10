#ifndef MEDIA_SOURCE_H
#define MEDIA_SOURCE_H

#include <VLCQtCore/Media.h>

class VlcMetaManager;

class MediaSource : public VlcMedia
{
    Q_OBJECT

    Q_PROPERTY(QString artwork     READ artwork     NOTIFY artworkChanged )
    Q_PROPERTY(QString trackID     READ trackID     NOTIFY trackIDChanged )
    Q_PROPERTY(QString rating      READ rating      NOTIFY ratingChanged  )
    Q_PROPERTY(QString setting     READ setting     NOTIFY settingChanged )
    Q_PROPERTY(QString url         READ url         NOTIFY urlChanged     )

    Q_PROPERTY(QString title       READ title       WRITE setTitle       NOTIFY positionChanged    ) //!
    Q_PROPERTY(QString artist      READ artist      WRITE setArtist      NOTIFY artistChanged      ) //!
    Q_PROPERTY(QString genre       READ genre       WRITE setGenre       NOTIFY genreChanged       ) //!
    Q_PROPERTY(QString copyright   READ copyright   WRITE setCopyright   NOTIFY copyrightChanged   )
    Q_PROPERTY(QString album       READ album       WRITE setAlbum       NOTIFY albumChanged       ) //!
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged )    // ?
    Q_PROPERTY(QString language    READ language    WRITE setLanguage    NOTIFY languageChanged    )    // ??
    Q_PROPERTY(QString publisher   READ publisher   WRITE setPublisher   NOTIFY publisherChanged   )
    Q_PROPERTY(QString encoder     READ encoder     WRITE setEncoder     NOTIFY encoderChanged     ) // ????
    Q_PROPERTY(  int   trackNumber READ trackNumber WRITE setTrackNumber NOTIFY trackNumberChanged )
    Q_PROPERTY(  int   year        READ year        WRITE setYear        NOTIFY yearChanged        )    // ??

    Q_ENUM(Vlc::Meta)

public:
    explicit MediaSource(const QString & location, bool localFile, VlcInstance * instance);
    explicit MediaSource(const QString & location, VlcInstance * instance);
    explicit MediaSource(const QJsonObject & json, VlcInstance * instance);
    virtual ~MediaSource();

    const QJsonObject & toJson() const;

    // Properties

    QString title() const;
    void setTitle(const QString &title);

    QString artist() const;
    void setArtist(const QString &artist);

    QString genre() const;
    void setGenre(const QString &genre);

    QString copyright() const;
    void setCopyright(const QString &copyright);

    QString album() const;
    void setAlbum(const QString &album);

    int trackNumber() const;
    void setTrackNumber(int trackNumber);

    QString description() const;
    void setDescription(const QString &description);

    QString rating() const;

    int year() const;
    void setYear(int year);

    QString setting() const;
    void setSetting(const QString &setting);

    QString url() const;

    QString language() const;
    void setLanguage(const QString &language);

    QString publisher() const;
    void setPublisher(const QString &publisher);

    QString encoder() const;
    void setEncoder(const QString &encoder);

    QString artwork() const;

    QString trackID() const;

signals:
    void titleChanged();
    void artistChanged();
    void genreChanged();
    void copyrightChanged();
    void albumChanged();
    void trackNumberChanged();
    void descriptionChanged();
    void ratingChanged();
    void yearChanged();
    void settingChanged();
    void urlChanged();
    void languageChanged();
    void publisherChanged();
    void encoderChanged();
    void artworkChanged();
    void trackIDChanged();
    void nowPlaying();

    void prepareToRemove();

public slots:

private:
    QString m_title;
    QString m_artist;
    QString m_genre;
    QString m_copyright;
    QString m_album;
    QString m_trackNumber;
    QString m_description;
    QString m_rating;
    QString m_date;
    QString m_setting;
    QString m_url;
    QString m_language;
    QString m_nowPlaying;
    QString m_publisher;
    QString m_encodedBy;
    QString m_artworkURL;
    QString m_trackID;


    void init();

    VlcMetaManager * m_metaManager;

};

#endif // MEDIA_SOURCE_H
