#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <settings/palette.h>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Palette * palette READ palette NOTIFY paletteChanged)

public:
    enum SaveMode
    {
        Binary,
        Json
    };

    explicit Settings(QObject *parent = nullptr);
    virtual ~Settings();

    Q_INVOKABLE void defaultSettings();

    Palette * palette();

    SaveMode saveMode() const;

    QString playlistsPath() const;

signals:
    void paletteChanged();

private:

    bool load();
    bool save();

    Palette * m_palette;

    QStringList m_playlists;

    SaveMode m_saveMode;
};

#endif // SETTINGS_H
