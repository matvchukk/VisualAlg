#include "GallagherSyedGallagher.h"
/// Searches for the pattern in the given text using the Gallagher-Syed-Gallagher algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void GallagherSyedGallagher::search(const QString& text, const QString& pattern)
{
    int n = text.length();
    int m = pattern.length();

    std::vector<int> goodSuffix = computeGoodSuffixTable(pattern);
    std::vector<int> badCharacter = computeBadCharacterTable(pattern);

    std::vector<int> positions;

    int i = 0;
    while (i <= n - m)
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[i + j])
            j--;

        if (j < 0)
        {
            positions.push_back(i);
            i += goodSuffix[0];
        }
        else
        {
            int shift1 = j - badCharacter[text[i + j].unicode()];
            int shift2 = goodSuffix[j + 1];
            i += std::max(shift1, shift2);
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}
/// Computes the good suffix table for the pattern
/// @param pattern The pattern to search for
/// @returns The computed good suffix table
std::vector<int> GallagherSyedGallagher::computeGoodSuffixTable(const QString& pattern)
{
    int m = pattern.length();

    std::vector<int> goodSuffix(m + 1, 0);
    std::vector<int> border(m + 1, 0);

    int i = m;
    int j = m + 1;
    border[i] = j;

    while (i > 0)
    {
        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {
            if (goodSuffix[j] == 0)
                goodSuffix[j] = j - i;
            j = border[j];
        }

        i--;
        j--;
        border[i] = j;
    }

    j = border[0];
    for (i = 0; i <= m; i++)
    {
        if (goodSuffix[i] == 0)
            goodSuffix[i] = j;
        if (i == j)
            j = border[j];
    }

    return goodSuffix;
}
/// Computes the bad character table for the pattern
/// @param pattern The pattern to search for
/// @returns The computed bad character table
std::vector<int> GallagherSyedGallagher::computeBadCharacterTable(const QString& pattern)
{
    std::vector<int> badCharacter(256, -1);

    for (int i = 0; i < pattern.length(); i++)
    {
        int c = pattern[i].unicode();
        badCharacter[c] = i;
    }

    return badCharacter;
}
// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& GallagherSyedGallagher::getSearchPositions() {
    return  searchPositions;
}
