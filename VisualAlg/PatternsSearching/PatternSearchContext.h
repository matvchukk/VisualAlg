#ifndef PATTERNSEARCHCONTEXT_H
#define PATTERNSEARCHCONTEXT_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class PatternSearchContext : public QObject
{
    Q_OBJECT

private:
    PatternSearchStrategy* searchStrategy;

public:
    PatternSearchContext(QObject* parent = nullptr) : QObject(parent), searchStrategy(nullptr)  {
    }

    Q_INVOKABLE void setStrategy(PatternSearchStrategy* newSetStrategy)
    {
        if (searchStrategy)
        {
            QObject::disconnect(searchStrategy, &PatternSearchStrategy::searchCompleted, this, &PatternSearchContext::searchCompleted);
        }
        searchStrategy = newSetStrategy;
        QObject::connect(searchStrategy, &PatternSearchStrategy::searchCompleted, this, &PatternSearchContext::searchCompleted);
    }

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
