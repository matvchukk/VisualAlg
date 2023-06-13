#ifndef FINITEAUTOMATA_H
#define FINITEAUTOMATA_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class FiniteAutomata : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    FiniteAutomata(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    int getNextState(const QString& pattern, int M, int state, int x);
};

#endif // FINITEAUTOMATA_H

