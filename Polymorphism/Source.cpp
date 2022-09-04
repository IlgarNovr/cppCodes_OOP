/*
class: Car
class: Manual
class: Automatic
Manaul ve Automatic-den de mashinlar yaransin.
Misal class Bmw: Automatic
funksiya yazirisiz, Parametr olaraq Base qebul edir.
Funksiya icersinde mashinlarin melumatlarni chap edirsiz.
Her mashina aid field-ler ve mehodlar olsun.
Base class adi altinda butun mashinlari vector-da saxlamaq
*/
#include <iostream>
#include <vector>
using namespace std;

class Car {
protected:
	int year;
	string model;
	string vendor;
	Car(const string vendor, const string model, const int year) {
		this->year = year;
		this->model = model;
		this->vendor = vendor;
	}
public:
	virtual void printCar() = 0;
};

class Automatic : public Car {
public:
	Automatic(const string vendor, const string model, const int year) :Car(vendor, model, year) {}
	void printCar() {
		cout << "Vendor: " << vendor << endl;
		cout << "Model: " << model << endl;
		cout << "Year: " << year << endl;
		cout << " ~ Automatic\n";
	}
};

class Manual : public Car {
public:
	Manual(const string vendor, const string model, const int year) :Car(vendor, model, year) {}
	void printCar() {
		cout << "Vendor: " << vendor << endl;
		cout << "Model: " << model << endl;
		cout << "Year: " << year << endl;
		cout << "Manual \n";
	}
};

class BMW : public Automatic {
public:
	BMW(const string vendor, const string model, const int year) :Automatic(vendor, model, year) {}
	void printCar() {
		Automatic::printCar();
		cout << "This car is BMW\n";
	}
};

class Mercedes : public Manual {
public:
	Mercedes(const string vendor, const string model, const int year) :Manual(vendor, model, year) {}
	void printCar() {
		Manual::printCar();
		cout << "This car is Mercedes\n";
	}
};

void printAllCar(Car& car) {
	cout << "____________________________\n\n";
	car.printCar();
}

int main() {
	//
	BMW bmw("BMW", "F30", 2020);
	Mercedes benz("Mercedes Benz", "e350", 2019);
	//Automatic
	Automatic c1("Hundai", "Santafe", 2008);
	Manual c2("KIA", "Optima", 2007);
	//Manual
	Automatic c3("Lada", "vaz2107", 2003);
	Automatic c4("Toyota", "corola", 2010);

	vector<Car*> cars;
	cars.push_back(&bmw);
	cars.push_back(&benz);
	cars.push_back(&c1);
	cars.push_back(&c2);
	cars.push_back(&c3);
	cars.push_back(&c4);
	for (int i = 0; i < cars.size(); i++) {
		printAllCar(*cars[i]);
	}
}