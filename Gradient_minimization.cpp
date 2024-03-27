// Gradient_minimization.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<time.h>
#include <cmath>
using namespace std;

double f(double z1, double z2) {
    double res = sqrt(pow(z1, 2) + 2 * pow(z2, 2) + 1) + 0.5 * z1 - 0.5 * z2;
    return res;
}
double fder1(double z1, double z2) {
    double res = z1 / sqrt(pow(z1, 2) + 2 * pow(z2, 2) + 1) + 0.5;
    return res;
}
double fder2(double z1, double z2) {
    double res = 2 * z2 / sqrt(pow(z1, 2) + 2 * pow(z2, 2) + 1) - 0.5;
    return res;
}
double phi(double z1, double z2, double s, double h1, double h2) {
    double res = f(z1 - h1 * s, z2 - h2 * s);
    return res;
}
int main()
{
    double z1 = 50;
    double e = 0.0000001;
    double z2 = 50;
    double i = 0.1;
    double s = 0;
    double h1 = fder1(z1, z2);
    double h2 = fder2(z1, z2);
    double* m = new double[2];
    double n = sqrt(pow(h1, 2) + pow(h2, 2));
    m[0] = phi(z1, z2, s, h1, h2);
    s += i;
    int k = 0;
    m[1] = phi(z1, z2, s, h1, h2);
    while (n > e) {
        while (m[0] > m[1]) {
            m[0] = m[1];
            s += i;
            m[1] = phi(z1, z2, s, h1, h2);
        }
        double b;
        double a;
        a = 0;
        b = s;
        double la = (1 + sqrt(5)) / 2;
        double del = (b - a) / (pow(la, 2));
        double X = a + del;
        double Y = b - del;
        double Fx = phi(z1, z2, a, h1, h2);
        double Fy = phi(z1, z2, b, h1, h2);
        while (b - a >= 2 * e) {
            if (phi(z1, z2, X, h1, h2) >= phi(z1, z2, Y, h1, h2)) {
                a = X;
                X = Y;
                Fx = Fy;
                Y = a + b - X;
                Fy = phi(z1, z2, Y, h1, h2);
            }
            else {
                b = Y;
                Y = X;
                Fy = Fx;
                X = a + b - Y;
                Fx = phi(z1, z2, X, h1, h2);
            }
        }
        s = ((a + b) / 2);
        k++;
        z1 = z1 - s * h1;
        z2 = z2 - s * h2;       
        h1 = fder1(z1, z2);
        h2 = fder2(z1, z2);
        n = sqrt(pow(h1, 2) + pow(h2, 2));        
        s = 0;
        i = 0.1;
        m[0] = phi(z1, z2, s, h1, h2);
        s += i;
        m[1] = phi(z1, z2, s, h1, h2);
    }
    cout.precision(6);
    cout << "z1: " << z1 << " " << endl;
    cout << "z1: " << z2 << " " << endl;
    cout << "f(z1,z2): " << f(z1, z2) << " " << endl;
    cout << "|f'(z)|: " << n << endl;
    cout << "Number of iterations: " << k << " " << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
