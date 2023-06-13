#ifndef RK_H
#define RK_H
#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class RabinKarp : public PatternSearchStrategy
{
    Q_OBJECT

private:
    std::vector<int> searchPositions;

public:
    RabinKarp(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;
    Q_INVOKABLE std::vector<int>& getSearchPositions() override;

private:
    int hash(const QString& str, int len, int q);
};


#endif // RK_H


