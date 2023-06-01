#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"
#include "SortingAlg\Sorts\quickSort.h"
#include "SortingAlg\Sorts\mergeSort.h"
#include "SortingAlg\Sorts\listofsteps.h"
#include "SortingAlg\Sorts\step.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    // For sorting algorithm
    List array;
    engine.rootContext()->setContextProperty("array", &array);
    BubbleSort bubbleSort(&array);
    engine.rootContext()->setContextProperty("bubbleSort", &bubbleSort);
    ListOfSteps listofsteps(&bubbleSort);
    engine.rootContext()->setContextProperty("listofsteps", &listofsteps);
    Step step;
    engine.rootContext()->setContextProperty("step", &step);
    QuickSort quickSort(&array);
    engine.rootContext()->setContextProperty("quickSort", &quickSort);
    MergeSort mergeSort(&array);
    engine.rootContext()->setContextProperty("mergeSort", &mergeSort);
   //


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}


