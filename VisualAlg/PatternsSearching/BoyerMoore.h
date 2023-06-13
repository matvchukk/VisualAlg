#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class BoyerMoore : public PatternSearchStrategy
{
    Q_OBJECT
public:
    BoyerMoore(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;

private:
    std::vector<int> computeBadCharacterTable(const QString& pattern);
    std::vector<int> computeGoodSuffixTable(const QString& pattern);
};


#endif // BOYERMOORE_H
