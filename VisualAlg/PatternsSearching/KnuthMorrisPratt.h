#ifndef KNUTHMORRISPRATT_H
#define KNUTHMORRISPRATT_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class KnuthMorrisPratt : public PatternSearchStrategy
{
    Q_OBJECT
public:
    KnuthMorrisPratt(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;

private:
    std::vector<int> computeLPSArray(const QString& pattern);
};

#endif // KNUTHMORRISPRATT_H
