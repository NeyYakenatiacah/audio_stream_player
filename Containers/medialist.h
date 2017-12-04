#ifndef MEDIALIST_H
#define MEDIALIST_H

#include <QObject>

class MediaSource;
class MediaList : public QObject
{
    Q_OBJECT
public:
    explicit MediaList(QObject *parent = nullptr);
    virtual ~MediaList();

    MediaSource * getMedia(int) const;

    void addMediaSource(const QString & path);
    void removeMediaSource(const MediaSource * src);


signals:
    void listChanged();

public slots:

private:

    void saveListAs(const QString & path) const;
    void loadListFrom(const QString & path);
    void loadDefaultList();

    QList<MediaSource *> m_sources;

};

#endif // MEDIALIST_H
