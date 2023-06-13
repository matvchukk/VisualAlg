#include "Smith.h"

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

std::vector<int>& Smith::getSearchPositions() {
    return  searchPositions;
}
