#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"
#include "SortingAlg\Sorts\quickSort.h"
#include "SortingAlg\Sorts\mergeSort.h"
#include "PatternsSearching\RabinKarp.h"
//#include "SortingAlg\Sorts\sort.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;


    // For sorting algorithm
    List array;
    engine.rootContext()->setContextProperty("array", &array);

    //   Sort* Sort;
      //  Sort = new MergeSort(&array);
                //  bubble->sort();

    BubbleSort bubbleSort(&array);
    engine.rootContext()->setContextProperty("bubbleSort", &bubbleSort);
    QuickSort quickSort(&array);
    engine.rootContext()->setContextProperty("quickSort", &quickSort);
    MergeSort mergeSort(&array);
    engine.rootContext()->setContextProperty("mergeSort", &mergeSort);
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


