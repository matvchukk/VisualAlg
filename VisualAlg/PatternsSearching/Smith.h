#ifndef SMITH_H
#define SMITH_H

#include <QObject>
#include <QString>
#include <vector>
#include "PatternSearchStrategy.h"

class Smith : public PatternSearchStrategy
{
    Q_OBJECT
public:
    Smith(QObject *parent) : PatternSearchStrategy(parent) {}

    Q_INVOKABLE void search(const QString& text, const QString& pattern) override;

private:
    std::vector<int> computePrefixFunction(const QString& pattern);
};

#endif // SMITH_H
