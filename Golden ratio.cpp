// Golden ratio.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "math.h"
using namespace std;
#define e 0.000001

double func(double x) {
	double y;
	return y = pow(x, 2) - sin(x);
}

int main()
{
	double b;
	double a;
	a = -1;
	b = 2;
	double la = (1 + sqrt(5)) / 2;
	double del = (b - a) / (pow(la, 2));
	double X = a + del;
	double Y = b - del;
	double Fx = func(X);
	double Fy = func(Y);
	int i = 0;
	//cout.precision(1 / e);

	while (b - a >= 2 * e) {
		if (func(X) > func(Y)) {
			a = X;
			X = Y;
			Fx = Fy;
			Y = a + b - X;
			Fy = func(Y);
			i++;
		}
		else {
			b = Y;
			Y = X;
			Fy = Fx;
			X = a + b - Y;
			Fx = func(X);
			i++;
		}
	}
	double xe = (a + b) / 2;
	cout << "iterations: " << i << endl;
	//cout.precision(-log10(e));
	cout << "A " << a << endl;
	cout << "B " << b << endl;
	cout << "X " << X << endl;
	cout << "Y " << Y << endl;
	cout << "FX " << func(X) << endl;
	cout << "FY " << func(Y) << endl;
	cout << "xe " << xe << endl;
	cout << "f(xe) " << func(xe) << endl;
	cout << endl;
	//cout.precision(-log10(e));
	//cout << "e " << e << endl;
	return 0;
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

