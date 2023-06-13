#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class BoyerMoore : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    BoyerMoore(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    std::vector<int> computeBadCharacterTable(const QString& pattern);
    std::vector<int> computeGoodSuffixTable(const QString& pattern);
};


#endif // BOYERMOORE_H
