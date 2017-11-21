#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QQmlContext"
#include "appobject.h"
#include "colormodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    AppObject object(QUrl::fromLocalFile("C:/saome-file.xml"));
    qmlRegisterUncreatableType<ColorModel>("com.ics.demo", 1, 0, "ColorModel", "Uncreatable!");
    engine.rootContext()->setContextObject(&object);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}


