#ifndef TIMEDPATTERNSEARCHSTRATEGY_H
#define TIMEDPATTERNSEARCHSTRATEGY_H

#include <QObject>
#include <QDateTime>
#include "PatternSearchStrategy.h"

/// The TimedPatternSearchStrategy class is a decorator that measures the execution time of the underlying pattern search strategy.
class TimedPatternSearchStrategy : public PatternSearchStrategy
{
    Q_OBJECT

private:
    PatternSearchStrategy* searchStrategy;

public:
    TimedPatternSearchStrategy(PatternSearchStrategy* strategy, QObject* parent = nullptr);
    /// Searches for the pattern in the given text using the Smith algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;
};

#endif // TIMEDPATTERNSEARCHSTRATEGY_H
