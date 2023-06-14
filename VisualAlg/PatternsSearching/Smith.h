#ifndef SMITH_H
#define SMITH_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The Smith class implements the Smith pattern search algorithm.
class Smith : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    Smith(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Smith algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Computes the prefix function for the pattern
    /// @param pattern The pattern to compute the prefix function for
    /// @returns The computed prefix function
    std::vector<int> computePrefixFunction(const QString& pattern);
};

#endif // SMITH_H
