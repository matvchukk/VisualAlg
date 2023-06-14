#include "RabinKarp.h"
/// Searches for the pattern in the given text using the Rabin-Karp algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void RabinKarp::search(const QString& text, const QString& pattern)
{
    const int d = 256; // кількість символів
    int q = INT_MAX;

    int n = text.length();
    int m = pattern.length();
    int h = 1;
    int patternHash = 0;
    int textHash = 0;

    std::vector<int> positions;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    patternHash = hash(pattern, m, q);
    textHash = hash(text, m, q);

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == m)
                positions.push_back(i);
        }

        if (i < n - m) {
            textHash = (d * (textHash - text[i].unicode() * h) + text[i + m].unicode()) % q;

            if (textHash < 0)
                textHash = (textHash + q);
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}
/// Computes the hash value of a string
/// @param str The string to compute the hash value for
/// @param len The length of the string
/// @param q A prime number used for the hash calculation
/// @returns The computed hash value
int RabinKarp::hash(const QString& str, int len, int q)
{
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash = (hash * 256 + str[i].unicode()) % q;
    }
    return hash;
}
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& RabinKarp::getSearchPositions() {
    return  searchPositions;
}

