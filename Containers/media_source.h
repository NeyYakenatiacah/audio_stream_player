#ifndef MEDIA_SOURCE_H
#define MEDIA_SOURCE_H

#include <VLCQtCore/Media.h>

class VlcMetaManager;

class MediaSource : public VlcMedia
{
    Q_OBJECT
public:
    explicit MediaSource(const QString & location, bool localFile, VlcInstance * instance);
    explicit MediaSource(const QString & location, VlcInstance * instance);
    explicit MediaSource(const QJsonObject & json, VlcInstance * instance);
    virtual ~MediaSource();

    const QJsonObject & toJson() const;

signals:

public slots:

private:
    void init();

    VlcMetaManager * m_metaManager;

};

#endif // MEDIA_SOURCE_H
