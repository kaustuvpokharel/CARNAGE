#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "PacketSniffer.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Sniffer::PacketSniffer sniffer;

    const QUrl url(QStringLiteral("qrc:/CARNAGE/Main/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
