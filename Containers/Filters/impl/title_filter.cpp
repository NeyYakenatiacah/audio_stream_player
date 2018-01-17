#include "title_filter.h"

TitleFilter::TitleFilter(const QString & sub_string)
{
    m_requiredTitle = sub_string;
}

TitleFilter::~TitleFilter()
{

}

bool TitleFilter::operator ()(const MediaSource *src) const
{
    if(src->title().contains(m_requiredTitle, Qt::CaseInsensitive)) return true;
    return false;
}

bool TitleFilter::filter(const MediaSource *src) const
{
    if(src->title().contains(m_requiredTitle, Qt::CaseInsensitive)) return true;
    return false;
}

Vlc::Meta TitleFilter::type() const
{
    return Vlc::Meta::Title;
}

void TitleFilter::setRequired(const QString &sub_string)
{
    m_requiredTitle = sub_string;
}
