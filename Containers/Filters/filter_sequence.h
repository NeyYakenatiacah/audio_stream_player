#ifndef FILTERSEQUENCE_H
#define FILTERSEQUENCE_H

#include <QList>

class IFilter;
class MediaSource;

class FilterSequence
{
public:
    FilterSequence(const QList<IFilter *> & filters);

    bool operator ()(const MediaSource *src);

private:

    QList<IFilter *> m_filters;
};

#endif // FILTERSEQUENCE_H
