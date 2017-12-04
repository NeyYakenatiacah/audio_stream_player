#ifndef MEDIASOURCE_H
#define MEDIASOURCE_H

#include <QObject>
#include "Containers/constants.h"
#include "Containers/metadata.h"

class MediaSource : public QObject
{
    Q_OBJECT


public:
    static MediaSource * instance(const QString & path, QObject *parent = nullptr);
    static MediaSource * instance(MetaData metaData, QObject *parent = nullptr);
    static MediaSource * instance(const QJsonObject & obj, QObject *parent = nullptr);

    bool isValid() const;

    QString getMetaData(const QString &key) const;
    void setValue();

    asp::Format format() const;

    QString & operator [] (const QString & key);
    QString & operator [] (const QString & key) const;


signals:

public slots:

private:

    explicit MediaSource(const QString & path, QObject *parent = nullptr);
    explicit MediaSource(MetaData metaData, QObject *parent = nullptr);
    explicit MediaSource(const QJsonObject & obj, QObject *parent = nullptr);

    bool isPathValid() const;

    MetaData m_data;
};

#endif // MEDIASOURCE_H
