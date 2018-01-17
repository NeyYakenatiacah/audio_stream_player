#include "settings.h"

#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStyle>

QJsonObject & toJson (const QColor & color)
{
    QJsonObject obj;

    obj["red"]   = color.red();
    obj["green"] = color.green();
    obj["blue"]  = color.blue();

    return obj;
}

QJsonObject & toJson (const QPalette & palette)
{
    QJsonObject obj;

    obj["Window"]        = toJson(palette.color(QPalette::Window));
    obj["Background"]    = toJson(palette.color(QPalette::Background));
    obj["WindowText"]    = toJson(palette.color(QPalette::WindowText));
    obj["Foreground"]    = toJson(palette.color(QPalette::Foreground));
    obj["Base"]          = toJson(palette.color(QPalette::Base));
    obj["AlternateBase"] = toJson(palette.color(QPalette::AlternateBase));
    obj["ToolTipBase"]   = toJson(palette.color(QPalette::ToolTipBase));
    obj["ToolTipText"]   = toJson(palette.color(QPalette::ToolTipText));
    obj["Text"]          = toJson(palette.color(QPalette::Text));
    obj["Button"]        = toJson(palette.color(QPalette::Button));
    obj["ButtonText"]    = toJson(palette.color(QPalette::ButtonText));
    obj["BrightText"]    = toJson(palette.color(QPalette::BrightText));

    return obj;
}

QColor & colorFromJson(const QJsonObject & obj)
{
    return QColor();
}

QPalette & fromJson(const QJsonObject & obj)
{
    return QPalette();
}

Settings::Settings(QObject *parent) : QObject(parent)
{
    if(!load()) defaultSettings();
}

Settings::~Settings()
{
    save();
}

void Settings::defaultSettings()
{
    setPalette(QApplication::style()->standardPalette());
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
        setPalette(fromJson(obj));
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

    QJsonDocument saveDoc(toJson(m_palette));

    saveFile.write(saveDoc.toBinaryData());

    return true;
}

QPalette Settings::palette() const
{
    return m_palette;
}

void Settings::setPalette(const QPalette &palette)
{
    m_palette = palette;

    emit paletteChanged();
}
