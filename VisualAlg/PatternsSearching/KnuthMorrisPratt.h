#ifndef KNUTHMORRISPRATT_H
#define KNUTHMORRISPRATT_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class KnuthMorrisPratt : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    KnuthMorrisPratt(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    std::vector<int> computeLPSArray(const QString& pattern);
};

#endif // KNUTHMORRISPRATT_H
