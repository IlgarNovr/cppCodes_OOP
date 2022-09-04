#include <iostream>

using namespace std;
class Date {
private:
	int _d;
	int _m;
	int _y;
public:
	int getDay()const {
		return _d;
	}
	int getMonth()const {
		return _m;
	}
	int getYear()const {
		return _y;
	}
	void setDate(const Date& time) {
		_d = time._d;
		_m = time._m;
		_y = time._y;
	}
	friend ostream& operator<<(ostream& os, const Date& time) {
		if (time._d <= 9) { os << 0; }
		os << time._d << "/";
		if (time._m <= 9) { os << 0; }
		os << time._m << "/" << time._y;
		return os;
	}

	Date& operator++(int) {
		_d++;
		if (_m == 2) {
			if (_y % 4 == 0 && _d == 30) {
				_d = 1;
				_m++;
			}
			else if (_y % 4 && _d == 29) {
				_d = 1;
				_m++;
			}
		}
		else if ((_m == 4 || _m == 6 || _m == 9 || _m == 11) && _d == 31) {
			_d = 1;
			_m++;
		}
		else if (_m == 12 && _d == 32) {
			_d = 1;
			_m = 1;
			_y++;
		}
		else if ((_m == 1 || _m == 3 || _m == 5 || _m == 7 || _m == 8 || _m == 10) && _d == 32) {
			_d = 1;
			_m++;
		}
		return *this;
	}
	bool operator<=(const Date& time) {
		if (_y == time._y) {
			if (_m == time._m) {
				if (_d <= time._d) {
					return true;
				}
			}
			else if (_m <= time._m) {
				return true;
			}
		}
		else if (_y <= time._y) {
			return true;
		}
		return false;
	}
	bool operator>=(const Date& time) {
		if (_y == time._y) {
			if (_m == time._m) {
				if (_d >= time._d) {
					return true;
				}
			}
			else if (_m >= time._m) {
				return true;
			}
		}
		else if (_y >= time._y) {
			return true;
		}
		return false;
	}
	Date() {
		_d = 1;
		_m = 1;
		_y = 2021;
	}
	Date(const Date& time) {
		_d = time._d;
		_m = time._m;
		_y = time._y;
	}
	Date& operator=(const Date& time) {
		_d = time._d;
		_m = time._m;
		_y = time._y;
		return *this;
	}
};
class Debtor {
private:
	bool _TFpayment;
	string _name;
	string _surname;
	string _workAddress;
	string _homeAddress;
	int _salary;
	int _phoneNumber;
	int _debt;
	Date _borrowDate;
	Date _paymentDate;
public:
	void setName(string name) {
		_name = name;
	}
	void setSurname(string surname) {
		_surname = surname;
	}
	void setWorkAddress(string address) {
		_workAddress = address;
	}
	void setHomeAddress(string address) {
		_homeAddress = address;
	}
	void setSalary(int salary) {
		_salary = salary;
	}
	void setPhoneNum(int num) {
		_phoneNumber = num;
	}
	void setDebt(int debt) {
		_debt = debt;
	}
	void setisPaymentLate(bool isLate) {
		_TFpayment = isLate;
	}
	void setDebtDate(Date& time, int day) {
		_borrowDate = time;
		_paymentDate = time;
		for (int i = 0; i < day; i++) { _paymentDate++; }
	}
	string getName()const {
		return _name;
	}
	string getSurname()const {
		return _surname;
	}
	string getWorkAddress()const {
		return _workAddress;
	}
	string getHomeAddress()const {
		return _homeAddress;
	}
	int getSalary()const {
		return _salary;
	}
	int getPhoneNum()const {
		return _phoneNumber;
	}
	int getDebt()const {
		return _debt;
	}
	bool getisPaymentLate()const {
		return _TFpayment;
	}
	Date getBorrowDate() {
		return _borrowDate;
	}
	Date getPaymentDate() {
		return _paymentDate;
	}
	friend ostream& operator<<(ostream& os, const Debtor& debtor) {
		os << debtor.getName() << " " << debtor.getSurname() << endl;
		return os;
	}
	Debtor() {
		_name = "unknown";
		_surname = "unknown";
		_workAddress = "unknown";
		_homeAddress = "unknown";
		_salary = 1000;
		_phoneNumber = 0;
		_debt = 0;
		_TFpayment = false;
	}
	Debtor(const Debtor& debtor) {
		setName(debtor._name);
		setSurname(debtor._surname);
		setWorkAddress(debtor._workAddress);
		setHomeAddress(debtor._homeAddress);
		setSalary(debtor._salary);
		setDebt(debtor._debt);
		setPhoneNum(debtor._phoneNumber);
		setisPaymentLate(debtor._TFpayment);
		_paymentDate = debtor._paymentDate;
		_borrowDate = debtor._borrowDate;
	}
	Debtor& operator=(const Debtor& debtor) {
		setName(debtor._name);
		setSurname(debtor._surname);
		setWorkAddress(debtor._workAddress);
		setHomeAddress(debtor._homeAddress);
		setSalary(debtor._salary);
		setDebt(debtor._debt);
		setisPaymentLate(debtor._TFpayment);
		setPhoneNum(debtor._phoneNumber);
		_paymentDate = debtor._paymentDate;
		_borrowDate = debtor._borrowDate;
		return *this;
	}
};
class Bank {
private:
	string _name;
	int count;
	Debtor* _debtor;
public:
	void setBankName(string name) {
		_name = name;
	}
	string getBankName() {
		return _name;
	}
	int getCount() {
		return count;
	}
	void addDebtor(Debtor& debtor) {
		count++;
		Debtor* temp = new Debtor[count];
		for (int i = 0; i < count - 1; i++) { temp[i] = _debtor[i]; }
		temp[count - 1] = debtor;
		delete[] _debtor;
		_debtor = temp;
		temp = nullptr;
	}
	void deleteDebtor(int index) {
		if (count > 0) {
			count--;
			Debtor* temp = new Debtor[count];
			for (int i = 0; i < index; i++) {
				temp[i] = _debtor[i];
			}
			for (int i = index; i < count; i++) {
				temp[i] = _debtor[i + 1];
			}
			delete[] _debtor;
			_debtor = temp;
			temp = nullptr;
		}
		else {
			system("cls");
			cout << "Borc yoxdur\n";
			system("pause");
		}
	}
	void showAllDebtors() {
		int i = 0;
		for (; i < count; i++) {
			cout << i + 1 << "." << _debtor[i];
		}
		cout << i + 1 << ".";
		cout << "Musteri elave etmek.\n"; i++;
		cout << i + 1 << ".";
		cout << "Gunu sonlandir!!!\n";
	}
	int showDebtor(int index) {
		int i = 1;
		int c = 0;
		cout << "Ad: " << _debtor[index].getName() << endl;
		cout << "Soyad: " << _debtor[index].getSurname() << endl;
		cout << "Telefon: " << _debtor[index].getPhoneNum() << endl;
		cout << "Maas: " << _debtor[index].getSalary() << " $" << endl;
		cout << "Ev adresi: " << _debtor[index].getHomeAddress() << endl;
		cout << "Is adresi: " << _debtor[index].getWorkAddress() << endl;
		if (_debtor[index].getisPaymentLate()) {
			cout << _debtor[index].getName() << " " << _debtor[index].getSurname() << " kredit\n";
		}
		cout << "Mebleg: " << _debtor[index].getDebt() << " $" << endl;
		if (_debtor[index].getDebt()) {
			cout << "Alinma tarixi: " << _debtor[index].getBorrowDate() << endl;
			cout << "Tehvil verilme tarixi: " << _debtor[index].getPaymentDate() << endl;
			cout << i << ". Meblegi geri ode\n"; i++;
			c += 10;
		}
		if (!_debtor[index].getisPaymentLate()) {
			cout << i << ".Kredit\n"; i++;
			if (_debtor[index].getDebt() == 0) {
				cout << i << ".Musterini sil\n"; i++;
				c++;
			}
			c += 1;
		}
		cout << i << ".Geri\n";
		return c;
	}
	void requestMoney(int index) {
		_debtor[index].setDebt(0);
		_debtor[index].setisPaymentLate(false);
		system("cls");
		cout << "Emeliyyat sona catdi!!!";
	}
	void loanMoney(Date& date, int day, int money, int index) {
		_debtor[index].setDebtDate(date, day);
		money += _debtor[index].getDebt();
		_debtor[index].setDebt(money);

	}
	void endDay(Date& date) {
		for (int i = 0; i < count; i++) {
			int money = _debtor[i].getDebt();
			bool late = false;
			if (money) {
				if (_debtor[i].getPaymentDate() <= date) { late = true; }
				if (late) { money += money * 0.7; }
				else { money += money * 0.1; }
				_debtor[i].setDebt(money);
			}
			_debtor[i].setisPaymentLate(late);
		}
	}
	Bank() {
		_name = "unknown";
		count = 0;
		_debtor = nullptr;
	}
};


int main() {
	Date time;
	Bank bank1;
	bank1.setBankName("MiniKapital Bank");
	int num = 0;
	int index = 0;
	while (true) {
		system("cls");
		if (num == 0) {
			cout << time << endl;
			cout << bank1.getBankName() << endl << endl;
			bank1.showAllDebtors();
			cout << "\nENTER: ";
			cin >> num;
			index = num - 1;
		}
		if (num > 0 && num < bank1.getCount() + 1) {
			system("cls");
			cout << time << endl;
			int choose = bank1.showDebtor(index);
			cout << "\nENTER: ";
			cin >> num;
			system("cls");
			if (choose == 10) {
				if (num == 1) {
					bank1.requestMoney(index);
					num = 1;
				}
				else if (num == 2) { num = 0; }
				else {
					system("cls");
					cout << "Wrong Index\n";
					system("pause");
					num = 1;
				}
			}
			else if (choose == 11) {
				if (num == 1) {
					bank1.requestMoney(index);
					num = 1;
				}
				else if (num == 2) {
					system("cls");
					cout << time << endl;
					int money, day;
					cout << "Mebleg daxil edin: ";
					cin >> money;
					cout << "Muddet daxil edin: ";
					cin >> day;
					bank1.loanMoney(time, day, money, index);
					num = 1;
				}
				else if (num == 3) { num = 0; }
				else {
					system("cls");
					cout << "Wrong Index\n";
					system("pause");
					num = 1;
				}
			}
			else if (choose == 2) {
				if (num == 1) {
					system("cls");
					cout << time << endl;
					int money, day;
					cout << "Mebleg daxil edin: ";
					cin >> money;
					cout << "Muddet daxil edin: ";
					cin >> day;
					bank1.loanMoney(time, day, money, index);
					num = 1;
				}
				else if (num == 2) {
					bank1.deleteDebtor(index);
					num = 0;
				}
				else if (num == 3) { num = 0; }
				else {
					system("cls");
					cout << "Wrong Index\n";
					system("pause");
					num = 1;
				}
			}
		}
		else if (num == bank1.getCount() + 1) {
			system("cls");
			Debtor temp;
			string info;
			int tint;
			cout << "Ad: ";
			cin >> info;
			temp.setName(info);
			cout << "Soyad: ";
			cin >> info;
			temp.setSurname(info);
			cout << "Telefon: ";
			cin >> tint;
			temp.setPhoneNum(tint);
			cout << "Maas: ";
			cin >> tint;
			temp.setSalary(tint);
			cout << "Ev adresi: ";
			cin >> info;
			temp.setHomeAddress(info);
			cout << "Is adresi: ";
			cin >> info;
			temp.setWorkAddress(info);
			bank1.addDebtor(temp);
			num = 0;
		}
		else if (num == bank1.getCount() + 2) {
			time++;
			bank1.endDay(time);
			num = 0;
		}
		else {
			system("cls");
			cout << "Wrong Index\n";
			system("pause");
			num = 0;
		}
	}
}