#ifndef RK_H
#define RK_H
#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The RabinKarp class implements the Rabin-Karp pattern search algorithm.
class RabinKarp : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    RabinKarp(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Rabin-Karp algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Computes the hash value of a string
    /// @param str The string to compute the hash value for
    /// @param len The length of the string
    /// @param q A prime number used for the hash calculation
    /// @returns The computed hash value
    int hash(const QString& str, int len, int q);
};


#endif // RK_H


