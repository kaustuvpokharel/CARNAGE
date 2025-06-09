#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "AppController.h"
#include "Logger.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AppController controller;
    qmlRegisterSingletonInstance("CARNAGE", 1, 0, "AppController", &controller);

    Core::Logger::instance().setLogFile("logs/app.log");
    Core::Logger::instance().enableConsoleOutput(true);

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
