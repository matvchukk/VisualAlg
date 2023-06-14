#include "BoyerMooreHorspool.h"
/// Searches for the pattern in the given text using the Boyer-Moore-Horspool algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void BoyerMooreHorspool::search(const QString& text, const QString& pattern)
{
    int n = text.length();
    int m = pattern.length();

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
            i += 1;
        }
        else
        {
            int shift = badCharacter[text[i + m - 1].unicode()];
            i += shift != 0 ? shift : 1;
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}
/// Computes the bad character table for the pattern
/// @param pattern The pattern for which to compute the table
/// @returns The computed bad character table
std::vector<int> BoyerMooreHorspool::computeBadCharacterTable(const QString& pattern)
{
    std::vector<int> badCharacter(256, pattern.length());

    for (int i = 0; i < pattern.length() - 1; i++)
    {
        int c = pattern[i].unicode();
        badCharacter[c] = pattern.length() - 1 - i;
    }

    return badCharacter;
}
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& BoyerMooreHorspool::getSearchPositions() {
    return  searchPositions;
}
