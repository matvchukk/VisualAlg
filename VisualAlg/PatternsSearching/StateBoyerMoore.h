#ifndef STATEBOYERMOORE_H
#define STATEBOYERMOORE_H

#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class StateBoyerMoore : public PatternSearchStrategy
{

public:
    StateBoyerMoore(QObject *parent) : PatternSearchStrategy(parent){}
    /// Searches for the pattern in the given text using the Boyer-Moore-Horspool algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    std::vector<int> searchPositions;
    /// Sets the algorithm based on the given text and pattern
    /// @param text The text to search in
    /// @param pattern The pattern to search for.
    void setAlgorithm(const QString& text, const QString& pattern);
};


#endif // STATEBOYERMOORE_H
