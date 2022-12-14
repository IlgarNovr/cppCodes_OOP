#include "Header.h"

void User::setUsername(const string username) {
	this->username = username;
}
void User::setPassword(const string password) {
	if (password.length() > 6)
		this->password = password;
	else
		throw InvalidArgumentException("Password is not long enough", __LINE__, "User.cpp");
}
void User::setName(const string name) {
	this->name = name;
}
void User::setSurname(const string surname) {
	this->surname = surname;
}
string User::getUsername() const { return username; }
string User::getPassword() const { return password; }
string User::getSurname() const { return surname; }
string User::getName() const { return name; }
void User::show() const {
	cout << "Username: " << username << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
}
User::User() {
	username = "unknown";
	surname = "unknown";
	password = "unknown";
	name = "unknown";
}

void Database::addUser(User& user) {
	for (int i = 0; i < user_count; i++) {
		if (users[i].getUsername() == user.getUsername())
			throw DatabaseException("This username already exist", __LINE__, "User.cpp");
	}
	User* temp = new User[++user_count];
	int i = 0;
	for (; i < user_count - 1; i++) {
		temp[i] = users[i];
	}
	temp[i] = user;
	delete[] users;
	users = temp;
	temp = nullptr;
}
User& Database::getUserByUsername(string username) {
	for (int i = 0; i < user_count; i++) {
		if (users[i].getUsername() == username) {
			return users[i];
		}
	}
	throw DatabaseException("User not found", __LINE__, "User.cpp");
}
void Database::updateUser(User& olduser, User& newuser) {
	bool found = false;
	for (int i = 0; i < user_count; i++) {
		if (users[i].getUsername() == olduser.getUsername()) {
			users[i] = newuser;
			found = true;
		}
	}
	if (!found)
		throw DatabaseException("User not found", __LINE__, "User.cpp");
}
Database::Database() {
	users = nullptr;
	user_count = 0;
}

void Registration::signIn(string username, string password) {
	User temp;
	try {
		temp = _database.getUserByUsername(username);
	}
	catch (const Exception& ex) {
		ex.saveData();
		ex.show();
	}
	if (temp.getPassword() != password) {
		throw DatabaseException("Wrong password", __LINE__, "User.cpp");
	}

}
void Registration::signUp(string username, string password, string name, string surname) {
	if (username.length() < 6) throw InvalidArgumentException("username must be longer than 6 character", __LINE__, "User.cpp");
	if (password.length() < 6) throw InvalidArgumentException("password must be longer than 6 character", __LINE__, "User.cpp");
	if (name.length() < 4) throw InvalidArgumentException("name must be longer than 4 character", __LINE__, "User.cpp");
	if (surname.length() < 6) throw InvalidArgumentException("surname must be longer than 6 character", __LINE__, "User.cpp");
	User user;
	user.setName(name);
	user.setUsername(username);
	user.setPassword(password);
	user.setSurname(surname);
	try {
		_database.addUser(user);
	}
	catch (const Exception& ex) {
		ex.saveData();
		ex.show();
	}
}
Database& Registration::getDatabase() {
	return _database;
}

void System::Control() {
	Database db;
	string username, password, name, surname;

	int index = 0;
	Registration datab(db);
	string* menu = new string[2]{ "Sign In","Sign Up" };
	while (true) {
		system("cls");
		index = choosenLine(menu, 2);
		if (index == 0) {
			system("cls");
			cout << "username: ";
			cin >> username;
			cout << "password: ";
			cin >> password;
			try {
				datab.signIn(username, password);
			}
			catch (const Exception& ex) {
				ex.saveData();
				ex.show();
				continue;
			}
			system("cls");
			datab.getDatabase().getUserByUsername(username).show();
			system("pause");
		}
		else {
			User user;
			system("cls");
			cout << "username: ";
			cin >> username;
			cout << "password: ";
			cin >> password;
			cout << "name: ";
			cin >> name;
			cout << "surname: ";
			cin >> surname;
			try {
				datab.signUp(username, password, name, surname);
			}
			catch (const Exception& ex) {
				ex.saveData();
				ex.show();
				continue;
			}
			user.setName(name);
			user.setSurname(surname);
			user.setPassword(password);
			user.setUsername(username);

		}
	}
}