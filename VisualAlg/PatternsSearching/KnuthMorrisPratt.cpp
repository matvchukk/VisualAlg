#include "KnuthMorrisPratt.h"

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

std::vector<int>& KnuthMorrisPratt::getSearchPositions() {
    return  searchPositions;
}
