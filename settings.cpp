#include "settings.h"

#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStyle>

#include <QDebug>

QJsonObject toJson (const QColor & color)
{
    QJsonObject obj;

    obj["red"]   = color.red();
    obj["green"] = color.green();
    obj["blue"]  = color.blue();
    obj["alpha"] = color.alpha();

    return obj;
}

QJsonObject toJson (const QPalette & palette)
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

QColor colorFromJson(const QJsonObject & obj)
{
    QColor color;

    if (obj.contains("red"))   color.setRed   (obj["red"].toInt());
    if (obj.contains("green")) color.setGreen (obj["green"].toInt());
    if (obj.contains("blue"))  color.setBlue  (obj["blue"].toInt());
    if (obj.contains("alpha")) color.setAlpha (obj["alpha"].toInt());

    return color;
}

QPalette fromJson(const QJsonObject & obj)
{
    if(!(obj.contains("Background") && obj.contains("Foreground"))) throw ("Bad palette");

    QPalette palette;

    if(obj.contains("Window"))      palette.setColor(QPalette::Window, colorFromJson(obj["Window"].toObject()));
    if(obj.contains("Background"))  palette.setColor(QPalette::Window, colorFromJson(obj["Background"].toObject()));
    if(obj.contains("WindowText"))  palette.setColor(QPalette::Window, colorFromJson(obj["WindowText"].toObject()));
    if(obj.contains("Foreground"))  palette.setColor(QPalette::Window, colorFromJson(obj["Foreground"].toObject()));
    if(obj.contains("Base"))        palette.setColor(QPalette::Window, colorFromJson(obj["Base"].toObject()));
    if(obj.contains("ToolTipBase")) palette.setColor(QPalette::Window, colorFromJson(obj["ToolTipBase"].toObject()));
    if(obj.contains("ToolTipText")) palette.setColor(QPalette::Window, colorFromJson(obj["ToolTipText"].toObject()));
    if(obj.contains("Text"))        palette.setColor(QPalette::Window, colorFromJson(obj["Text"].toObject()));
    if(obj.contains("Button"))      palette.setColor(QPalette::Window, colorFromJson(obj["Button"].toObject()));
    if(obj.contains("ButtonText"))  palette.setColor(QPalette::Window, colorFromJson(obj["ButtonText"].toObject()));
    if(obj.contains("BrightText"))  palette.setColor(QPalette::Window, colorFromJson(obj["BrightText"].toObject()));

    return palette;
}

Settings::Settings(QObject *parent) : QObject(parent)
{
    if(!load()) defaultSettings();
    qDebug() << "Settings";
}

Settings::~Settings()
{
    if (save())
    qDebug() << "~Settings";
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
