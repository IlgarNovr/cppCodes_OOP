/*
void deleteContact(const string& name) {}
void find(const string& data){}
*/
#include <iostream>
#include <fstream>
using namespace std;

void addContact(const string& name, const string& phone) {
	string _name, _phone;
	bool find = false;
	ifstream data("contact.txt", ios::in);
	if (data.is_open()) {
		while (data >> _name >> _phone) {
			if (phone == _phone) {
				find = true;
			}
		}
	}		
	data.close();
	if (find)throw "Bu nomre contacta daha once daxil edilib!";
	if (!find) {
		ofstream data("contact.txt", ios::app);
		if (data.is_open()) {
			data << name << " " << phone << endl;
		}
	}
	data.close();
}

void deleteContact(const string& name) {
	string _name, phone;
	ofstream temp("temp.txt", ios::out);
	if (temp.is_open()) {
		ifstream data("contact.txt", ios::in);
		if (data.is_open()) {
			while (data >> _name >> phone) {
				if (_name != name) {
					temp << _name << " " << phone << endl;
				}
			}
		}
		data.close();
	}
	temp.close();
	ofstream data("contact.txt", ios::out);
	if (data.is_open()) {
		ifstream temp("temp.txt", ios::in);
		if (temp.is_open()) {
			while (temp >> _name >> phone) {
				data << _name << " " << phone << endl;
			}
		}
	}
	remove("temp.txt");
}
void find(const string& data) {
	string name, phone;
	ifstream fl("contact.txt", ios::in);
	if (fl.is_open()) {
		while (fl >> name >> phone) {
			if (name == data || phone == data) {
				cout << "Name: " << name << endl;
				cout << "Phone: " << phone << endl;
			}
		}
	}
	fl.close();
}

void print() {
	string name, phone;
	ifstream fl("contact.txt", ios::in);
	if (fl.is_open()) {
		while (fl >> name >> phone) {
				cout << "Name: " << name << "\nPhone: " << phone;
				cout << "\n---------------------------\n";
		}
	}
	fl.close();
}
int main() {
	try {
		addContact("Qezenfer", "123456");
	}
	catch (const char* ex) {
		cout << ex<<endl;
	}	
	try {
		addContact("Ali", "123456");
	}
	catch (const char* ex) {
		cout << ex << endl;
	}
	print();
}