#ifndef KNUTHMORRISPRATT_H
#define KNUTHMORRISPRATT_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The KnuthMorrisPratt class implements the Knuth-Morris-Pratt pattern search algorithm.
class KnuthMorrisPratt : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    KnuthMorrisPratt(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Knuth-Morris-Pratt algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Computes the Longest Proper Prefix which is also a Suffix (LPS) array for the pattern
    /// @param pattern The pattern to search for
    /// @returns The computed LPS array
    std::vector<int> computeLPSArray(const QString& pattern);
};

#endif // KNUTHMORRISPRATT_H
