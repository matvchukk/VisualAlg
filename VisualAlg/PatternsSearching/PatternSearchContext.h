#ifndef PATTERNSEARCHCONTEXT_H
#define PATTERNSEARCHCONTEXT_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
///The PatternSearchContext class representing the pattern search context.
/// Used to perform a pattern search in the text using the selected strategy.
/// It allows you to change the search strategy and execute the search using the selected strategy.
/// After the search is complete, sends the `searchStarted()` and `searchCompleted()` signals to notify the start and end of the search.
class PatternSearchContext : public QObject
{
    Q_OBJECT

private:
    PatternSearchStrategy* searchStrategy;

public:
    PatternSearchContext(QObject* parent = nullptr) : QObject(parent), searchStrategy(nullptr)  {
    }
    /// Sets the strategy for pattern search
    /// @param newSetStrategy The new pattern search strategy to set
    Q_INVOKABLE void setStrategy(PatternSearchStrategy* newSetStrategy)
    {
        if (searchStrategy)
        {
            QObject::disconnect(searchStrategy, &PatternSearchStrategy::searchCompleted, this, &PatternSearchContext::searchCompleted);
        }
        searchStrategy = newSetStrategy;
        QObject::connect(searchStrategy, &PatternSearchStrategy::searchCompleted, this, &PatternSearchContext::searchCompleted);
    }
    /// Executes the pattern search strategy
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void executeStrategy(const QString& text, const QString& pattern)
    {
        if (searchStrategy)
        {
            searchStrategy->search(text, pattern);
        }
    }

signals:
    void searchStarted();
    void searchCompleted(const std::vector<int>& positions);
};

#endif // PATTERNSEARCHCONTEXT_H
