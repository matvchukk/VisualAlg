#include "KnuthMorrisPratt.h"
/// Searches for the pattern in the given text using the Knuth-Morris-Pratt algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void KnuthMorrisPratt::search(const QString& text, const QString& pattern)
{
    int M = pattern.size();
    int N = text.size();

    std::vector<int> lps = computeLPSArray(pattern);

    std::vector<int> positions;

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            ++j;
            ++i;
        }

        if (j == M)
        {
            positions.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                ++i;
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}
/// Computes the Longest Proper Prefix which is also a Suffix (LPS) array for the pattern
/// @param pattern The pattern to search for
/// @returns The computed LPS array
std::vector<int> KnuthMorrisPratt::computeLPSArray(const QString& pattern)
{
    int M = pattern.size();
    std::vector<int> lps(M, 0);

    int len = 0;
    int i = 1;
    while (i < M)
    {
        if (pattern[i] == pattern[len])
        {
            ++len;
            lps[i] = len;
            ++i;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                ++i;
            }
        }
    }

    return lps;
}
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& KnuthMorrisPratt::getSearchPositions() {
    return  searchPositions;
}
