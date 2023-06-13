#ifndef PATTERNSEARCHSTRATEGY_H
#define PATTERNSEARCHSTRATEGY_H

#include <QObject>
#include <QString>
#include <vector>

class PatternSearchStrategy : public QObject
{
    Q_OBJECT
private:
    std::vector<int> positions;
public:
    PatternSearchStrategy(QObject *parent = nullptr) : QObject(parent) {}
    virtual void search(const QString& text, const QString& pattern) = 0;
//    const std::vector<int>& getSearchPositions() const
//    {
//        return positions;
//    }
    virtual std::vector<int>& getSearchPositions() = 0;

signals:
    void searchCompleted(const std::vector<int>& positions);
};

#endif // PATTERNSEARCHSTRATEGY_H
