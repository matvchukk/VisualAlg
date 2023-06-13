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


#include "PatternsSearching/RabinKarp.h"
#include "PatternsSearching/BoyerMoore.h"
#include "PatternsSearching/FiniteAutomata.h"
#include "PatternsSearching/PatternSearchContext.h"

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

    Sort* bubbleSort= new BubbleSort(&array);
    engine.rootContext()->setContextProperty("bubbleSort", bubbleSort);

    Sort* selectionSort= new SelectionSort(&array);
    engine.rootContext()->setContextProperty("selectionSort", selectionSort);

    Sort* quickSort= new QuickSort(&array);
    engine.rootContext()->setContextProperty("quickSort", quickSort);

    ListOfSteps listofstepsB(bubbleSort);
    engine.rootContext()->setContextProperty("listofstepsB", &listofstepsB);

    ListOfSteps listofstepsS(selectionSort);
    engine.rootContext()->setContextProperty("listofstepsS", &listofstepsS);

    ListOfSteps listofstepsQ(quickSort);
    engine.rootContext()->setContextProperty("listofstepsQ", &listofstepsQ);


   //
    PatternSearchContext* context = new PatternSearchContext(nullptr);
    RabinKarp* rabinKarp = new RabinKarp(nullptr);
    BoyerMoore* boyerMoore = new BoyerMoore(nullptr);
    FiniteAutomata* finiteAutomata = new FiniteAutomata(nullptr);
    context->setStrategy(rabinKarp);
    engine.rootContext()->setContextProperty("context", context);
    engine.rootContext()->setContextProperty("rabinKarp", rabinKarp);
    engine.rootContext()->setContextProperty("boyerMoore", boyerMoore);
    engine.rootContext()->setContextProperty("finiteAutomata", finiteAutomata);


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
