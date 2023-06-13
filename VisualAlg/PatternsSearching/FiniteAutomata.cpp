#include "FiniteAutomata.h"

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

std::vector<int>& FiniteAutomata::getSearchPositions() {
    return  searchPositions;
}
