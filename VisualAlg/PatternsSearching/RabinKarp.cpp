#include "RabinKarp.h"

RabinKarp::RabinKarp(QObject *parent) : QObject(parent)
{
}

void RabinKarp::search(const QString& text, const QString& pattern)
{
    const int d = 256; // кількість символів в алфавіті
    int q = INT_MAX; // просте число

    int n = text.length();
    int m = pattern.length();
    int h = 1;
    int patternHash = 0;
    int textHash = 0;

    std::vector<int> positions; // Вектор для збереження позицій, де знайдено паттерн

    // Значення h буде "pow(d, m-1)%q"
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Обчислення хеш-значення для шаблону та першого вікна тексту
    patternHash = hash(pattern, m, q);
    textHash = hash(text, m, q);

    // Пересуваємо шаблон по тексту по одному символу
    for (int i = 0; i <= n - m; i++) {
        // Перевіряємо, чи співпадають хеш-значення поточного вікна тексту та шаблону.
        // Якщо хеш-значення співпадають, то перевіряємо символи поодинці
        if (patternHash == textHash) {
            // Перевіряємо символи поодинці
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            // Якщо j дорівнює m, то знайдено шаблон
            if (j == m)
                positions.push_back(i); // Збереження позиції, де знайдено паттерн
        }

        // Обчислення хеш-значення для наступного вікна тексту:
        // видаляємо перший символ, додаємо останній символ
        if (i < n - m) {
            textHash = (d * (textHash - text[i].unicode() * h) + text[i + m].unicode()) % q;

            // Можливе отримання від'ємного значення textHash, перетворюємо його в додатнє
            if (textHash < 0)
                textHash = (textHash + q);
        }
    }

    emit searchCompleted(positions); // Відправлення сигналу з позиціями, де знайдено паттерн
}

int RabinKarp::hash(const QString& str, int len, int q)
{
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash = (hash * 256 + str[i].unicode()) % q; // Припускаємо, що просте число q = 256 для спрощення
    }
    return hash;
}

//int RabinKarp::rehash(const QString& str, int oldIndex, int newIndex, int oldHash, int h, int q)
//{
//    int newHash = oldHash - str[oldIndex].unicode();
//    newHash = (newHash / 256) % q;
//    newHash = (newHash * 256 + str[newIndex].unicode()) % q;
//    return newHash;
//}
