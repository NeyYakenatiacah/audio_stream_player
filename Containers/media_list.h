#ifndef MEDIALIST_H
#define MEDIALIST_H

#include <QObject>

class MediaSource;
class VlcInstance;

class MediaList : public QObject
{
    Q_OBJECT
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

    Q_INVOKABLE void sort(/* const Vlc::Meta & tag */);

    Q_INVOKABLE void search(const QString & tag);

signals:
    void reloaded();


public slots:

private:

    void saveListAs(const QString & path) const;
    void loadListFrom(const QString & path);
    void loadDefaultList();

    VlcInstance * m_instance;
    //MediaSource * selectedMedia;
    //QList<MediaSource *> m_buffer;

    QList<MediaSource *> m_sources;
};

#endif // MEDIALIST_H
