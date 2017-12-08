#include "media_controller.h"

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Equalizer.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

MediaController::MediaController(QObject *parent) : QObject(parent)
{
    m_instance = new VlcInstance (VlcCommon::args(), this);
    m_player   = new VlcMediaPlayer (m_instance);

    connect(m_player, &VlcMediaPlayer::stopped,             this, &MediaController::stopped);
    connect(m_player, &VlcMediaPlayer::paused,              this, &MediaController::paused);
    connect(m_player, &VlcMediaPlayer::playing,             this, &MediaController::playing);
    connect(m_player, &VlcMediaPlayer::stopped,             this, &MediaController::stopped);

    connect(m_player, &VlcMediaPlayer::positionChanged,     this, &MediaController::positionChanged);
    //connect(m_player, &VlcMediaPlayer::playbackRateChanged, this, &MediaController::playbackRateChanged);

    connect(m_player, &VlcMediaPlayer::vout,                this, &MediaController::voutAvailable);
    connect(m_player, &VlcMediaPlayer::stateChanged,        this, &MediaController::stateChanged);
    connect(m_player, &VlcMediaPlayer::error,               this, &MediaController::error);

    connect(m_player, &VlcMediaPlayer::backward,            this, &MediaController::backward);
    connect(m_player, &VlcMediaPlayer::forward,             this, &MediaController::forward);
    connect(m_player, &VlcMediaPlayer::mediaChanged,        this, &MediaController::mediaChanged);
    connect(m_player, &VlcMediaPlayer::end,                 this, &MediaController::end);
}

void MediaController::play()
{
    m_player->play();
}

void MediaController::pause()
{
    m_player->pause();
}

void MediaController::stop()
{
    m_player->stop();
}

void MediaController::resume()
{
    m_player->resume();
}

void MediaController::toForward()
{
    emit forward();
}

void MediaController::toBackward()
{
    emit backward();
}

float MediaController::playbackRate() const
{
    return m_player->playbackRate();
}

void MediaController::setPlaybackRate(float playbackRate)
{
    m_player->setPlaybackRate(playbackRate);
    emit playbackRateChanged(playbackRate);
}

float MediaController::postition() const
{
    return m_player->position();
}

void MediaController::setPostition(float postition)
{
    m_player->setPosition(postition);
    
    emit positionChanged(m_player->position());
}

bool MediaController::autoPlayMode() const
{
    return m_autoPlayMode;
}

void MediaController::setAutoPlayMode(bool autoPlayMode)
{
    m_autoPlayMode = autoPlayMode;
}

VlcMedia *MediaController::media() const
{
    return m_player->currentMedia();
}

void MediaController::setMedia(VlcMedia *media)
{
    if(m_autoPlayMode)
    {
        m_player->open(media);
    }
    else
    {
        m_player->openOnly(media);
    }
}
