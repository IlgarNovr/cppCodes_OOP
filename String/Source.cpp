/*
	class: User
	fields:
		id,
		username,
		password

	class: Database
	fields:
		User array,
		size
	method:
		bool LogIn(User)
		bool Register(User)
		User GetUserByUsername(username)
		User GetUserById(id)
		void DeleteUserByUsername(username)
		void DeleteUserById(id)


		melumatlar file'a yazilir.
		filedan oxunur
*/
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
class User {
private:
	int id;
	string username;
	string password;

	int getFile() {
		ifstream data("Users.txt");
		if (data.is_open()) {
			int id, temp = 0;;
			string uname, pword;
			while (data >> id >> uname >> pword) {
				temp = id;
			}
			data.close();
			return temp;
		}
	}
public:
	void setUsername(const string name) {
		this->username = name;
	}
	void setPassword(const string password) {
		this->password = password;
	}
	void setId(int id) {
		this->id = id;
	}
	string getUsername() {
		return username;
	}
	string getPassword() {
		return password;
	}

	int getID()const {
		return id;
	}
	User() {
		id = getFile() + 1;
		username = "unknown";
		password = "unknown";

	}
	User& operator=(const User& testuser) {
		id = testuser.id;
		username = testuser.username;

		password = testuser.password;
		return *this;
	}
};


class DataBase {
private:
	User* arrUser;
	int size;

	void fillUserArray() {
		ifstream data("Users.txt");
		if (data.is_open()) {
			int uid, temp = 0;;
			string uname, pword;
			while (data >> uid >> uname >> pword) {
				size++;
				User* temp = new User[size];
				for (int i = 0; i < size - 1; i++) {
					temp[i] = arrUser[i];
				}
				temp[size - 1].setUsername(uname);
				temp[size - 1].setUsername(uname);
				temp[size - 1].setId(uid);
				delete[] arrUser;
				arrUser = temp;
				temp = nullptr;
			}
			data.close();
		}
	}
public:
	int getSize() {
		return size;
	}
	void showAllUser() {
		int i = 0;
		for (; i < size; i++)
		{
			cout << i + 1 << "." << arrUser[i].getUsername() << endl;
		}
		cout << i + 1 << ".Retrun\n";
	}

	bool isUsername(string username) {
		bool found = false;
		int uid;
		string uname, pword;
		ifstream data("Users.txt");
		if (data.is_open()) {
			while (data >> uid >> uname >> pword) {
				if (uname == username) {
					found = true;
				}
			}
			data.close();
		}
		return found;
	}

	void rregister(User& testuser) {
		if (!isUsername(testuser.getUsername())) {
			ofstream data("Users.txt", ios::app);
			if (data.is_open()) {
				data << testuser.getID() << " " << testuser.getUsername() << " " << testuser.getPassword() << endl;
			}
			data.close();
			size++;
			User* temp = new User[size];
			for (int i = 0; i < size - 1; i++) { temp[i] = arrUser[i]; }
			temp[size - 1] = testuser;
			delete[] arrUser;
			arrUser = temp;
			temp = nullptr;
		}
		else {
			system("cls");
			cout << "This username is repeated\n";
		}
	}

	bool isDataRight(User& testuser) {
		bool found = false;
		int uid;
		string uname, pword;
		ifstream data("Users.txt");
		if (data.is_open()) {
			while (data >> uid >> uname >> pword) {
				if (uname == testuser.getUsername() && pword == testuser.getPassword()) {
					found = true;
				}
			}
			data.close();
		}
		return found;
	}

	bool login(User& testuser) {
		bool found = isDataRight(testuser);;
		if (found) {
			return true;
		}
		return false;
	}

	User getUserbyUsername(string username) {
		bool found = false;
		User testuser;
		int uid;
		string uname, pword;
		ifstream data("Users.txt");
		if (data.is_open()) {
			while (data >> uid >> uname >> pword) {
				if (uname == username) {
					found = true;
					testuser.setUsername(uname);
					testuser.setPassword(pword);
				}
			}
			data.close();
		}
		return testuser;
	}
	User getUserbyID(int id) {
		bool found = false;
		User testuser;
		int uid;
		string uname, pword;
		ifstream data("Users.txt");
		if (data.is_open()) {
			while (data >> uid >> uname >> pword) {
				if (uid == id) {
					found = true;
					testuser.setUsername(uname);
					testuser.setPassword(pword);
				}
			}
			data.close();
		}
		return testuser;
	}
	void deleteUserbyUsername(string username) {
		int index = 0;
		bool found = false;
		for (int i = 0; i < size; i++) {
			if (username == arrUser[i].getUsername()) {
				index = i;
				found = true;
				break;
			}
		}
		if (found) {
			size--;
			User* temp = new User[size];
			for (int i = 0; i < index; i++) { arrUser[i].setId(i + 1); temp[i] = arrUser[i]; }
			for (int i = index; i < size; i++) { arrUser[i + 1].setId(i + 1); temp[i] = arrUser[i + 1]; }
			delete[] arrUser;
			arrUser = temp;
			temp = nullptr;
			ofstream myfile("Users.txt", ios::ate);
			if (myfile.is_open()) {
				for (int i = 0; i < size; i++) {
					myfile << arrUser[i].getID() << " " << arrUser[i].getUsername() << " " << arrUser[i].getPassword() << endl;
				}
			}
			myfile.close();
		}
		else cout << "There is no such username!\n";
	}
	void deleteUserbyID(int id) {
		int index = 0;
		bool found = false;
		for (int i = 0; i < size; i++) {
			if (id == arrUser[i].getID()) {
				index = i;
				found = true;
				break;
			}
		}
		if (found) {
			size--;
			User* temp = new User[size];
			for (int i = 0; i < index; i++) { arrUser[i].setId(i + 1); temp[i] = arrUser[i]; }
			for (int i = index; i < size; i++) { arrUser[i + 1].setId(i + 1); temp[i] = arrUser[i + 1]; }
			delete[] arrUser;
			arrUser = temp;
			temp = nullptr;
			ofstream myfile("Users.txt", ios::ate);
			if (myfile.is_open()) {
				for (int i = 0; i < size; i++) {
					myfile << arrUser[i].getID() << " " << arrUser[i].getUsername() << " " << arrUser[i].getPassword() << endl;
				}
			}
			myfile.close();
		}
		else cout << "There is no such user!\n";
	}
	DataBase() {
		arrUser = nullptr;
		size = 0;
		fillUserArray();
	}
	~DataBase() {
		delete[] arrUser;
	}
};

int main() {

	DataBase data;
	int num = 0;
	while (true) {
		system("cls");
		if (num == 0) {
			cout << "1.Login\n2.Register\n3.All user\n\nENTER (count): ";
			cin >> num;
		}
		if (num == 1) {
			User testuser;
			string username, password = "";
			char input;
			system("cls");
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			input = _getch();
			while (int(input) != 13) {
				if (int(input) != 8) {
					password.push_back(input);
					cout << "*";
				}
				input = _getch();
			}
			testuser.setUsername(username);
			testuser.setPassword(password);
			bool found = data.login(testuser);
			if (found) {
				system("cls");
				testuser = data.getUserbyUsername(username);
				cout << "Username: " << testuser.getUsername() << endl;
				cout << "Password: " << testuser.getPassword() << endl;
				cout << "1.Delete User\n2.Return\n\nENTER (count): ";
				cin >> num;
				if (num == 1) {
					data.deleteUserbyUsername(username);
				}
				num = 0;
			}
			else {
				system("cls");
				cout << "Username or password is wrong\n";
				system("pause");
				num = 0;
			}
		}
		else if (num == 2) {
			system("cls");
			User testuser;
			string temp;
			cout << "Username: ";
			cin >> temp;
			testuser.setUsername(temp);
			cout << "Password: ";
			cin >> temp;
			testuser.setPassword(temp);
			data.rregister(testuser);
			num = 0;
		}
		else if (num == 3) {
			int index;
			system("cls");
			data.showAllUser();
			cout << "ENTER: ";
			cin >> num;
			index = num;
			if (num > 0 && num <= data.getSize()) {
				system("cls");
				cout << "Username: " << data.getUserbyID(index).getUsername() << endl;
				cout << "1.Delete\n2.Return\n\nENTER: ";
				cin >> num;
				if (num == 1) {
					data.deleteUserbyID(index);
					num = 3;
				}
				num = 3;
			}
			else if (num == data.getSize() + 1) {
				num = 0;
			}
			else {
				system("cls");
				cout << "Wrong Index\n";
				system("pause");
				num = 3;
			}
		}
		else {
			system("cls");
			cout << "Wrong Index\n";
			system("pause");
			num = 0;
		}
	}
}