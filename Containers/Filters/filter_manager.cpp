#include "filter_manager.h"

#include <QtConcurrent/QtConcurrentFilter>

#include "filter_sequence.h"
#include "ifilter.h"

#include "impl/title_filter.h"

FilterManager::FilterManager(QObject *parent)
    : QObject(parent)
{
}

FilterManager::~FilterManager()
{
    clear();
}

void FilterManager::clear()
{
    for(IFilter * filter : m_filters)
    {
        delete filter;
    }

    m_filters.clear();
}

void FilterManager::append(const QString &filterName, const QVariant &value)
{
    if(filterName == "Title")
    {
        append(Vlc::Meta::Title, value);
    }
    /*else if()
    {

    }*/
}

void FilterManager::append(const Vlc::Meta &tag, const QVariant &value)
{
    switch(tag)
    {
    case Vlc::Meta::Title:
    {
        IFilter * title_filter = nullptr;
        for(IFilter * filter : m_filters)
        {
            if(filter->type() == tag) title_filter = filter;
        }

        if(title_filter)
        {
            TitleFilter * filter = dynamic_cast<TitleFilter *>(title_filter);
            if(filter)
            {
                filter->setRequired(value.toString());
                break;
            }
        }

        m_filters.append(new TitleFilter(value.toString()));
    }
    break;

    default:
        break;
    }

    emit preparedToFiltration();
}

QStringList FilterManager::availableFilters() const
{
    QStringList filterList;

    filterList << "Title";

    return filterList;
}

QList<MediaSource *> FilterManager::filter(QList<MediaSource *> src)
{
//    QFuture<QList<MediaSource *>> dst_list = QtConcurrent::filteredReduced(src, FilterSequence(m_filters), [this](QList<MediaSource *> & dst, MediaSource * src)
//    {
//        dst.append(src);
//    });

//    return dst_list.result();
    QList<MediaSource*> list;
    return list;
}
