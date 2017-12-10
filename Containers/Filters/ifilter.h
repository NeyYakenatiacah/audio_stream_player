#ifndef IFILTER_H
#define IFILTER_H

#include "Containers/media_source.h"

class IFilter
{
public:
    virtual bool operator() (const MediaSource * src) = 0;
    virtual Vlc::Meta type() const =0;
};

#endif // IFILTER_H
