//#include "FiniteAutomata.h"

//#include <QDebug>
//#include <vector>

//void FiniteAutomata::calcTF(const QString& pattern, std::vector<std::vector<int>>& TF)
//{
//    int M = pattern.length();
//    int x, state;
//    for (state = 0; state <= M; ++state) {
//        for (x = 0; x < 256; ++x) {
//            TF[state][x] = calcNextState(pattern, state, QChar(x));
//        }
//    }
//}

//void FiniteAutomata::search(const QString& text, const QString& pattern)
//{
//    int M = pattern.length();
//    int N = text.length();
//    std::vector<std::vector<int>> TF(M + 1, std::vector<int>(256));

//    calcTF(pattern, TF);

//    int i, state = 0;
//    for (i = 0; i < N; i++) {
//        state = TF[state][text[i].toLatin1()];
//        if (state == M) {
//            qDebug() << "Given pattern is found at index" << i - M + 1;
//        }
//    }
//}
