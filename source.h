#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class Source : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString stream READ stream_url WRITE setStream_url NOTIFY streamUrlChanged)
    Q_PROPERTY(QString tag READ tag_url WRITE setTag_url NOTIFY tagUrlChanged)

public:

    explicit Source(QObject * parent = nullptr);
    explicit Source(QString name, QString stream_url, QString tag_url, QObject * parent = nullptr);
    explicit Source(const QJsonObject & obj);
    explicit Source(const Source & other);
    explicit Source(Source && other);

    QJsonObject toJson() const;

    QString name() const;
    void setName(const QString & name);

    QString stream_url() const;
    void setStream_url(const QString & stream_url);

    QString tag_url() const;
    void setTag_url(const QString & tag_url);

    bool operator <(const Source & other) const;
    bool operator >(const Source & other) const;
    void operator =(const Source & other);

signals:
    void nameChanged();
    void streamUrlChanged();
    void tagUrlChanged();

private:
    QString m_name;
    QString m_stream_url;
    QString m_tag_url;
};

#endif // SOURCE_H
