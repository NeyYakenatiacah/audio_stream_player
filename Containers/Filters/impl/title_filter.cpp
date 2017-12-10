#include "title_filter.h"

TitleFilter::TitleFilter(const QString & sub_string)
{
    m_requiredTitle = sub_string;
}

bool TitleFilter::operator ()(const MediaSource *src)
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
