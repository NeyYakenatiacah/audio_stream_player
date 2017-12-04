#include "settings.h"

#include <algorithm>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

Settings::Settings(QObject *parent) : QObject(parent)
{
    if(!loadSettings())
    {
        defaultSettings();
    }
}

Settings::~Settings()
{
    saveSettings();
    m_srcList.clear();
}

bool Settings::loadSettings()
{
    QFile file(QStringLiteral("settings.rs"));

    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QByteArray data = file.readAll();

    QJsonDocument settings_doc(QJsonDocument::fromJson(data));

    QJsonObject settings_obj(settings_doc.object());

    if(settings_obj.contains("autoplay"))
    {
        m_autoPlay = settings_obj["autoplay"].toBool();
    }
    else
    {
        return false;
    }

    if(settings_obj.contains("src"))
    {
        QJsonArray src_array = settings_obj["src"].toArray();

        for(const QJsonValue & val : src_array)
        {
            addSource(Source(val.toObject()));
        }
    }
    else
    {
        return false;
    }

    return true;
}

bool Settings::saveSettings() const
{
    QJsonArray src_array;

    for(const Source & src : m_srcList)
    {
        src_array.push_back(src.toJson());
    }

    QJsonObject settings_obj;

    settings_obj["autoplay"] = m_autoPlay;
    settings_obj["src"]      = src_array;

    QFile save_file(QStringLiteral("settings.rs"));

    if(!save_file.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QJsonDocument settings_doc(settings_obj);
    save_file.write(settings_doc.toJson());

    save_file.close();

    return true;
}

//Source Settings::selectSource(int idx) const
//{
//    Source src("a","b","c");




//}

void Settings::addSource(const Source &src)
{
    m_srcList.append(src);
    //std::sort(m_srcList.begin(), m_srcList.end());
}

void Settings::addSource(QString name, QString stream, QString tag)
{
    this->addSource(Source(name, stream, tag));
}

void Settings::defaultSettings()
{
    m_autoPlay = false;

    addSource("Rock 00s", "http://rock00128.streamr.ru", "//radiopleer.com/info/rock00.txt");
    addSource("Rock 90s", "http://rock90128.streamr.ru", "//radiopleer.com/info/rock90.txt");
    addSource("Rock 80s", "http://rock80128.streamr.ru", "//radiopleer.com/info/rock80.txt");
    addSource("Rock 70s", "http://rock70128.streamr.ru", "//radiopleer.com/info/rock70.txt");
    //addSource("Heavy Rock", "", "");
    //addSource("", "", "");
    //addSource("", "", "");
}
