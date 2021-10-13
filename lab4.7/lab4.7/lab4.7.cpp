// lab4.7.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 4.7
// Обчислення суми ряду Тейлора за допомогою ітераційних циклів та рекурентних співвідношень.
// Варіант 19

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	double xFirst, xLast, x, dx, eps, a, R, Sum;
	int n = 1;

	cout << "Enter first x: ";	cin >> xFirst;
	cout << "Enter last x: ";	cin >> xLast;
	cout << "Enter dx: ";		cin >> dx;
	cout << "Enter eps: ";		cin >> eps;

	cout << fixed;
	cout << "-------------------------------------------------\n";
	cout << "|" << setw(7)  << "x"         << " |"
				<< setw(10) << "arcsin(x)" << " |"
				<< setw(10) << "Sum"       << " |"
				<< setw(5)  << "n"		   << " |\n";
	cout << "-------------------------------------------------\n";

	for (x = xFirst; x <= xLast; x += dx) {
		for (a = pow(x, 3) / 6., n = 2, Sum = x + a; abs(a) >= eps; n++) {
			R = (pow((2 * n - 1), 2) * x * x) / (2. * n * (2 * n + 1));
			a *= R;
			Sum += a;
		}

		cout  << "|" << setw(7)  << setprecision(2) << x	   << " |"
			         << setw(10) << setprecision(5) << asin(x) << " |"
			         << setw(10) << setprecision(5) << Sum     << " |"
			         << setw(5)					    << n       << " |\n";
	}

	cout << "-------------------------------------------------\n";

	return 0;
}
