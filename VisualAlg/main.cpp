#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    // For sorting algorithm
    List array;
    engine.rootContext()->setContextProperty("array", &array);

    Sort* bubbleSort= new BubbleSort(&array);
    engine.rootContext()->setContextProperty("bubbleSort", bubbleSort);

    Sort* selectionSort= new SelectionSort(&array);
    engine.rootContext()->setContextProperty("selectionSort", selectionSort);

    ListOfSteps listofsteps(bubbleSort);
    engine.rootContext()->setContextProperty("listofsteps", &listofsteps);

    ListOfSteps listofstepsS(selectionSort);
    engine.rootContext()->setContextProperty("listofstepsS", &listofstepsS);


   //
    RabinKarp rabinKarp;
    engine.rootContext()->setContextProperty("rabinKarp", &rabinKarp);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}


