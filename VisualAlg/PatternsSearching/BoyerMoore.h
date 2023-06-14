#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The BoyerMoore class implements the Boyer-Moore pattern search algorithm.
class BoyerMoore : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    BoyerMoore(QObject *parent) : PatternSearchStrategy(parent) {}

    /// Searches for the pattern in the given text using the Boyer-Moore algorithm.
    /// @param text The text to search in.
    /// @param pattern The pattern to search for.
    /// @returns The positions where the pattern is found.
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;

    /// Returns the positions where the pattern is found in the text.
    /// @returns The positions where the pattern is found.
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;


private:
    /// Computes the bad character table for the Boyer-Moore algorithm.
    /// @param pattern The pattern to compute the table for.
    /// @returns The bad character table.
    std::vector<int> computeBadCharacterTable(const QString& pattern);
    /// Computes the good suffix table for the Boyer-Moore algorithm.
    /// @param pattern The pattern to compute the table for.
    /// @returns The good suffix table.
    std::vector<int> computeGoodSuffixTable(const QString& pattern);

};


#endif // BOYERMOORE_H
