﻿#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>

#include "media_controller.h"
#include "media_list_manager.h"
#include "settings.h"
#include "Containers/media_list.h"
#include "Containers/media_source.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("audio_stream_player");
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);

    QGuiApplication app(argc, argv);
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    VlcCommon::setPluginPath(QCoreApplication::applicationDirPath() + "/plugins");

    VlcInstance instance(VlcCommon::args());

    MediaController controller(&instance);
    MediaListManager pl_manager(&instance);
    Settings settings;

////! Init type system
    qmlRegisterUncreatableType<MediaList>   ("asp.MediaList",   1, 0, "MediaList",   "This type requires initialization");
    qmlRegisterUncreatableType<MediaSource> ("asp.MediaSource", 1, 0, "MediaSource", "This type requires initialization");
////!

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("controller",    &controller);
    engine.rootContext()->setContextProperty("media_manager", &pl_manager);
    engine.rootContext()->setContextProperty("settings",      &settings  );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
