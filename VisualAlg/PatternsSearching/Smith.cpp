#include "Smith.h"
/// Searches for the pattern in the given text using the Smith algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void Smith::search(const QString& text, const QString& pattern)
{
    int n = text.length();
    int m = pattern.length();

    std::vector<int> prefixFunction = computePrefixFunction(pattern);

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
            int shift = j - prefixFunction[j];
            i += shift > 0 ? shift : 1;
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}
/// Computes the prefix function for the pattern
/// @param pattern The pattern to compute the prefix function for
/// @returns The computed prefix function
std::vector<int> Smith::computePrefixFunction(const QString& pattern)
{
    int m = pattern.length();

    std::vector<int> prefixFunction(m, 0);

    int k = 0;
    for (int q = 1; q < m; q++)
    {
        while (k > 0 && pattern[k] != pattern[q])
            k = prefixFunction[k - 1];

        if (pattern[k] == pattern[q])
            k++;

        prefixFunction[q] = k;
    }

    return prefixFunction;
}
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& Smith::getSearchPositions() {
    return  searchPositions;
}
