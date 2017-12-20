#ifndef MEDIALIST_H
#define MEDIALIST_H

#include <QObject>
#include <QQmlListProperty>

#include <VLCQtCore/Enums.h>

class FilterManager;
class MediaListPrivate;
class MediaSource;
class VlcInstance;

class MediaList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<MediaSource> sources READ sources)
public:
    explicit MediaList(VlcInstance * instance);
    explicit MediaList(const QString & path, VlcInstance * instance);
    virtual ~MediaList();

    MediaSource * getCurrentMedia() const;
    int           getCurrentMediaIdx() const;

    MediaSource * getMedia(int) const;

    void addMediaSource(const QString & path);
    void removeMediaSource(const MediaSource * src);

    Q_INVOKABLE void openLocalFile(const QString & path);
    Q_INVOKABLE void openUrl(const QString& url);

    Q_INVOKABLE void sort(const Vlc::Meta & type);

    Q_INVOKABLE void search(const Vlc::Meta & type, const QString & tag);

    QQmlListProperty<MediaSource> sources();
    void appendSource(MediaSource * src);
    int count() const;
    MediaSource * source(int idx) const;
    void clearSources();

signals:

    void reloaded();
    void added(MediaSource *);

public slots:

private:

    //bool saveBufferList(path);
    bool saveListAs(const QString & path) const;
    bool loadListFrom(const QString & path);

//!  Source list interactions for QML
    static void          append_source (QQmlListProperty<MediaSource> * list, MediaSource * src);
    static int           source_count  (QQmlListProperty<MediaSource> * list);
    static MediaSource * source_at     (QQmlListProperty<MediaSource> * list, int idx);
    static void          clear_sources (QQmlListProperty<MediaSource> * list);

    VlcInstance * m_instance;
    //MediaSource * selectedMedia;
    //QList<MediaSource *> m_buffer;

    FilterManager * m_filterManager;

    MediaListPrivate * m_data;
    QList<MediaSource *> m_sources;
};

#endif // MEDIALIST_H
