#ifndef BOYERMOOREHORSPOOL_H
#define BOYERMOOREHORSPOOL_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class BoyerMooreHorspool : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    BoyerMooreHorspool(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    std::vector<int> computeBadCharacterTable(const QString& pattern);
};

#endif // BOYERMOOREHORSPOOL_H
