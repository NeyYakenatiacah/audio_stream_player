#ifndef MEDIA_SOURCE_H
#define MEDIA_SOURCE_H

#include <VLCQtCore/Media.h>

class MediaSource : public VlcMedia
{
    Q_OBJECT
public:
    explicit MediaSource(const QString &location, bool localFile, VlcInstance *instance);
    explicit MediaSource(const QString &location, VlcInstance *instance);
    virtual ~MediaSource();

    const QJsonObject & toJson() const;
signals:

public slots:

private:

};

#endif // MEDIA_SOURCE_H
