#ifndef RABINKARP_H
#define RABINKARP_H

#include <QObject>
#include <QString>
#include <vector>

class RabinKarp : public QObject
{
    Q_OBJECT
public:
    explicit RabinKarp(QObject *parent = nullptr);

    Q_INVOKABLE void search(const QString& text, const QString& pattern);

signals:
    void searchCompleted(const std::vector<int>& positions);

private:
    int hash(const QString& str, int len, int q);
//    int rehash(const QString& str, int oldIndex, int newIndex, int oldHash, int h, int q);
};


#endif // RABINKARP_H
