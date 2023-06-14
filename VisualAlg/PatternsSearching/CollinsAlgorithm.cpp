#include "CollinsAlgorithm.h"
/// Searches for the pattern in the given text using the Collins algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
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
/// Computes the jump table for the pattern
/// @param pattern The pattern for which to compute the jump table
/// @returns The computed jump table
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
/// Computes the length of the suffix of the pattern at position p
/// @param pattern The pattern for which to compute the suffix length
/// @param p The position of the suffix
/// @returns The length of the suffix
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
/// Checks if a string is a prefix of the pattern
/// @param pattern The pattern to check against
/// @param p The position to start the comparison
/// @returns True if the string is a prefix, false otherwise
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
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& CollinsAlgorithm::getSearchPositions() {
    return  searchPositions;
}
