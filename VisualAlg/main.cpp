#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Створюємо екземпляр List і реєструємо його в QML контексті
    List array;
     engine.rootContext()->setContextProperty("array", &array);



    // ManagerSortWrapper managerSortWrapper;
    // engine.rootContext()->setContextProperty("managerS", &managerSortWrapper);



     BubbleSort bubbleSort(&array);
    engine.rootContext()->setContextProperty("bubbleSort", &bubbleSort);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // Завантажуємо QML-файл
    engine.load(url);

    return app.exec();
}


