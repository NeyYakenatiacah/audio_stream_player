#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QPalette>

class Settings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QPalette palette READ palette WRITE setPalette NOTIFY paletteChanged)

public:
    explicit Settings(QObject *parent = nullptr);
    virtual ~Settings();

    Q_INVOKABLE void defaultSettings();



    QPalette palette() const;
    void setPalette(const QPalette &palette);

signals:
    void paletteChanged();

private:

    bool load();
    bool save();

    QPalette m_palette;

    QStringList m_playlists;
};

#endif // SETTINGS_H
