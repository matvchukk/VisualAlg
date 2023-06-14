#include "TimedPatternSearchStrategy.h"
/// Searches for the pattern in the given text using the Smith algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void TimedPatternSearchStrategy::search(const QString& text, const QString& pattern)
{
    if (searchStrategy)
    {
        QObject::disconnect(searchStrategy, &PatternSearchStrategy::searchCompleted, this, &TimedPatternSearchStrategy::searchCompleted);
        QObject::disconnect(searchStrategy, &PatternSearchStrategy::getElapsedTime, this, &TimedPatternSearchStrategy::getElapsedTime);
    }

    QDateTime start = QDateTime::currentDateTime();
    searchStrategy->search(text, pattern);
    QObject::connect(searchStrategy, &PatternSearchStrategy::searchCompleted, this, &TimedPatternSearchStrategy::searchCompleted);
    QDateTime end = QDateTime::currentDateTime();
    qint64 elapsedTime = start.msecsTo(end);
    QObject::connect(searchStrategy, &PatternSearchStrategy::getElapsedTime, this, &TimedPatternSearchStrategy::getElapsedTime);

    emit getElapsedTime(elapsedTime);
}
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& TimedPatternSearchStrategy::getSearchPositions()
{
    return searchStrategy->getSearchPositions();
}
