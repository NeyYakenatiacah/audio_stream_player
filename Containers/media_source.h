#ifndef MEDIA_SOURCE_H
#define MEDIA_SOURCE_H

#include <memory>
#include <QObject>

class VlcMedia;

class MediaSource : public QObject
{
    Q_OBJECT
public:
    explicit MediaSource(QObject *parent = nullptr);

signals:

public slots:

private:
    std::shared_ptr<VlcMedia*> m_media;
};

#endif // MEDIA_SOURCE_H
