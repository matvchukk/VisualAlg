#ifndef SMITH_H
#define SMITH_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class Smith : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    Smith(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    std::vector<int> computePrefixFunction(const QString& pattern);
};

#endif // SMITH_H
