//#ifndef FINITEAUTOMATA_H
//#define FINITEAUTOMATA_H

//#include <QObject>
//#include <QString>
//#include <vector>
//#include <unordered_map>
//#include "PatternSearchStrategy.h"

//class FiniteAutomata : public PatternSearchStrategy
//{
//    Q_OBJECT
//public:
//    FiniteAutomata(QObject *parent) : PatternSearchStrategy(parent) {}

//    Q_INVOKABLE void search(const QString& text, const QString& pattern);

//private:
//    void calcTF(const QString& pattern, std::vector<std::vector<int>>& TF);
//    int calcNextState(const QString& pattern, int state, QChar ch);

//};

//#endif // FINITEAUTOMATA_H


////#ifndef FINITEAUTOMATA_H
////#define FINITEAUTOMATA_H

////#include <QObject>
////#include <QString>
////#include <vector>
////#include <unordered_map>
////#include "PatternSearchStrategy.h"

////// Custom hash function for QChar
////#include <QChar>

////// Custom hash function for QChar
////struct QCharHash {
////    std::size_t operator()(const QChar& ch) const {
////        return std::hash<int>()(ch.unicode());
////    }
////};


////class FiniteAutomata : public PatternSearchStrategy
////{
////    Q_OBJECT
////public:
////    FiniteAutomata(QObject *parent) : PatternSearchStrategy(parent) {}

////    Q_INVOKABLE void search(const QString& text, const QString& pattern);

////private:
////    void computeTransitionFunction(const QString& pattern);
////    int getNextState(const QString& pattern, int state, QChar ch);

////    std::unordered_map<QChar, std::vector<int>, QCharHash> transitionTable;
////};

////#endif // FINITEAUTOMATA_H
