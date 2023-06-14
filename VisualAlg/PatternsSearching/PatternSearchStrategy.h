#ifndef PATTERNSEARCHSTRATEGY_H
#define PATTERNSEARCHSTRATEGY_H

#include <QObject>
#include <QString>
#include <vector>
///The PatternSearchStrategy class defines a common interface for all pattern search strategies.
class PatternSearchStrategy : public QObject
{
    Q_OBJECT
private:
    std::vector<int> positions;
    int elapsedTime;
public:
    PatternSearchStrategy(QObject *parent = nullptr) : QObject(parent) {}
    /// Performs a pattern search in the given text using the specified pattern search strategy.
    /// @param text The text to search in.
    /// @param pattern The pattern to search for.
    virtual void search(const QString& text, const QString& pattern) = 0;
    /// Returns the positions where the pattern was found in the text.
    /// @returns A vector containing the positions where the pattern was found.
    virtual std::vector<int>& getSearchPositions() = 0;

signals:
    /// Signal emitted when the search operation is completed.
    /// @param positions A vector containing the positions where the pattern was found.
    void searchCompleted(const std::vector<int>& positions);
    /// Signal emitted when the elapsed time is available.
    /// @param elapsedTime The elapsed time in milliseconds.
    void getElapsedTime(int elapsedTime);
};

#endif // PATTERNSEARCHSTRATEGY_H
