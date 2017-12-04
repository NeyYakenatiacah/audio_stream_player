#ifndef METADATA_H
#define METADATA_H

#include <string>

class MetaData
{
public:
    MetaData();
    MetaData(const MetaData & other);
    MetaData(MetaData && other);
    ~MetaData();

    std::string keys() const;
    bool contains(const std::string & key) const;

    std::string   operator[](const std::string & key) const;
    std::string & operator[](const std::string & key);

};

#endif // METADATA_H
