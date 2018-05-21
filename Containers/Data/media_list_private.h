#ifndef MEDIA_LIST_PRIVATE_H
#define MEDIA_LIST_PRIVATE_H

#include <QObject>

class MediaSource;
class VlcInstance;

class MediaListPrivate : public QObject
{
    Q_OBJECT
public:
    explicit MediaListPrivate(VlcInstance *instance = nullptr);
    MediaListPrivate(const QString & name, VlcInstance * instance);
    virtual ~MediaListPrivate();

    void openMedia(const QString & location, bool isLocalFile);
    void openMedia(MediaSource * src);
    void removeMedia(MediaSource * src);

    QList<MediaSource *>::const_iterator begin() const;
    QList<MediaSource *>::const_iterator end()   const;

    int size() const;

    bool load(const QString & path);
    bool save(const QString & path);

    QJsonObject jsonExport() const;
    bool jsonImport(const QJsonObject & obj);

    QString name() const;
    void setName(const QString &name);

signals:
    void reloaded();
    void added(MediaSource *);
    void removed(MediaSource *);
    void nameChanged();
//    void removed(MediaSource *);

public slots:

private:
    QString m_name;
    VlcInstance * m_instance;
    QList<MediaSource *> m_sources;
};

#endif // MEDIA_LIST_PRIVATE_H
