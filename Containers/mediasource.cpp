#include "mediasource.h"

bool isFormatValid(const QString & format)
{
    Q_UNUSED(format)
    return true;
}

bool isPathValid(const QString & path)
{
    Q_UNUSED(path)
    return true;
}

MediaSource::MediaSource(const QString &path, QObject *parent)
    : QObject(parent)
{

}

MediaSource::MediaSource(MetaData metaData, QObject *parent)
    : QObject(parent)
{
    m_data = metaData;
}

MediaSource::MediaSource(const QJsonObject &obj, QObject * parent)
    : QObject(parent)
{
    //m_data = MetaData::fromJson(obj);
}

MediaSource *MediaSource::instance(const QString &path, QObject *parent)
{

}

MediaSource *MediaSource::instance(MetaData metaData, QObject *parent)
{

}

MediaSource *MediaSource::instance(const QJsonObject &obj, QObject *parent)
{

}

QString MediaSource::getMetaData(const QString &key) const
{
    return m_data[key];
}

QString & MediaSource::operator [] (const QString &key)
{
    if(m_data.contains(key))
        return m_data[key];
    return QString();
}

QString &MediaSource::operator [] (const QString &key) const
{
    if(m_data.contains(key))
        return m_data[key];
    return QString();
}

