#ifndef COLLINSALGORITHM_H
#define COLLINSALGORITHM_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The CollinsAlgorithm class implements the Collins pattern search algorithm.
class CollinsAlgorithm : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    CollinsAlgorithm(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Collins algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Computes the jump table for the pattern
    /// @param pattern The pattern for which to compute the jump table
    /// @returns The computed jump table
    std::vector<int> computeJumpTable(const QString& pattern);
    /// Computes the length of the suffix of the pattern at position p
    /// @param pattern The pattern for which to compute the suffix length
    /// @param p The position of the suffix
    /// @returns The length of the suffix
    int computeSuffixLength(const QString& pattern, int p);
    /// Checks if a string is a prefix of the pattern
    /// @param pattern The pattern to check against
    /// @param p The position to start the comparison
    /// @returns True if the string is a prefix, false otherwise
    bool isPrefix(const QString& pattern, int p);
};

#endif // COLLINSALGORITHM_H
