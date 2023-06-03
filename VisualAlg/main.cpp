#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Tests\doctest.h"

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"
#include "SortingAlg\Sorts\selectionSort.h"
#include "SortingAlg\Sorts\quickSort.h"
#include "SortingAlg\Sorts\listofsteps.h"
#include "SortingAlg\Sorts\sort.h"
#include "SortingAlg\Sorts\timingsortdecorator.h"

#include "PatternsSearching\RabinKarp.h "


//namespace lab {
//int doctestRun(int argc, char *argv[]){
  //  doctest::Context context(argc, argv);
    //    int result = context.run();
      //  return result;//
//}
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    //doctestRun(argc, argv);

    // For sorting algorithm
    List array;
    engine.rootContext()->setContextProperty("array", &array);




   // timingBubbleSort->sort(); // Виклик сортування з вимірюванням часу

    Sort* bubbleSort= new BubbleSort(&array);
    Sort* timingBubbleSort = new TimingSortDecorator(bubbleSort);
    engine.rootContext()->setContextProperty("bubbleSort", bubbleSort);
    engine.rootContext()->setContextProperty("timingBubbleSort", timingBubbleSort);

    Sort* selectionSort= new SelectionSort(&array);
    engine.rootContext()->setContextProperty("selectionSort", selectionSort);
    Sort* timingSelectionSort = new TimingSortDecorator(selectionSort);
    engine.rootContext()->setContextProperty("timingSelectionSort", timingSelectionSort);

    Sort* quickSort= new QuickSort(&array);
    engine.rootContext()->setContextProperty("quickSort", quickSort);
    Sort* timingQuickSort = new TimingSortDecorator(quickSort);
    engine.rootContext()->setContextProperty("timingQuickSort", timingQuickSort);

    ListOfSteps listofstepsB(timingBubbleSort);
    engine.rootContext()->setContextProperty("listofstepsB", &listofstepsB);

    ListOfSteps listofstepsS(timingSelectionSort);
    engine.rootContext()->setContextProperty("listofstepsS", &listofstepsS);

    ListOfSteps listofstepsQ(timingQuickSort);
    engine.rootContext()->setContextProperty("listofstepsQ", &listofstepsQ);

    //

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

//}
