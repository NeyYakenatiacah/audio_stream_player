#include "filter_sequence.h"

#include "ifilter.h"

FilterSequence::FilterSequence(const QList<IFilter *> &filters)
{
    m_filters = filters;
}

bool FilterSequence::operator ()(const MediaSource * src)
{
    for(const IFilter * filter : m_filters)
    {
        if(!filter->filter(src)) return false;
    }

    return true;
}
