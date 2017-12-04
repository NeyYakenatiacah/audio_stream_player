#include "source.h"

#include <QJsonObject>

Source::Source(QObject *parent)
    : m_name(QString()), m_stream_url(QString()), m_tag_url(QString()), QObject(parent)
{
}

Source::Source(QString name, QString stream_url, QString tag_url, QObject *parent)
    : m_name(name), m_stream_url(stream_url), m_tag_url(tag_url), QObject(parent)
{
}

Source::Source(const QJsonObject &obj)
    : QObject(nullptr)
{
    m_name       = obj["name"].toString();
    m_stream_url = obj["stream"].toString();
    m_tag_url    = obj["tag"].toString();
}

Source::Source(const Source &other)
    : m_name(other.m_name), m_stream_url(other.m_stream_url), m_tag_url(other.m_tag_url), QObject(other.parent())
{
}

Source::Source(Source &&other)
    : m_name(std::move(other.m_name)), m_stream_url(std::move(other.m_stream_url)), m_tag_url(std::move(other.m_tag_url))
{
}

QJsonObject Source::toJson() const
{
    QJsonObject obj;

    obj["name"]   = m_name;
    obj["stream"] = m_stream_url;
    obj["tag"]    = m_tag_url;

    return obj;
}

QString Source::tag_url() const
{
    return m_tag_url;
}

void Source::setTag_url(const QString &tag_url)
{
    if(tag_url != m_tag_url)
    {
        m_tag_url = tag_url;
        emit tagUrlChanged();
    }
}

bool Source::operator <(const Source &other) const
{
    if(m_name < other.m_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Source::operator >(const Source &other) const
{
    if(m_name > other.m_name)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Source::operator =(const Source &other)
{
    m_name = other.m_name;
    m_stream_url = other.m_stream_url;
    m_tag_url = other.m_tag_url;
}

QString Source::stream_url() const
{
    return m_stream_url;
}

void Source::setStream_url(const QString &stream_url)
{
    if(stream_url != m_stream_url)
    {
        m_stream_url = stream_url;
        emit streamUrlChanged();
    }
}

QString Source::name() const
{
    return m_name;
}

void Source::setName(const QString &name)
{
    if(name != m_name)
    {
        m_name = name;
        emit nameChanged();
    }
}
