#include "CollinsAlgorithm.h"

void CollinsAlgorithm::search(const QString& text, const QString& pattern)
{
    int n = text.length();
    int m = pattern.length();

    std::vector<int> jumpTable = computeJumpTable(pattern);

    std::vector<int> positions;

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[i + j])
            j--;

        if (j < 0) {
            positions.push_back(i);
            i += jumpTable[0];
        } else {
            int jump = jumpTable[j];
            if (jump > 0) {
                i += std::max(1, j - jump);
            } else {
                i++;
            }
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}

std::vector<int> CollinsAlgorithm::computeJumpTable(const QString& pattern)
{
    int m = pattern.length();

    std::vector<int> jumpTable(m, 0);

    int lastPrefixPosition = m;

    for (int i = m - 1; i >= 0; i--) {
        if (isPrefix(pattern, i + 1)) {
            lastPrefixPosition = i + 1;
        }
        jumpTable[i] = lastPrefixPosition - i + m - 1;
    }

    for (int i = 0; i < m - 1; i++) {
        int suffixLength = computeSuffixLength(pattern, i);
        jumpTable[suffixLength] = m - 1 - i + suffixLength;
    }

    return jumpTable;
}

int CollinsAlgorithm::computeSuffixLength(const QString& pattern, int p)
{
    int length = 0;
    int j = pattern.length() - 1;
    while (p >= 0 && pattern[p] == pattern[j]) {
        length++;
        p--;
        j--;
    }
    return length;
}

bool CollinsAlgorithm::isPrefix(const QString& pattern, int p)
{
    int patternLength = pattern.length();
    for (int i = p, j = 0; i < patternLength; i++, j++) {
        if (pattern[i] != pattern[j]) {
            return false;
        }
    }
    return true;
}

std::vector<int>& CollinsAlgorithm::getSearchPositions() {
    return  searchPositions;
}
