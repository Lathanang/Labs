#include <iostream>
using namespace std;

struct triangle {
	double a;
	double b;
	double c;
};

class InCorrectTriangle : public exception
{
public:
	const char* what() const throw() {

		return "Треугольника с данными сторонами не существует!";

	}
};

double Perimeter(triangle r) throw(InCorrectTriangle) {
	if (r.a + r.b < r.c || r.a + r.c < r.b || r.c + r.b < r.a) {
		throw InCorrectTriangle();
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
	catch (InCorrectTriangle& e) {
		cout << e.what();
	}
	return 0;
}

