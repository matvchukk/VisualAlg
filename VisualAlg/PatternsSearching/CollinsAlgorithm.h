#ifndef COLLINSALGORITHM_H
#define COLLINSALGORITHM_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class CollinsAlgorithm : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    CollinsAlgorithm(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    std::vector<int> computeJumpTable(const QString& pattern);
    int computeSuffixLength(const QString& pattern, int p);
    bool isPrefix(const QString& pattern, int p);
};

#endif // COLLINSALGORITHM_H
