#ifndef FILTER_MANAGER_H
#define FILTER_MANAGER_H

#include <VLCQtCore/Enums.h>

class IFilter;
class MediaSource;

class FilterManager : public QObject
{
    Q_OBJECT
public:
    explicit FilterManager(QObject * parent = nullptr);
    virtual ~FilterManager();

    void clear();

    void append(const QString & filterName, const QVariant & value);
    void append(const Vlc::Meta & tag, const QVariant & value);

    QStringList availableFilters() const;

    QList<MediaSource *> filter(QList<MediaSource *> src);
    QList<MediaSource *> filter(const QList<MediaSource *>::const_iterator & begin,
                                const QList<MediaSource *>::const_iterator & end);

signals:
    void preparedToFiltration();

private:

    QList<IFilter *> m_filters;
};

#endif // FILTER_MANAGER_H
