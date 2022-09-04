#include <iostream>
using namespace std;
#define MAX 5
template <class T>
class Stack {
	T arr[MAX];
	int top;
public:
	Stack() { top = -1; }
	bool isEmpty() { return top < 0; }
	bool isFull() { return top == MAX - 1; }
	T peak() {
		if (!isEmpty()) {
			return arr[top];
		}
		cout << "Is Empty!\n";
	}
	void pop() {
		if (isEmpty()) {
			cout << "Is Empty!\n";
			return;
		}
		arr[--top];
	}
	void push(const T& data) {
		if (isFull()) {
			cout << "Is Full!\n";
			return;
		}
		arr[++top] = data;
	}
};
class Engine {
	float _volume;
	string _company;
public:
	void setVolume(float volume) {
		_volume = volume;
	}
	void setCompany(string company) {
		_company = company;
	}
	float getVolume() {
		return _volume;
	}
	string getCompany() {
		return _company;
	}
	Engine() {
		_volume = 1;
		_company = "unknown";
	}
	Engine(const Engine& engine) {
		_volume = engine._volume;
		_company = engine._company;
	}
	Engine& operator=(const Engine engine) {
		_volume = engine._volume;
		_company = engine._company;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Engine& engine) {
		os << "Company: " << engine._company << endl;
		os << "Volume: " << engine._volume << endl;
		return os;
	}
};

class Vehicle {
protected:
	string vendor;
	string model;
	Engine engine;
	Vehicle& vhcl() {
		return *this;
	}
public:
	void setVendor(string vendor) {
		this->vendor = vendor;
	}
	void setModel(string model) {
		this->model = model;
	}
	void setEngine(const Engine& engine) {
		this->engine = engine;
	}
	string getVendor() {
		return vendor;
	}
	string getModel() {
		return model;
	}
	Engine getEngine() {
		return engine;
	}
	Vehicle() {
		vendor = "unknown";
		model = "unknown";
	}
};
class Car : public Vehicle {
	static int NextID;
	int id;
	bool hasSpoiler;
public:
	void setSpoiler(bool spoiler) {
		hasSpoiler = spoiler;
	}
	void resetID() {
		NextID = 0;
		id = 0;
	}
	int getID() {
		return id;
	}
	bool getSpoiler() {
		return hasSpoiler;
	}
	Car() : Vehicle() {
		hasSpoiler = false;
		id = NextID++;
	}
	Car(const Car& car) {
		engine = car.engine;
		vendor = car.vendor;
		model = car.model;
		id = car.id;
		hasSpoiler = car.hasSpoiler;
	}
	Car& operator=(const Car& car) {
		engine = car.engine;
		vendor = car.vendor;
		model = car.model;
		id = car.id;
		hasSpoiler = car.hasSpoiler;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Car& car) {
		os << "ID: #" << car.id << endl;
		os << "Spoiler: ";
		if (car.hasSpoiler)os << "yes\n";
		else os << "no\n";
		os << "Vendor: " << car.vendor << endl;
		os << "Model: " << car.model << endl;
		os << "Engine -: \n" << car.engine;
		return os;
	}
};
int Car::NextID = 0;
class Ship : public Vehicle {
	static int NextID;
	int id;
	bool hasSail;

public:
	void setHasSail(bool sail) {
		hasSail = sail;
	}
	void resetID() {
		NextID = 0; id = 0;
	}
	int getID() {
		return id;
	}
	bool getHasSail() {
		return hasSail;
	}
	Ship() : Vehicle() {
		id = NextID++;
		hasSail = false;
	}
	Ship(const Ship& ship) {
		id = ship.id;
		hasSail = ship.hasSail;
		engine = ship.engine;
		vendor = ship.vendor;
		model = ship.model;
	}
	Ship& operator=(const Ship& ship) {
		id = ship.id;
		hasSail = ship.hasSail;
		engine = ship.engine;
		vendor = ship.vendor;
		model = ship.model;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Ship& ship) {
		os << "ID: #" << ship.id << endl;
		os << "Sail: ";
		if (ship.hasSail)os << "yes\n";
		else os << "no\n";
		os << "Vendor: " << ship.vendor << endl;
		os << "Model: " << ship.model << endl;
		os << "Engine -: \n" << ship.engine;
		return os;
	}
};
int Ship::NextID = 0;
class Airplane : public Vehicle {
	static int NextID;
	int id;
	int engineCount;
	int passengersCount;
public:
	void setEngineCount(int count) {
		engineCount = count;
	}
	void setPCount(int count) {
		engineCount = count;
	}
	void resetID() {
		NextID = 0; id = 0;
	}
	int getEngineCount() {
		return engineCount;
	}
	int getPsngrCount() {
		return passengersCount;
	}
	int getID() { return id; }
	Airplane() : Vehicle() {
		id = NextID++;
		engineCount = 1;
		passengersCount = 1;
	}
	Airplane(const Airplane& plane) {
		id = plane.id;
		engineCount = plane.engineCount;
		passengersCount = plane.passengersCount;
		engine = plane.engine;
		vendor = plane.vendor;
		model = plane.model;
	}
	Airplane& operator=(const Airplane& plane) {
		id = plane.id;
		engineCount = plane.engineCount;
		passengersCount = plane.passengersCount;
		engine = plane.engine;
		vendor = plane.vendor;
		model = plane.model;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Airplane& plane) {
		os << "ID: #" << plane.id << endl;
		os << "Seats: " << plane.passengersCount << endl;
		os << "Vendor: " << plane.vendor << endl;
		os << "Model: " << plane.model << endl;
		os << "Engine -: \n" << plane.engine;
		os << "Num of Engine: " << plane.engineCount << endl;
		return os;
	}
};
int Airplane::NextID = 0;
class VehicleDepo {
	Stack<Car> cars;
	Stack<Ship> ships;
	Stack<Airplane> planes;
public:
	void addCar(const Car& car) {
		cars.push(car);
	}
	void addShip(const Ship& ship) {
		ships.push(ship);
	}
	void addPlane(const Airplane& plane) {
		planes.push(plane);
	}
	void showAllVehicle() {
		cout << "\nCar______________________\n\n";
		while (!cars.isEmpty()) {
			cout << cars.peak();
			cars.pop();
		}
		cout << "\nShip_____________________\n\n";
		while (!ships.isEmpty()) {
			cout << ships.peak();
			ships.pop();
		}
		cout << "\nAirplane__________________\n\n";
		while (!planes.isEmpty()) {
			cout << planes.peak();
			planes.pop();
		}
	}
	VehicleDepo() {
		Car cr;
		cr.resetID();
		Ship sp;
		sp.resetID();
		Airplane ap;
		ap.resetID();
	}
};

int main() {
	VehicleDepo depo;

	Car* car = new Car[1];
	Engine e_car;
	e_car.setCompany("Mercedes Benz");
	e_car.setVolume(2.4);
	car[0].setModel("C-class 240");
	car[0].setVendor("Mercedes");
	car[0].setEngine(e_car);
	car[0].setSpoiler(false);
	depo.addCar(car[0]);

	Ship* ship = new Ship[1];
	Engine e_ship;
	e_ship.setCompany("Handymax");
	e_ship.setVolume(30);
	ship[0].setModel("OCEAN 4");
	ship[0].setVendor("Handy");
	ship[0].setEngine(e_ship);
	ship[0].setHasSail(false);
	depo.addShip(ship[0]);

	Airplane* plane = new Airplane[1];
	Engine e_plane;
	e_plane.setCompany("Jet Aircraft");
	e_plane.setVolume(6);
	plane[0].setModel("Bombardier CRJ-100");
	plane[0].setVendor("JET");
	plane[0].setEngine(e_plane);
	plane[0].setEngineCount(4);
	plane[0].setPCount(20);
	depo.addPlane(plane[0]);

	depo.showAllVehicle();
}