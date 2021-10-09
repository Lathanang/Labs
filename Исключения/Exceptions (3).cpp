#include <iostream>
using namespace std;

struct triangle {
	double a;
	double b;
	double c;
};

class VoidException

{

};

double Perimeter(triangle r) throw(VoidException) {
	if (r.a + r.b < r.c || r.a + r.c < r.b || r.c + r.b < r.a) {
		throw VoidException();
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
	catch (VoidException& e) {
		cout << "Ошибка!";
	}
	return 0;
}

