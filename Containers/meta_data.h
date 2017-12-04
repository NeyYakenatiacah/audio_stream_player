#ifndef METADATA_H
#define METADATA_H

class QJsonObject;
class QString;

class MetaData
{
public:
    MetaData();
    MetaData(const MetaData & other);
    MetaData(MetaData && other);
    ~MetaData();

    QString keys() const;
    bool contains(const QString & key) const;

    QString   operator[](const QString & key) const;
    QString & operator[](const QString & key);

    static MetaData fromJson(const QJsonObject & obj);
    QJsonObject toJson() const;
private:
    // some data
};

#endif // METADATA_H
