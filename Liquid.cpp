#include <iostream>

using namespace std;


class Liquid {
private:
    int density;
    string name;
public:
    Liquid() { // Конструктор по умолчанию
        this->density = 0;
        this->name = "None";
    }

    Liquid(int density, string name) { // Конструктор c прямыми параметрами
        if (density <= 0) {
            throw invalid_argument("Плотности равной или меньше нуля не существует!\n");
        }
        this->density = density;
        this->name = name;
    }

    void set_density(int newDensity) {
        if (newDensity <= 0) {
            throw invalid_argument("Плотности равной или меньше нуля не существует!\n");
        }
        this->density = newDensity;
    }

    int get_density() const{
        return this->density;
    }

    void set_name(string newName) {
        this->name = newName;
    }

    string get_name() const {
        return this->name;
    }

    virtual void getInfo() {
        cout << "Название жидкости: " << this->name << "; " << "Плотность жидкости: " << this->density << endl;
    }
};


class Alcohol : public Liquid {
private:
    int strength;
public:
    Alcohol(int density, string name, int strength) : Liquid(density, name) {
        if (strength < 0) {
            throw invalid_argument("Крепости меньше нуля не существует!\n");
        }
        this->strength = strength;
    }

    void set_strength(int newStrength) {
        if (newStrength < 0) {
            throw invalid_argument("Крепости меньше нуля не существует!\n");
        }
        this->strength = newStrength;
    }

    int get_strength() {
        return this->strength;
    }

    void getInfo() override {
        Liquid::getInfo();
        cout << "Крепость: " << this->strength << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "rus");
    // тестирование методов и конструктора класса жидкости
    Liquid liquid = Liquid(1000, "water");
    liquid.getInfo();
    liquid.set_name("NewWater");
    try {
        liquid.set_density(-42);
    }
    catch (exception& ex) {
        cout << ex.what();
    }
    liquid.set_density(999);
    liquid.getInfo();

    Alcohol alc = Alcohol(1000, "Vodka", 40);
    alc.getInfo();
    alc.set_name("Another vodka");
    try {
        alc.set_strength(0);
    }
    catch (exception& ex) {
        cout << ex.what();
    }
    alc.set_strength(38);
    alc.getInfo();
    return 0;
}

