#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controllers/master-controller.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterType<cm::controllers::NavigationController>("CM", 1, 0, "NavigationControlle");
    cm::controllers::MasterController masterController;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("masterController", &masterController);
    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));
    engine.load(url);

    return app.exec();
}
