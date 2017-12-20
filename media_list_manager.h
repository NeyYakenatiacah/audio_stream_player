#ifndef MEDIA_LIST_MANAGER_H
#define MEDIA_LIST_MANAGER_H

#include <QObject>

class MediaList;
class VlcInstance;

class MediaListManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MediaList* currentList READ currentList NOTIFY currentListChanged)
    Q_PROPERTY(QStringList names READ names NOTIFY namesChanged)

public:
    explicit MediaListManager(VlcInstance * instance);

    QStringList names() const;

    Q_INVOKABLE void select(const QString & name);

    Q_INVOKABLE void createList (const QString & name);
    Q_INVOKABLE void loadList   (const QString & path);

    MediaList * currentList() const;

signals:

    void currentListChanged();
    void namesChanged();

private:

    void select(MediaList * list);

    VlcInstance * m_instance;

    MediaList * m_selectedList;
    QList<MediaList *> m_playlists;

};

#endif // MEDIA_LIST_MANAGER_H
