#include "StateBoyerMoore.h"
#include "BoyerMoore.h"
#include "BoyerMooreHorspool.h"

BoyerMoore* bmAlgorithm = new BoyerMoore(nullptr);
BoyerMooreHorspool* bmhAlgorithm = new BoyerMooreHorspool(nullptr);
/// Sets the algorithm based on the given text and pattern
/// @param text The text to search in
/// @param pattern The pattern to search for.
void StateBoyerMoore::setAlgorithm(const QString& text, const QString& pattern){

    int n = text.length();
    int m = pattern.length();


    if (m < 2 * n / 3){
        bmAlgorithm->search(text, pattern);
        emit searchCompleted(bmAlgorithm->getSearchPositions());
    }
    else {
        bmhAlgorithm->search(text, pattern);
    }
}

/// Searches for the pattern in the given text using the Boyer-Moore-Horspool algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void StateBoyerMoore::search(const QString& text, const QString& pattern)
{
    setAlgorithm(text, pattern);
    //this->executeStrategy(text, pattern);
}

/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& StateBoyerMoore::getSearchPositions() {
    return  searchPositions;
}

