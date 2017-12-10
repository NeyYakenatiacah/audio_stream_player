#ifndef IFILTER_H
#define IFILTER_H

#include "Containers/media_source.h"

class IFilter
{
public:
    virtual bool operator() (const MediaSource * src) const = 0;
    virtual bool filter(const MediaSource * src) const = 0;
    virtual Vlc::Meta type() const =0;
};

#endif // IFILTER_H
