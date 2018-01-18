#include "settings.h"

#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStyle>

#include <QDebug>

Settings::Settings(QObject *parent) : QObject(parent)
{
    m_palette = new Palette(this);

    if(!load())
    {
        defaultSettings();
    }
}

Settings::~Settings()
{
    save();
    //if (save())
    qDebug() << "~Settings";
}

void Settings::defaultSettings()
{
    m_palette->defaultPalette();
//    m_palette.default();
}

bool Settings::load()
{
    QFile loadFile(QStringLiteral("pls.stg"));

    if(!loadFile.open(QIODevice::ReadOnly)) return false;

    QByteArray data = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromBinaryData(data));

    QJsonObject obj(loadDoc.object());

    try
    {
        m_palette->fromJson(obj);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

bool Settings::save()
{
    QFile saveFile(QStringLiteral("pls.stg"));

    if(!saveFile.open(QIODevice::WriteOnly)) return false;

    QJsonDocument saveDoc(m_palette->toJson());

    saveFile.write(saveDoc.toBinaryData());

    return true;
}

Palette *Settings::palette()
{
    return m_palette;
}
