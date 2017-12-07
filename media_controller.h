#ifndef MEDIA_CONTROLLER_H
#define MEDIA_CONTROLLER_H

#include <QObject>

class VlcEqualizer;
class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class MediaController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(float playbackRate READ playbackRate WRITE setPlaybackRate NOTIFY playbackRateChanged)

public:
    explicit MediaController(QObject *parent = nullptr);

    Q_INVOKABLE void play ();
    Q_INVOKABLE void pause ();
    Q_INVOKABLE void stop ();
    Q_INVOKABLE void resume ();

    Q_INVOKABLE void toForward();
    Q_INVOKABLE void toBackward();


    float playbackRate() const;
    void setPlaybackRate(float playbackRate);

    float postition() const;
    void setPostition(float postition);

    bool autoPlayMode() const;
    void setAutoPlayMode(bool autoPlayMode);

    VlcMedia *media() const;
    void setMedia(VlcMedia *media);

signals:

    //void mediaChanged (libvlc_media_t *media)
    void mediaChanged();
    void backward ();
    void forward  ();

    void buffering (float);
    void buffering (int);
    void opening ();

    void stopped ();
    void paused  ();
    void playing ();
    void end ();

    void positionChanged(float pos);
    void playbackRateChanged(float rate);

    void voutAvailable (int count);

    void stateChanged ();

    void error();

public slots:

private:

    bool m_autoPlayMode;

    VlcMediaPlayer * m_player;
    VlcInstance * m_instance;
};

#endif // MEDIA_CONTROLLER_H
