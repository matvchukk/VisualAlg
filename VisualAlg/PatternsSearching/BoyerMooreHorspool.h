#ifndef BOYERMOOREHORSPOOL_H
#define BOYERMOOREHORSPOOL_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The BoyerMooreHorspool class implements the Boyer-Moore-Horspool pattern search algorithm.
class BoyerMooreHorspool : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    BoyerMooreHorspool(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Boyer-Moore-Horspool algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Computes the bad character table for the pattern
    /// @param pattern The pattern for which to compute the table
    /// @returns The computed bad character table
    std::vector<int> computeBadCharacterTable(const QString& pattern);
};

#endif // BOYERMOOREHORSPOOL_H
