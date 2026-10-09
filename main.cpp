// Оленчук Є. В., ІК-12. ЛР 4.2, варіант 10. Табуляція функції однієї змінної.
// y = 4,95x^2 + B(x), де B(x) = 4 + x^(-2),        x < -3,5
//                              tg((3,5 + x) / 5),  -3,5 <= x < 1
//                              sin(3x) - cos(x),   x >= 1
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x, xp, xk, dx;   // аргумент, початок, кінець інтервалу, крок
    double A, B, y;         // стала й змінна частини виразу, результат

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    // Крок має бути додатним, а початок не більшим за кінець,
    // інакше цикл не завершиться або таблиця буде порожньою.
    if (!cin || dx <= 0 || xp > xk) {
        cerr << "Invalid input (need dx > 0 and xp <= xk)\n";
        return 1;
    }

    // Невеликий допуск, щоб накопичена похибка x += dx
    // не загубила останній рядок таблиці.
    const double eps = 1e-9;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
         << setw(12) << "y" << " |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk + eps)
    {
        A = 4.95 * x * x;
        if (x < -3.5)
            B = 4 + pow(x, -2);
        else
            if (x < 1)
                B = tan((3.5 + x) / 5);
            else
                B = sin(3 * x) - cos(x);
        y = A + B;

        cout << "|" << setw(8) << setprecision(2) << x
             << " |" << setw(12) << setprecision(4) << y
             << " |" << endl;
        x += dx;
    }
    cout << "---------------------------" << endl;
    return 0;
}
