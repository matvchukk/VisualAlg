#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Tests/doctest.h"
#include "PatternsSearching\PatternSearchContext.h"
#include "PatternsSearching\PatternSearchStrategy.h"
#include "PatternsSearching\RabinKarp.h"
#include "PatternsSearching\BoyerMoore.h"
#include "PatternsSearching\FiniteAutomata.h"
#include "PatternsSearching\KnuthMorrisPratt.h"
#include "PatternsSearching\BoyerMooreHorspool.h"
#include "PatternsSearching\Smith.h"
#include "PatternsSearching\GallagherSyedGallagher.h"
#include "PatternsSearching\CollinsAlgorithm.h"
#include <QDebug>

#include <vector>

PatternSearchContext* context = new PatternSearchContext(nullptr);
BoyerMoore* bmAlgoAlgorithm = new BoyerMoore(nullptr);
RabinKarp* rkAlgorithm = new RabinKarp(nullptr);
FiniteAutomata* faAlgorithm = new FiniteAutomata(nullptr);
KnuthMorrisPratt* kmpAlgorithm = new KnuthMorrisPratt(nullptr);
BoyerMooreHorspool* bmhAlgorithm = new BoyerMooreHorspool(nullptr);
Smith* smAlgorithm = new Smith(nullptr);
GallagherSyedGallagher* gsgAlgorithm = new GallagherSyedGallagher(nullptr);
CollinsAlgorithm* colAlgorithm = new CollinsAlgorithm(nullptr);
//PatternSearchStrategy* strategy = bmAlgoAlgorithm;
TEST_CASE("Boyer-Moore pattern search") {

    context->setStrategy(bmAlgoAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "algorithm";
        QString pattern = "algo";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "algorithm";
        QString pattern = "rithm";
        std::vector<int> expected = {4};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "algorithm";
        QString pattern = "ith";
        std::vector<int> expected = {5};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }


    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "algorithm";
        QString pattern = "xyz";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }
}

TEST_CASE("Rabin-Karp pattern search") {

    context->setStrategy(rkAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "charming";
        QString pattern = "charm";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "charming";
        QString pattern = "ming";
        std::vector<int> expected = {4};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "charming";
        QString pattern = "arm";
        std::vector<int> expected = {2};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "charming";
        QString pattern = "amr";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }
}

TEST_CASE("Finite Automata pattern search") {

    context->setStrategy(faAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "example";
        QString pattern = "exam";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "example";
        QString pattern = "ple";
        std::vector<int> expected = {4};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "example";
        QString pattern = "amp";
        std::vector<int> expected = {2};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "example";
        QString pattern = "xyz";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());
        CHECK(positions == expected);
    }
}

TEST_CASE("Knuth-Morris-Pratt pattern search") {

    context->setStrategy(kmpAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "programming";
        QString pattern = "pro";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "programming";
        QString pattern = "ing";
        std::vector<int> expected = {8};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "programming";
        QString pattern = "mmi";
        std::vector<int> expected = {6};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "programming";
        QString pattern = "xyz";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }
}

TEST_CASE("Boyer-Moore-Horspool pattern search") {

    context->setStrategy(bmhAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "compelling";
        QString pattern = "com";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "compelling";
        QString pattern = "ling";
        std::vector<int> expected = {6};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "compelling";
        QString pattern = "pel";
        std::vector<int> expected = {3};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "compelling";
        QString pattern = "xyz";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());
        CHECK(positions == expected);
    }
}

TEST_CASE("Smith pattern search") {

    context->setStrategy(smAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "flawless";
        QString pattern = "flaw";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "flawless";
        QString pattern = "les";
        std::vector<int> expected = {4};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());
        //qDebug() << "Positions2:" << smAlgorithm->getSearchPositions();

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "flawless";
        QString pattern = "aw";
        std::vector<int> expected = {2};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "flawless";
        QString pattern = "xyz";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }
}
TEST_CASE("Gallager-Syed-Gallager pattern search") {

    context->setStrategy(gsgAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "ferocious";
        QString pattern = "fero";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "ferocious";
        QString pattern = "ious";
        std::vector<int> expected = {5};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "ferocious";
        QString pattern = "oci";
        std::vector<int> expected = {3};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "abracadabra";
        QString pattern = "abra";
        std::vector<int> expected = {0, 7};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "ferocious";
        QString pattern = "xyz";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());
        CHECK(positions == expected);
    }
}
TEST_CASE("Rabin-Karp pattern search") {
    context->setStrategy(colAlgorithm);

    SUBCASE("Pattern found at the beginning") {
        QString text = "irrepressible";
        QString pattern = "irrep";
        std::vector<int> expected = {0};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found at the end") {
        QString text = "irrepressible";
        QString pattern = "sible";
        std::vector<int> expected = {8};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found in the middle") {
        QString text = "irrepressible";
        QString pattern = "press";
        std::vector<int> expected = {4};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern found multiple times") {
        QString text = "irrepressible";
        QString pattern = "re";
        std::vector<int> expected = {2, 5};

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());

        CHECK(positions == expected);
    }

    SUBCASE("Pattern not found") {
        QString text = "irrepressible";
        QString pattern = "abc";
        std::vector<int> expected;

        std::vector<int> positions;
        context->executeStrategy(text, pattern);
        REQUIRE_NOTHROW(positions = context->getSearchPositions());
        CHECK(positions == expected);
    }
}





