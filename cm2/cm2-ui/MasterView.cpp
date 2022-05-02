#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "master-controller.h"
#include "commandcontroller.h"

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    qmlRegisterType<cm2::controllers::MasterController>("CM2", 1, 0, "MasterController");
    qmlRegisterType<cm2::controllers::NavigationController>("CM2", 1, 0, "NavigationController");
    qmlRegisterType<cm2::controllers::CommandController>("CM2", 1, 0, "CommandController");
    qmlRegisterType<cm2::framework::Command>("CM2", 1, 0, "Command");

    cm2::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("masterController", &masterController);
    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
