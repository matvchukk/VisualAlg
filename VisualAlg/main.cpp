#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "SortingAlg/Sorts/complexityvisitor.h"
#include "Tests\doctest.h"

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"
#include "SortingAlg\Sorts\selectionSort.h"
#include "SortingAlg\Sorts\quickSort.h"
#include "SortingAlg\Sorts\listofsteps.h"
#include "SortingAlg\Sorts\sort.h"
#include "SortingAlg\Sorts\timingsortdecorator.h"

#include "PatternsSearching/RabinKarp.h"
#include "PatternsSearching/BoyerMoore.h"
#include "PatternsSearching/FiniteAutomata.h"
#include "PatternsSearching/PatternSearchContext.h"
#include "PatternsSearching/KnuthMorrisPratt.h"
#include "PatternsSearching/BoyerMooreHorspool.h"
#include "PatternsSearching/Smith.h"
#include "PatternsSearching/GallagherSyedGallagher.h"




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

    ComplexityVisitor *complexity = new ComplexityVisitor();
    engine.rootContext()->setContextProperty("complexity", complexity );
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
    PatternSearchContext* context = new PatternSearchContext(nullptr);

    RabinKarp* rabinKarp = new RabinKarp(nullptr);
    engine.rootContext()->setContextProperty("rabinKarp", rabinKarp);

    BoyerMoore* boyerMoore = new BoyerMoore(nullptr);
    engine.rootContext()->setContextProperty("boyerMoore", boyerMoore);

    FiniteAutomata* finiteAutomata = new FiniteAutomata(nullptr);
    engine.rootContext()->setContextProperty("finiteAutomata", finiteAutomata);

    KnuthMorrisPratt* knuthMorrisPratt = new KnuthMorrisPratt(nullptr);
    engine.rootContext()->setContextProperty("knuthMorrisPratt", knuthMorrisPratt);

    BoyerMooreHorspool* boyerMooreHorspool = new BoyerMooreHorspool(nullptr);
    engine.rootContext()->setContextProperty("boyerMooreHorspool", boyerMooreHorspool);

    Smith* smith = new Smith(nullptr);
    engine.rootContext()->setContextProperty("smith", smith);

    GallagherSyedGallagher* gallagherSyedGallagher = new GallagherSyedGallagher(nullptr);
    engine.rootContext()->setContextProperty("gallagherSyedGallagher", gallagherSyedGallagher);

    context->setStrategy(rabinKarp);
    engine.rootContext()->setContextProperty("context", context);



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
