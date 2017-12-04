#ifndef STREAMPLAYER_H
#define STREAMPLAYER_H

#include <QObject>

class StreamPlayer : public QObject
{
    Q_OBJECT
public:
    explicit StreamPlayer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // STREAMPLAYER_H