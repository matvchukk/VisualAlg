#ifndef FINITEAUTOMATA_H
#define FINITEAUTOMATA_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"
/// The FiniteAutomata class implements the Finite-Automata pattern search algorithm.
class FiniteAutomata : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    FiniteAutomata(QObject *parent) : PatternSearchStrategy(parent) {}
    /// Searches for the pattern in the given text using the Finite Automata algorithm
    /// @param text The text to search in
    /// @param pattern The pattern to search for
    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    /// Returns the positions where the pattern was found in the text
    /// @returns A reference to the vector of search positions
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    /// Returns the next state of the Finite Automata based on the current state and input
    /// @param pattern The pattern to search for
    /// @param M The length of the pattern
    /// @param state The current state of the Finite Automata
    /// @param x The input character
    /// @returns The next state of the Finite Automata
    int getNextState(const QString& pattern, int M, int state, int x);
};

#endif // FINITEAUTOMATA_H

