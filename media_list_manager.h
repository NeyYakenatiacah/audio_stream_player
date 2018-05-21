#ifndef MEDIA_LIST_MANAGER_H
#define MEDIA_LIST_MANAGER_H

#include <QObject>


class MediaList;
class Settings;
class VlcInstance;

class MediaListManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(MediaList* currentList READ currentList NOTIFY currentListChanged)
    Q_PROPERTY(QStringList names READ names NOTIFY namesChanged)

public:

    MediaListManager(VlcInstance * instance, Settings *settings);
    virtual ~MediaListManager();

    QStringList names() const;

    Q_INVOKABLE void select(const QString & name);

    Q_INVOKABLE void createList ();
    Q_INVOKABLE void createList (const QString & name);

    Q_INVOKABLE void loadList   (const QString & path);

    MediaList * currentList() const;
    Q_INVOKABLE int currentIdx() const;

    Q_INVOKABLE void rename(int idx, const QString &name);
    Q_INVOKABLE void rename(const QString & old_name, const QString & new_name);

signals:

    void currentListChanged();
    void namesChanged();

private:

    void createList(MediaList * list);

    bool load();
    bool save();

    void select(MediaList * list);

    VlcInstance * m_instance;

    MediaList * m_selectedList;
    QList<MediaList *> m_playlists;

    static int m_metaCounter;

    Settings * m_settings;
};

#endif // MEDIA_LIST_MANAGER_H
