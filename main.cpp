#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <VLCQtCore/Common.h>

#include "media_controller.h"
#include "Containers/media_list.h"
#include "Containers/media_source.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QGuiApplication::setApplicationName("Vlc_qt stream player");
    QGuiApplication::setAttribute(Qt::AA_X11InitThreads);
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");

    qmlRegisterType<MediaController>("asp.MediaController", 0, 2, "MediaController");
    qmlRegisterUncreatableType<MediaList>("asp.MediaList", 1, 0, "MediaList", "This type requires initialization");
    //qmlRegisterType<MediaSource>("asp.MediaSource", 1, 0, "MediaSource");
    qmlRegisterUncreatableType<MediaSource>("asp.MediaSource", 1, 0, "MediaSource", "This type requires initialization");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
