#ifndef GALLAGHERSYEDGALLAGHER_H
#define GALLAGHERSYEDGALLAGHER_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The GallagherSyedGallagher class implements the Gallagher-Syed-Gallagher pattern search algorithm.
class GallagherSyedGallagher : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    GallagherSyedGallagher(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Gallagher-Syed-Gallagher algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Computes the good suffix table for the pattern
    /// @param pattern The pattern to search for
    /// @returns The computed good suffix table
    std::vector<int> computeGoodSuffixTable(const QString& pattern);
    /// Computes the bad character table for the pattern
    /// @param pattern The pattern to search for
    /// @returns The computed bad character table
    std::vector<int> computeBadCharacterTable(const QString& pattern);
};

#endif // GALLAGHERSYEDGALLAGHER_H
