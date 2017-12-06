#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <VLCQtCore/Common.h>

#include "media_controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("VLC-Qt Stream Player");
    QCoreApplication::setAttribute(Qt::AA_X11InitThreads);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    VlcCommon::setPluginPath(app.applicationDirPath() + "/plugins");

    qmlRegisterType<MediaController>("asp.MediaController", 0, 2, "MediaController");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
