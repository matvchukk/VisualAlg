#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

//#include "Tests\doctest.h"

#include "SortingAlg\List\list.h"
#include "SortingAlg\Sorts\bubbleSort.h"
#include "SortingAlg\Sorts\selectionSort.h"
#include "SortingAlg\Sorts\quickSort.h"
#include "SortingAlg\Sorts\listofsteps.h"
#include "SortingAlg\Sorts\sort.h"


#include "PatternsSearching\PatternSearchContext.h"
#include "PatternsSearching\RabinKarp.h"
#include "PatternsSearching\BoyerMoore.h"
#include "PatternsSearching\FiniteAutomata.h"
#include "PatternsSearching\KnuthMorrisPratt.h"
#include "PatternsSearching\BoyerMooreHorspool.h"
#include "PatternsSearching\Smith.h"
#include "PatternsSearching\GallagherSyedGallagher.h"
#include "PatternsSearching\CollinsAlgorithm.h"
#include "PatternsSearching\StateBoyerMoore.h"


//namespace lab {
//int doctestRun(int argc, char *argv[]){
//    doctest::Context context(argc, argv);
//        int result = context.run();
//        return result;//
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

    CollinsAlgorithm* collinsAlgorithm = new CollinsAlgorithm(nullptr);
    engine.rootContext()->setContextProperty("collinsAlgorithm", collinsAlgorithm);

    StateBoyerMoore* stateBoyerMoore = new StateBoyerMoore(nullptr);
    engine.rootContext()->setContextProperty("stateBoyerMoore", stateBoyerMoore);

    context->setStrategy(boyerMoore);
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
