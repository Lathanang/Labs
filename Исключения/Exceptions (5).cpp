#include <iostream>
using namespace std;

struct triangle {
	double a;
	double b;
	double c;
};

double Perimeter(triangle r)  {
	if (r.a + r.b < r.c || r.a + r.c < r.b || r.c + r.b < r.a) {
		throw 'e';
	}
	else {
		return r.a + r.b + r.c;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	triangle t;
	cout << "Введите 3 строны треугольника: ";
	cin >> t.a >> t.b >> t.c;
	try {
		cout << Perimeter(t);
	}
	catch (char) {
		cout << "Ошибка!";
	}
	return 0;
}

