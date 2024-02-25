#include <iostream>
#include <clocale>
using namespace std;
const int n = 8;
int a[n][n];
void boar() // Создание нулевого массива 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}
void resh2() // вывод измененного массива
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                cout << " Q "; // Ферзь
            }
            else if (a[i][j] > 0) {
                cout << " X "; // Клетка под боем
            }
            else {
                cout << " _ "; // Клетка    
            }
        }
        cout << endl;
    }
}
void Ferz(int i, int j) // Подстановка ферзя
{
    for (int x = 0; x < n; ++x)
    {
        a[x][j] += 1;
        a[i][x] += 1;
        int d;
        d = j - i + x;
        if (d >= 0 && d < n)
        {
            a[x][d] += 1;
        }
        d = j + i - x;
        if (d >= 0 && d < n) {
            a[x][d] += 1;
        }
    }
    a[i][j] = -1;
    cout << endl;
    resh2();
}
void del(int i, int j) // Удаление ферзя
{
    for (int x = 0; x < n; ++x) {
        a[x][j] -= 1;
        a[i][x] -= 1;
        int d;
        d = j - i + x;
        if (d >= 0 && d < n) {
            a[x][d] -= 1;
        }
        d = j + i - x;
        if (d >= 0 && d < n) {
            a[x][d] -= 1;
        }
    }
    cout << endl << "Отмена прошлого хода" << endl;
    resh2();
    a[i][j] = 0;
}
bool resh1(int i) //Основная функция
{
    bool f = false;
    for (int j = 0; j < n; ++j)
    {
        if (a[i][j] == 0)
        {
            Ferz(i, j); // Постановка ферзя
            if (i == 7)
            {
                f = true;
            }
            else if (!(f = resh1(i + 1)))
            {
                del(i, j); // Удаление ферзя
            }
        }
        if (f) break;
    }
    return f;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    boar();
    resh1(0);
    cout << endl << "Итог:" << endl;
    resh2();
    return 0;
}