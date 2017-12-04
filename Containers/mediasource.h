#ifndef MEDIASOURCE_H
#define MEDIASOURCE_H

#include <QObject>
#include "Containers/constants.h"

class MediaSource : public QObject
{
    Q_OBJECT
public:
    explicit MediaSource(const QString & path, QObject *parent = nullptr);
    explicit MediaSource(QVariantMap metaData, QObject *parent = nullptr);

    QVariant getMetaData(const Qstring & key) const;

    asp::Format format() const;

signals:

public slots:

private:

    QVariantMap m_metaData;
    QString source_path;

};

#endif // MEDIASOURCE_H
