#ifndef BOYERMOOREHORSPOOL_H
#define BOYERMOOREHORSPOOL_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class BoyerMooreHorspool : public PatternSearchStrategy
{
    Q_OBJECT
public:
    BoyerMooreHorspool(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;

private:
    std::vector<int> computeBadCharacterTable(const QString& pattern);
};

#endif // BOYERMOOREHORSPOOL_H
