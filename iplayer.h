#ifndef IPLAYER_H
#define IPLAYER_H

#include <QObject>
#include <QMediaPlayer>

class IPlayer : public QObject
{
    Q_OBJECT

public:
    explicit IPlayer(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~IPlayer(){}

    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;

    virtual void setVolume(int) = 0;
    virtual void setMuted(bool) = 0;
    virtual void setSource(QString) = 0; //may be: + overloaded for playlist
    //setPlaylist?

    enum State
    {
        Stopped = 0,
        Playing = 1,
        Paused  = 2,
        Muted   = 4
    };


signals:
    void mediaChanged(QString); //param - ???
    void stateChanged(IPlayer::State);
    void volumeChanged(int);

};

#endif // IPLAYER_H
