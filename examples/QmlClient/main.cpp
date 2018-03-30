#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "XmppCore/XmppModule.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtXmpp::initialize();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
