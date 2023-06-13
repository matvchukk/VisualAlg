#include "BoyerMooreHorspool.h"

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

    emit searchCompleted(positions);
}

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
