#include "settings.h"

#include <QApplication>
#include <QStyle>

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
    return false;
}

bool Settings::save()
{
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
