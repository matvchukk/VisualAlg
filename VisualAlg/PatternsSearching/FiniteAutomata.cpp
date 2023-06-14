#include "FiniteAutomata.h"
/// Searches for the pattern in the given text using the Finite Automata algorithm
/// @param text The text to search in
/// @param pattern The pattern to search for
void FiniteAutomata::search(const QString& text, const QString& pattern)
{
    int M = pattern.size();
    int N = text.size();

    std::vector<std::vector<int>> TF(M + 1, std::vector<int>(256, 0));

    int state, x;
    for (state = 0; state <= M; ++state)
    {
        for (x = 0; x < 256; ++x)
            TF[state][x] = getNextState(pattern, M, state, x);
    }

    std::vector<int> positions;

    state = 0;
    for (int i = 0; i < N; ++i)
    {
        state = TF[state][text[i].unicode()];
        if (state == M)
        {
            positions.push_back(i - M + 1);
        }
    }
    searchPositions = positions;
    emit searchCompleted(positions);
}
/// Returns the next state of the Finite Automata based on the current state and input
/// @param pattern The pattern to search for
/// @param M The length of the pattern
/// @param state The current state of the Finite Automata
/// @param x The input character
/// @returns The next state of the Finite Automata
int FiniteAutomata::getNextState(const QString& pattern, int M, int state, int x)
{
    if (state < M && x == pattern[state].unicode())
        return state + 1;

    int ns;
    for (ns = state; ns > 0; --ns)
    {
        if (pattern[ns - 1].unicode() == x)
        {
            int i;
            for (i = 0; i < ns - 1; ++i)
            {
                if (pattern[i].unicode() != pattern[state - ns + 1 + i].unicode())
                    break;
            }
            if (i == ns - 1)
                return ns;
        }
    }

    return 0;
}
/// Returns the positions where the pattern was found in the text
/// @returns A reference to the vector of search positions
std::vector<int>& FiniteAutomata::getSearchPositions() {
    return  searchPositions;
}
