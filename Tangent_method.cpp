// Tangent_method.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "math.h"
using namespace std;
#define e 0.000001
#define pi 3.1415926

double func(double x) {
    double y;
    return y = pow(x, 2) - sin(x);
}

double derf(double x) {
    double dy;
    return dy = 2 * x - cos(x);
}

int main()
{
    double a;
    a = 0;
    double b;
    b = pi / 2;
    int i;
    i = 0;
    double xe;
    xe = 0;     
    double res = 0;
        while (1)
        {
            if (derf(a) >= 0) {
                cout << "xmin = " << a << endl;
                cout << "f(a) = " << func(a) << endl;                 
                break;
            }
            if (derf(b) <= 0) {
                cout << "xmin = " << b << endl;
                cout << "f(b) = " << func(b) << endl;
                break;
            }
            double da = derf(a);
            double db = derf(b);
            double Fa;
            Fa = func(a) - da * a;
            double Fb;
            Fb = func(b) - db * b;
            xe = (Fb - Fa) / (da - db);
            if (derf(xe) > e) { b = xe; }
            if (derf(xe) < -e) { a = xe; }
            i++;
            if ((derf(xe) >= -e) && (derf(xe) <= e))
               {                
                    res = xe;
                    break;
              }
        }
        cout << "iterations numb: " << i << endl;
        cout << "a = : " << a << endl;
        cout << "b = : " << b << endl;
        cout << "xmin = : " << res << endl;
        cout << "F(min) = : " << func(res);
    /*print(i)
        print(a)
        print(b)        
        print(xe)
        print(f(xe))*/
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
