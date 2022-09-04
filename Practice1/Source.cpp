// Autosalon management system 
	// Mashinlarimiz olacaq
	// Ishchilerimiz olacaq
	// Ishchi elave etmek 
	// Mashin elave etmek
	// mashin satilmasi ve kirayesi
	// axtarish sistemi 
	// umumi budce olacaq
	// umumi ayliq gelir (butun alver)
	// umumi ayliq menfeet (butun alver - xerc)
	// umumi ayliq xerc
	// hefteni bitir

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//Avtomobil
class Car {
private:
	string model;
	string marka;
	string color;
	int year;
	int price;
	int rent;
	int km;
	int sellingPrice;
	void setSellingPrice() {
		sellingPrice = price * 0.5 + price;
	}
	void setRent() {
		rent = price * 0.08;
	}

public:
	bool rentedCar;

	void setModel(string model) {
		this->model = model;
	}
	void setmarka(string marka) {
		this->marka = marka;
	}
	void setColor(string color) {
		this->color = color;
	}
	void setYear(int year) {
		if (year <= 2021 && year >= 1900)
			this->year = year;
		else {
			this->year = 2021;
			cout << "Bu ilde olan avtomobillerin alis-satisi movcud deyil!\n";
		}
	}
	void setPrice(int price) {
		if (price > 0)
			this->price = price;
		else {
			this->price = 10000;
			cout << "Yanlis qiymet!\n";
		}
	}
	void setKm(int km) {
		if (km >= 0)
			this->km = km;
		else {
			this->km = 0;
			cout << "Yanlis surus mesafesi!\n";
		}
	}

	string getModel() {
		return model;
	}
	string getmarka() {
		return marka;
	}
	string getColor() {
		return color;
	}
	int getYear() {
		return year;
	}
	int getPrice() {
		return price;
	}
	int getKm() {
		return km;
	}
	int getRent() {
		return rent;
	}
	int getSellingPrice() {
		return sellingPrice;
	}

	Car() {
		model = "unknown";
		marka = "unknown";
		color = "unknown";
		year = 2021;
		rent = 1000;
		price = 10000;
		km = 0;
		setSellingPrice();
		setRent();
		rentedCar = false;
	}
	Car(const Car& car) {
		setmarka(car.marka);
		setModel(car.model);
		setColor(car.color);
		setYear(car.year);
		setPrice(car.price);
		setKm(car.km);
		setSellingPrice();
		setRent();
		rentedCar = car.rentedCar;
	}
	Car& operator=(const Car& car) {
		setmarka(car.marka);
		setModel(car.model);
		setColor(car.color);
		setYear(car.year);
		setPrice(car.price);
		setKm(car.km);
		setSellingPrice();
		setRent();
		rentedCar = car.rentedCar;
		return *this;
	}
};
//Isciler
class Seller {
private:
	string name;
	string lastname;
	int salary;
	int age;
	int phone;
public:
	void setName(const string name) {
		this->name = name;
	}
	void setlastname(const string lastname) {
		this->lastname = lastname;
	}
	void setSalary(const int salary) {
		if (salary > 300) {
			this->salary = salary;
		}
		else {
			cout << "\n300-den az maas olmamalidir!";
			this->salary = 300;
		}
	}
	void setAge(const int age) {
		if (age >= 18 && age < 65) { this->age = age; }
		else {
			cout << "\nYas 18-64 olmalidir!";
			this->age = 18;
		}
	}
	void setphone(const int phone) {
		if (phone > 1000000 && phone < 1000000000) { this->phone = phone; }
		else {
			this->phone = 3124756;
			cout << "\nNomre teyin edilmemisdir!";
		}
	}

	string getName() {
		return name;
	}
	string getlastname() {
		return lastname;
	}
	int getSalary() {
		return salary;
	}
	int getAge() {
		return age;
	}
	int getphone() {
		return phone;
	}
	//Constructor
	Seller() {
		name = "unknown";
		lastname = "unknown";
		salary = 300;
		age = 18;
		phone = 1234567;
	}
	Seller(const Seller& emp) {
		setAge(emp.age);
		setName(emp.name);
		setlastname(emp.lastname);
		setSalary(emp.salary);
		setphone(emp.phone);
	}
	Seller& operator=(const Seller& emp) {
		setAge(emp.age);
		setName(emp.name);
		setlastname(emp.lastname);
		setSalary(emp.salary);
		setphone(emp.phone);
		return *this;
	}
};
//Avtosalon
class Autosalon {
private:
	int numCar;
	int numSeller;
	Car* car = new Car[numCar];
	Seller* emp = new Seller[numSeller];
	//budce 
	int week;
	int budget;
	int expense;
	int ex;
	int income;
	int in;
	int profit;
	int pr;
public:
	//Avtomobil
	void addCar(Car& cr) {
		expense += cr.getPrice();
		numCar++;
		Car* temp = new Car[numCar];
		for (int i = 0; i < numCar - 1; i++) { temp[i] = car[i]; }
		temp[numCar - 1] = cr;
		delete[]car;
		car = temp;
		temp = nullptr;
	}
	void sellCar(int index) {
		income += car[index].getSellingPrice();
		numCar--;
		Car* temp = new Car[numCar];
		for (int i = 0; i < index; i++) { temp[i] = car[i]; }
		for (int i = index; i < numCar; i++) { temp[i] = car[i + 1]; }
		delete[]car;
		car = temp;
		temp = nullptr;
	}
	void showCars() {
		system("cls");
		int i = 0;
		for (; i < numCar; i++) {
			cout << i + 1 << "." << car[i].getmarka() << " " << car[i].getModel();
			if (car[i].rentedCar)cout << " Rented";
			cout << endl;
		}
		cout << i + 1 << ".Buy new car for salon\n"; i++;
		cout << i + 1 << ".Search\n"; i++;
		cout << i + 1 << ".Return\n";
	}
	void showCarsDetails(int index, int sh) {
		if (index > 0 && index <= numCar) {
			index--;
			cout << "\nMarka: " << car[index].getmarka();
			cout << "\nModel: " << car[index].getModel();
			cout << "\nColor:	" << car[index].getColor();
			cout << "\nYear: " << car[index].getYear();
			cout << "\nKm: " << car[index].getKm() << " km";
			cout << "\nRent: " << car[index].getRent() << " $";
			cout << "\nPrice: " << car[index].getSellingPrice() << " $\n";
			if (!sh) {
				if (!car[index].rentedCar)
				{
					cout << "\n\n1.Sell" << "\n2.Rent" << "\n3.Return";
				}
				else cout << "\n1.Request car back\n2.Return";
			}
		}
		else cout << "Wrong index\n";
	}
	void requestCarBack(int index) { car[index].rentedCar = false; }
	void rentACar(int index) {
		car[index].rentedCar = true;
	}
	bool isRented(int index) { return car[index].rentedCar; }
	void searchCar(int index, int sch) {
		system("cls");
		bool found = false;
		switch (index)
		{
		case 4:
			for (int i = 0; i < numCar; i++) {
				if (car[i].getYear() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		case 5:
			for (int i = 0; i < numCar; i++) {
				if (car[i].getPrice() >= sch - 1000 && car[i].getPrice() <= sch + 1000) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		}
		if (!found) { cout << "\nNot found"; }
		cout << "\nPress any key to return..";
		_getch();
	}
	void searchCar(int index, string sch) {
		system("cls");
		bool found = false;
		switch (index)
		{
		case 1:
			for (int i = 0; i < numCar; i++) {
				if (car[i].getmarka() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		case 2:
			for (int i = 0; i < numCar; i++) {
				if (car[i].getModel() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		case 3:
			for (int i = 0; i < numCar; i++) {
				if (car[i].getColor() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		}
		if (!found) { cout << "\nNot found"; }
		cout << "\nPress any key to return..";
		_getch();
	}
	//Satici
	void addSeller(Seller& em) {
		numSeller++;
		Seller* temp = new Seller[numSeller];
		for (int i = 0; i < numSeller - 1; i++) { temp[i] = emp[i]; }
		temp[numSeller - 1] = em;
		delete[] emp;
		emp = temp;
		temp = nullptr;
	}
	void fireSeller(int index) {
		if (emp[index].getName() != "Ilqar" && emp[index].getlastname() != "Novruzov") {
			numSeller--;
			Seller* temp = new Seller[numSeller];
			for (int i = 0; i < index; i++) { temp[i] = emp[i]; }
			for (int i = index; i < numSeller; i++) { temp[i] = emp[i + 1]; }
			delete[]emp;
			emp = temp;
			temp = nullptr;
		}
		else { cout << "YOU CAN'T FIRE Ilqar Novruzov!!!\n"; Sleep(1500); }
	}
	void showSellers() {
		system("cls");
		int i = 0;
		for (; i < numSeller; i++) {
			cout << i + 1 << "." << emp[i].getlastname() << " " << emp[i].getName() << endl;
		}
		cout << i + 1 << ".Add new Seller" << endl; i++;
		cout << i + 1 << ".Search" << endl; i++;
		cout << i + 1 << ".Return" << endl;
	}
	void showEmpDetails(int index, int sh) {
		system("cls");
		cout << "Name: " << emp[index].getName() << endl;
		cout << "Last Name: " << emp[index].getlastname() << endl;
		cout << "Age: " << emp[index].getAge() << endl;
		cout << "Phone Num: " << emp[index].getphone() << endl;
		cout << "Salary: " << emp[index].getSalary() << " $" << endl;
		if (!sh)
			cout << "1.Fire Seller" << "\n2.Return";
	}
	void searchSeller(int index, string sch) {
		system("cls");
		bool found = false;
		switch (index)
		{
		case 1:
			for (int i = 0; i < numSeller; i++) {
				if (emp[i].getName() == sch) {
					showEmpDetails(i, 1);
					found = true;
				}
			}
			break;
		case 2:
			for (int i = 0; i < numSeller; i++) {
				if (emp[i].getlastname() == sch) {
					showEmpDetails(i, 1);
					found = true;
				}
			}
			break;
		}
		if (!found) { cout << "\nNot found"; }
		cout << "\nPress any key to return..";
		_getch();
	}
	//Autosalon
	int getnumOfCar() { return numCar; }
	int getNumOfEmp() { return numSeller; }
	void endWeek() {
		if (week == 4) {
			ex = 0;
			pr = 0;
			in = 0;
			week = 0;
		}
		week++;
		for (int i = 0; i < numSeller; i++) { expense += emp[i].getSalary() / 4; }
		for (int i = 0; i < numCar; i++) {
			if (car[i].rentedCar)
				income += car[i].getRent() / 4;
		}
		int temp = budget;
		budget = budget - expense + income;
		profit += budget - temp;
		ex += expense;
		in += income;
		pr += profit;
		expense = 0;
		income = 0;
		profit = 0;
	}
	void showBudget() {
		cout << "Week: " << week << endl;
		cout << "Budget: " << budget << endl;
		cout << "Expense: " << ex << endl;
		cout << "Income: " << in << endl;
		cout << "Profit: " << pr << endl;
		cout << "Press any key to return..\n";
		_getch();
	}
	Autosalon() {
		numCar = 0;
		numSeller = 0;
		budget = 500000;
		expense = 0;
		income = 0;
		profit = 0;
		ex = 0;
		pr = 0;
		in = 0;
		week = 0;
	}
};

//DATA
void addData(Autosalon& salon) {
	int wrkNum = 4;
	Seller* emp = new Seller[wrkNum];
	emp[0].setName("Qabil");
	emp[0].setlastname("Memmedov");
	emp[0].setSalary(12000);
	emp[0].setphone(0553451255);
	emp[0].setAge(45);
	emp[1].setName("Elekber");
	emp[1].setlastname("Yasamalli");
	emp[1].setSalary(2000);
	emp[1].setphone(0505734534);
	emp[1].setAge(40);
	emp[2].setName("Bayram");
	emp[2].setlastname("Kurdexanli");
	emp[2].setSalary(1000);
	emp[2].setphone(3542378);
	emp[2].setAge(51);
	emp[3].setName("Orxan");
	emp[3].setlastname("Lokbatanli");
	emp[3].setSalary(3000);
	emp[3].setphone(0706543267);
	emp[3].setAge(31);
	for (int i = 0; i < wrkNum; i++) {
		salon.addSeller(emp[i]);
	}
	int crnum = 5;
	Car* car = new Car[crnum];
	car[0].setmarka("Mercedes Benz");
	car[0].setColor("Black");
	car[0].setModel("E190");
	car[0].setKm(200000);
	car[0].setPrice(20000);
	car[0].setYear(2001);
	car[1].setmarka("BMW");
	car[1].setColor("White");
	car[1].setModel("E39");
	car[1].setKm(2000);
	car[1].setPrice(25000);
	car[1].setYear(2005);
	car[2].setmarka("Toyota");
	car[2].setColor("Red");
	car[2].setModel("Land Cruiser");
	car[2].setKm(68000);
	car[2].setPrice(35000);
	car[2].setYear(2013);
	car[3].setmarka("Lexus");
	car[3].setColor("Grey");
	car[3].setModel("HS250H");
	car[3].setKm(139000);
	car[3].setPrice(26800);
	car[3].setYear(2010);
	car[4].setmarka("Lada");
	car[4].setColor("Black");
	car[4].setModel("Niva 4x4");
	car[4].setKm(30000);
	car[4].setPrice(12000);
	car[4].setYear(2010);
	for (int i = 0; i < crnum; i++) { salon.addCar(car[i]); }
}

int main() {
	int num = 0;
	Autosalon salon;
	addData(salon);
	while (true) {
		system("cls");
		if (num == 0) {
			cout << "1.Cars\n" << "2.Sellers\n" << "3.Budget\n" << "4.End Week\n" << "ENTER: ";
			cin >> num;
		}
		system("cls");
		if (num == 1) {
			salon.showCars();
			cout << "\n\nENTER: ";
			cin >> num;
			if (num <= salon.getnumOfCar()) {
				system("cls");
				salon.showCarsDetails(num, 0);
				int index = num - 1;
				cout << "\n\nENTER: ";
				cin >> num;
				system("cls");
				if (salon.isRented(index)) {
					if (num == 1) {
						salon.requestCarBack(index);
					}
					else if (num == 2) { num = 1; }
				}
				else {
					if (num == 1) {
						salon.sellCar(index);
					}
					else if (num == 2) {
						salon.rentACar(index);
						num = 1;
					}
					else if (num == 3) { num = 1; }
				}
			}
			else if (num == salon.getnumOfCar() + 1) {
				system("cls");
				Car car;
				int tmInt;
				string tmString;
				cout << "marka: ";
				cin >> tmString; car.setmarka(tmString);
				cout << "\nModel: ";
				cin >> tmString; car.setModel(tmString);
				cout << "\nColor:	";
				cin >> tmString; car.setColor(tmString);
				while (true) {
					cout << "\nYear: ";
					cin >> tmInt;
					if (tmInt >= 1920 && tmInt <= 2021)
						break;
					cout << "\nWrong";
				}
				car.setYear(tmInt);
				while (true) {
					cout << "\nKm: ";
					cin >> tmInt;
					if (tmInt >= 0)
						break;
					cout << "\nWrong";
				}
				car.setKm(tmInt);
				while (true) {
					cout << "\nPrice: ";
					cin >> tmInt;
					if (tmInt > 0)
						break;
					cout << "\nWrong";
				}
				car.setPrice(tmInt);
				salon.addCar(car);
				num = 1;
			}
			else if (num == salon.getnumOfCar() + 2) {
				system("cls");
				cout << "Search car for:\n";
				cout << "1.marka\n2.Model\n3.Color\n4.Year\n5.Price\n6.Return";
				cout << "\n\nENTER: ";
				cin >> num;
				if (num > 0 && num < 4) {
					system("cls");
					string sch;
					cout << "Search: ";
					cin >> sch;
					salon.searchCar(num, sch);
					num = 1;
				}
				else if (num > 3 && num < 6) {
					system("cls");
					int sch;
					cout << "Search: ";
					cin >> sch;
					salon.searchCar(num, sch);
					num = 1;
				}
				else if (num == 6) { num = 1; }
			}
			else if (num == salon.getnumOfCar() + 3) { salon.endWeek(); num = 0; }
		}
		else if (num == 2) {
			salon.showSellers();
			cout << "\n\nENTER: ";
			cin >> num;
			if (num <= salon.getNumOfEmp()) {
				system("cls");
				salon.showEmpDetails(num - 1, 0);
				int index = num - 1;
				cout << "\n\nENTER: ";
				cin >> num;
				system("cls");
				if (num == 1) {
					salon.fireSeller(index);
					num = 2;
				}
			}
			else if (num <= salon.getNumOfEmp() + 1) {
				system("cls");
				int intg;
				string str;
				Seller emp;
				cout << "Name: ";
				cin >> str;
				emp.setName(str);
				cout << "Last Name: ";
				cin >> str;
				emp.setlastname(str);
				while (true) {
					cout << "Age: ";
					cin >> intg;
					if (intg >= 18 && intg < 65)
						break;
					cout << "\nWrong\n";
				}
				emp.setAge(intg);
				while (true) {
					cout << "Phone Num: ";
					cin >> intg;
					if (intg > 1000000 && intg < 10000000)
						break;
					cout << "\nWrong\n";
				}
				emp.setphone(intg);
				while (true) {
					cout << "Salary: ";
					cin >> intg;
					if (intg > 300)
						break;
					cout << "\nWrong\n";
				}
				emp.setSalary(intg);
				salon.addSeller(emp);
				num = 2;
			}
			else if (num <= salon.getNumOfEmp() + 2) {
				system("cls");
				cout << "Search Seller for:\n";
				cout << "1.Name\n2.Last Name\n3.Return";
				cout << "\n\nENTER: ";
				cin >> num;
				if (num > 0 && num < 3) {
					system("cls");
					string sch;
					cout << "Search: ";
					cin >> sch;
					salon.searchSeller(num, sch);
					num = 2;
				}
				else if (num == 3) {
					num = 2;
				}
			}
			else if (num <= salon.getNumOfEmp() + 3) {
				num = 0;
			}
		}
		else if (num == 3) { salon.showBudget(); num = 0; }
		else if (num == 4) { salon.endWeek(); num = 0; }
	}
}