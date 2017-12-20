#ifndef NAME_FILTER_H
#define NAME_FILTER_H

#include <Containers/Filters/ifilter.h>

class TitleFilter : public IFilter
{
public:
    explicit TitleFilter(const QString & sub_string);
    virtual ~TitleFilter();

    // IFilter interface
    virtual bool operator ()(const MediaSource *src) const override;
    virtual bool filter(const MediaSource * src) const override;
    virtual Vlc::Meta type() const override;

    void setRequired(const QString & sub_string);
private:
    QString m_requiredTitle;
};

#endif // NAME_FILTER_H
