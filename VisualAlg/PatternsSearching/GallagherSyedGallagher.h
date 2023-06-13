#ifndef GALLAGHERSYEDGALLAGHER_H
#define GALLAGHERSYEDGALLAGHER_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class GallagherSyedGallagher : public PatternSearchStrategy
{
    Q_OBJECT
public:
    GallagherSyedGallagher(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;

private:
    std::vector<int> computeGoodSuffixTable(const QString& pattern);
    std::vector<int> computeBadCharacterTable(const QString& pattern);
};

#endif // GALLAGHERSYEDGALLAGHER_H
