#include <iostream>
using namespace std;

struct triangle {
	double a;
	double b;
	double c;
};

class Exception {
public:
	string s;
	Exception(string str)
	{
		s = str;

	}
	string what()
	{
		return s;
	}
};

double Perimeter(triangle r) throw(Exception) {
	if (r.a + r.b < r.c || r.a + r.c < r.b || r.c + r.b < r.a) {
		throw Exception("Треугольника не сщуетвует!");
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
	catch (Exception& e) {
		cout << e.what();
	}
	return 0;
}

