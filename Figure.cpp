#include <iostream>
#include<math.h>
using namespace std;
#define PI 3.1415926535

class Figure {
public:
    virtual double Area() {
        return 0.0;
    }
    virtual double Perimeter() {
        return 0.0;
    }
    virtual void getInfo() {
    }
};

class Circle : public Figure {
private:
    double R;
public:

    Circle(double R) {
        if (R < 0) {
            throw invalid_argument("Радиуса меньше нуля не существует!");
        }
        this->R = R;
    }
    double Area() override {
        return PI * R * R;
    }

    double Perimeter() override {
        return 2 * PI * R;
    }
    double get_Rad() {
        return R;
    }

    double set_Rad(double newR) {
        if (R < 0) {
            throw invalid_argument("Радиуса меньше нуля не существует!");
        }
        R = newR;
    }

    void getInfo() override {
        cout << "Радиус окружности: " << R << endl;
    }
};


class Rectangle : public Figure {
private:
    double a; // первая сторона
    double b; // вторая сторона
public:

    Rectangle(double a, double b) {
        if (a <= 0 || b <= 0) {
            throw invalid_argument("Длины стороны меньше нуля не существует!");
        }
        this->a = a;
        this->b = b;
    }
    double Area() override {
        return a*b;
    }

    double Perimeter() override {
        return 2*(a + b);
    }

    double set_sides(double a, double b) {
        if (a < 0 || b < 0) {
            throw invalid_argument("Длины стороны меньше нуля не существует!");
        }
        this->a = a;
        this->b = b;
    }

    void getInfo() override {
        cout << "Стороны прямоугольника: " << a << ", " << b << endl;
    }
};


class Triangle : public Figure {
private:
    double a; // первая сторона
    double b; // вторая сторона
    double c; // третья сторона
public:

    Triangle(double a, double b, double c) {
        if ((b + c < a) || (a + c < b) || (a + b < c)) {
            throw invalid_argument("Такого треугольника не существует!");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double Area() override {
        double p = ((a + b + c) / 2.0);
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    double Perimeter() override {
        return a + b + c;
    }

    double set_sides(double a, double b, double c) {
        if ((a <= 0 || b <= 0 || c <= 0) || (a + b < c)) {
            throw invalid_argument("Такого треугольника не существует!");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }

    void getInfo() override {
        cout << "Стороны треугольника: " << a << ", " << b << ", " << c << endl;
    }
};

int main()
{
    int num, i;
    double a, b, c, R;
    setlocale(LC_ALL, "rus");
    while (true)
    {
        cout << "Выберите тип фигуры:\n1.Оркужность\n2.Прямогульник\n3.Треугольник\n4.Выход\n";
        cin >> num;
        if (num == 4) break;
        else if (num == 1) {
            cout << "Введите радиус окружности\n";
            cin >> R;
            Circle circle = Circle(R);
            cout << "1.Площадь окружности\n2.Периметр оркужности\n";
            do {
                cin >> i;
            } while (i <= 0 || i > 2);
            if (i == 1) cout << circle.Area() << endl;
            else if (i == 2) cout << circle.Perimeter() << endl;
            circle.getInfo();
        }
        else if (num == 2) {
            cout << "Введите cтороны прямоугольника\n";
            cin >> a >> b;
            Rectangle rectangle = Rectangle(a, b);
            cout << "1.Площадь прямоугольника\n2.Периметр прямоугольника\n";
            do {
                cin >> i;
            } while (i <= 0 || i > 2);
            if (i == 1) cout << rectangle.Area() << endl;
            else if (i == 2) cout << rectangle.Perimeter() << endl;
            rectangle.getInfo();
        }
        else if (num == 3) {
            cout << "Введите cтороны треугольника\n";
            cin >> a >> b >> c;
            Triangle triangle = Triangle(a, b, c);
            cout << "1.Площадь треугольника\n2.Периметр треугольника\n";
            do {
                cin >> i;
            } while (i <= 0 || i > 2);
            if (i == 1) cout << triangle.Area() << endl;
            else if (i == 2) cout << triangle.Perimeter() << endl;
            triangle.getInfo();
        }
    }
    return 0;
}
