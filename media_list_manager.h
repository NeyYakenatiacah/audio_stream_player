#ifndef MEDIA_LIST_MANAGER_H
#define MEDIA_LIST_MANAGER_H

#include <QObject>

class MediaListManager : public QObject
{
    Q_OBJECT
public:
    explicit MediaListManager(QObject *parent = nullptr);

signals:

public slots:

private:

    QList<MediaList *> m_playlists;
};

#endif // MEDIA_LIST_MANAGER_H
