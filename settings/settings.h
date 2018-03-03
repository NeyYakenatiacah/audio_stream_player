#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <settings/palette.h>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Palette * palette READ palette NOTIFY paletteChanged)

public:
    explicit Settings(QObject *parent = nullptr);
    virtual ~Settings();

    Q_INVOKABLE void defaultSettings();

    Palette * palette();

signals:
    void paletteChanged();

private:

    bool load();
    bool save();

    Palette * m_palette;

    QStringList m_playlists;
};

#endif // SETTINGS_H
