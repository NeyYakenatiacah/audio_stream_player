#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

#include "source.h"

class Settings : public QObject
{
    Q_OBJECT

public:

    explicit Settings(QObject *parent = nullptr);
    virtual ~Settings();

    bool loadSettings();
    bool saveSettings() const;

    //Q_INVOKABLE Source selectSource(int idx) const;
    //Q_INVOKABLE void setSource(int idx);

    void addSource(const Source & src);
    void addSource(QString name, QString stream, QString tag);

signals:
    void sourceChanged();

public slots:

private:
    void defaultSettings();


    bool m_autoPlay;

    QList<Source> m_srcList;
};

#endif // SETTINGS_H
