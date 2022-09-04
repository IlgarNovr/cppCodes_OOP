#include <iostream>
#include <conio.h>
#include <assert.h>
using namespace std;
#define MaxProduct 10
template <class T>
class Stack {
	T arr[MaxProduct];
	int top;
public:
	Stack() {
		top = -1;
	}
	T Peak() {
		if (!isEmpty()) {
			return arr[top];
		}
		cout << "Stack is Empty!\n";
		return arr[top];
	}
	void Push(const T& item) {
		if (isFull()) {
			cout << "Stack is Full!\n";
		}
		else {
			arr[++top] = item;
		}
	}
	void Pop() {
		if (isEmpty()) { cout << "Stack is Empty!\n"; }
		else { arr[--top]; }
	}
	bool isEmpty() { return top < 0; }
	bool isFull() { return top == MaxProduct - 1; }
};
class Product {
	static int nextID;
	string name;
	string company;
	int id;
	int price;

public:
	void setPrice(const int price) {
		assert(price > 0, "Error\n");
		this->price = price;
	}
	void setName(const string name) {
		this->name = name;
	}
	void setCompany(const string company) {
		this->company = company;
	}
	void setID(int id) {
		nextID = id;
		this->id = id;
	}
	int getID()const { return id; }
	int getPrice()const { return price; }
	string getName()const { return name; }
	string getCompany()const { return company; }
	Product() {
		name = "unknown";
		company = "unknown";
		price = 1;
		id = nextID++;
	}
	Product(const Product& product) {
		name = product.name;
		company = product.company;
		price = product.price;
		id = product.id;

	}
	Product operator=(const Product& product) {
		name = product.name;
		company = product.company;
		price = product.price;
		id = product.id;
		return *this;

	}
	friend ostream& operator<<(ostream& os, const Product& product) {
		os << "Product id:  " << product.id << endl;
		os << "Name: " << product.name << endl;
		os << "Company: " << product.company << endl;
		os << "Price: " << product.price << endl;
		return os;
	}
};
int Product::nextID = 0;

template <typename A>
class Node {
public:
	Node* next;
	Node* prev;
	A data;
	Node() {
		next = nullptr;
		prev = nullptr;
	}
	Node(A& data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

template <typename A>
class LinkedList {
	Node<A>* head;
	Node<A>* tail;
	int count;
public:
	LinkedList() :head(), tail() {
		count = 0;
	}
	void AddBegin(A& data) {
		auto nNode = new Node<A>(data);
		if (!head) {
			head = nNode;
			tail = nNode;
			return;
		}
		nNode->next = head;
		head->prev = nNode;
		head = nNode;
		count++;
	}
	void AddEnd(A& data) {
		auto nNode = new Node<A>(data);
		if (!head) {
			head = nNode;
			tail = nNode;
			return;
		}
		tail->next = nNode;
		nNode->prev = tail;
		tail = nNode;
		count++;
	}
	int getCount() {
		return count + 1;
	}
	void getAllNode(A*& arr) {
		Node<A>* temp = tail;
		int i = 0;
		arr[i] = tail->data; i++;
		while (temp->prev) {
			arr[i] = temp->prev->data;
			i++;
			temp = temp->prev;
		}
	}

	void UpdateData(A& data) {
		if (tail->data == data) {
			tail->data = data;
			return;
		}
		auto temp = head;
		while (temp->next) {
			if (temp->data == data) {
				temp->data = data;
				return;
			}
			temp = temp->next;
		}
		cout << "Not found!\n";
	}
	A getNodeByValue(A& data) {
		auto temp = head;
		while (temp->next) {
			if (temp->data = data)
				return temp;
			temp = temp->next;
		}
	}
	void DeleteBegin() {
		if (head) {
			head = head->next;
			head->prev = nullptr;
			count--;
			return;
		}
		cout << "List is Empty!\n";
	}
	void DeleteEnd() {
		if (head) {
			tail = tail->prev;
			tail->next = nullptr;
			count--;
			return;
		}
		cout << "List is Empty!\n";
	}
	void DeleteByValue(A data) {
		if (!head) {
			cout << "List is Empty!\n";
			return;
		}
		if (head->data == data) {
			DeleteBegin();
			return;
		}
		if (tail->data == data) {
			DeleteEnd();
			return;
		}
		auto temp = head;
		while (temp->next) {
			if (temp->next->data == data)
				break;
			temp = temp->next;
		}
		if (!temp->next) {
			cout << "Not found";
			return;
		}
		temp->next = temp->next->next;
		temp->next->prev = temp;
		count--;
	}
};

class Wagon {
	static int NextID;
	int id;
	static int speed;
	int produccount;
	string country;
	Stack<Product> product;
public:
	void setCountry(const string& country) {
		this->country = country;
	}
	void setSpeed(const int speed) {
		assert(speed >= 0, "Error\n");
		this->speed = speed;
	}
	void setProduct(Product& product) {
		this->product.Push(product);
		produccount++;
	}
	void setProduct(Stack<Product>& product, int size) {
		product = product;
		produccount = size;
	}
	int getSpeed() { return speed; }
	int getCount() { return produccount; }
	int getID() { return id; }
	string getCountry() { return country; }
	Stack<Product> getProduct() { return product; }
	Wagon() {
		Product t;
		t.setID(0);
		id = NextID++;
		produccount = 0;
		country = "unknown";
	}
	Wagon(const Wagon& wagon) {
		id = wagon.id;
		speed = wagon.speed;
		produccount = wagon.produccount;
		country = wagon.country;
		product = wagon.product;
	}
	Wagon& operator=(const Wagon& wagon) {
		id = wagon.id;
		speed = wagon.speed;
		produccount = wagon.produccount;
		country = wagon.country;
		product = wagon.product;
		return *this;
	}
	bool operator==(const Wagon& wagon) {
		return wagon.id == id;
	}
	friend ostream& operator<<(ostream& os, const Wagon& wagon) {
		os << wagon.id << "___________\nWagon id: 0" << wagon.id << endl;
		os << "Type of product: " << wagon.produccount << endl;
		os << "Country: " << wagon.country << endl;
		return os;
	}
};
int Wagon::NextID = 0;
int Wagon::speed = 110;
class Train {
	string TrainName;
	LinkedList<Wagon> wagons;
public:
	void setTrainName(string name) { TrainName = name; }
	string getTrainName() { return TrainName; }
	void addWagonBegin(Wagon& wagon) {
		wagons.AddBegin(wagon);
	}
	void addWagonEnd(Wagon& wagon) {
		wagons.AddEnd(wagon);
	}
	void deleteWagonByID(int id) {
		int index = -1;
		int count = wagons.getCount();
		Wagon* temp = new Wagon[count];
		wagons.getAllNode(temp);
		for (int i = 0; i < count; i++) {
			if (temp[i].getID() == id) {
				index = i;
				break;
			}
		}
		if (index >= 0) { wagons.DeleteByValue(temp[index]); }
		else cout << "ID not found!\n";
	}
	void updateSpeed(int speed) {
		int count = wagons.getCount();
		Wagon* temp = new Wagon[count];
		wagons.getAllNode(temp);
		temp[0].setSpeed(speed);
		wagons.UpdateData(temp[0]);
	}
	void updateCountryByID(int id, string country) {
		int index = -1;
		int count = wagons.getCount();
		Wagon* temp = new Wagon[count];
		wagons.getAllNode(temp);
		for (int i = 0; i < count; i++) {
			if (temp[i].getID() == id) {
				index = i;
				break;
			}
		}
		if (index >= 0) {
			temp[index].setCountry(country);
			wagons.UpdateData(temp[index]);
		}
		else cout << "ID not found!\n";
	}
	Wagon getWagonByID(int id) {
		int count = wagons.getCount();
		Wagon* temp = new Wagon[count];
		wagons.getAllNode(temp);
		for (int i = 0; i < count; i++) {
			if (temp[i].getID() == id) return temp[i];
		}
	}
	int getCount() {
		int count = wagons.getCount();
		return count;
	}
	void showProductsByID(int id) {
		Wagon wg = getWagonByID(id);
		Stack<Product> temp = wg.getProduct();
		while (!temp.isEmpty()) {
			cout << temp.Peak();
			cout << "\n\n";
			temp.Pop();
		}
		wg.setProduct(temp, 3);
		wagons.UpdateData(wg);
	}
	bool isIDTrue(int id) {
		int count = wagons.getCount();
		Wagon* temp = new Wagon[count];
		wagons.getAllNode(temp);
		for (int i = 0; i < count; i++) {
			if (temp[i].getID() == id) {
				return true;
				break;
			}
		}
		return false;
	}
	void printTrain() {
		int count = wagons.getCount();
		Wagon* temp = new Wagon[count];
		wagons.getAllNode(temp);
		cout << "Speed: " << temp[0].getSpeed() << endl;
		cout << "\n\n";
		for (int i = 0; i < count; i++) {
			cout << temp[i];
			cout << "\n\n";
		}
	}
};
void addData(Train& train) {
	int countWagon = 3;
	int countProduct = 3;
	Wagon* wagon = new Wagon[countWagon];
	wagon[0].setCountry("Azerbaijan");
	wagon[1].setCountry("Turkey");
	wagon[2].setCountry("Georgia");
	Product* product = new Product[countProduct];
	product[0].setCompany("ETI");
	product[0].setName("POPKEK");
	product[0].setPrice(2);

	product[1].setCompany("NORM");
	product[1].setName("Klass A");
	product[1].setPrice(25);

	product[2].setCompany("BEKO");
	product[2].setName("SmartTV w3356");
	product[2].setPrice(430);

	for (int i = 0; i < countWagon; i++) {
		for (int j = 0; j < countProduct; j++) {
			wagon[i].setProduct(product[j]);
		}
	}
	for (int i = 0; i < countWagon; i++) {
		train.addWagonBegin(wagon[i]);
	}
}

int cinReplacement() {
	int num = 0;
	int count = 0;
	while (true) {
		int index = _getch();
		if (index == 13 && count)break;
		if (index > 46 && index < 58) {
			if (count) {
				num *= 10;
			}
			index -= 48;
			num += index;
			count++;
			cout << index;
		}
	}
	return num;
}

int main() {
	Train train;
	train.setTrainName("KJ59");
	addData(train);
	int num = -1;
	while (true) {
		system("cls");
		if (num == -1) {
			cout << "Train Name: " << train.getTrainName() << endl;
			train.printTrain();
			cout << "Enter(wagon number): ";
			num = cinReplacement();
			system("cls");
		}
		if (train.isIDTrue(num)) {
			int id = num;
			cout << train.getWagonByID(id);
			cout << "Speed: " << train.getWagonByID(id).getSpeed() << endl;
			cout << "\n1. Products by Wagon\n2. Update Speed\n3. Update Country\n4. Delete Wagon\n5. Return\n\n ENTER(press count): ";
			num = cinReplacement();
			system("cls");
			if (num == 1) {
				train.showProductsByID(id);
				system("pause");
				num = -1;
			}
			else if (num == 2) {
				system("cls");
				cout << "Speed: ";
				num = cinReplacement();
				train.updateSpeed(num);
				num = id;
			}
			else if (num == 3) {
				system("cls");
				string country;
				cout << "Country: ";
				cin >> country;
				train.updateCountryByID(id, country);
				num = id;
			}
			else if (num == 4) {
				if (train.getCount() > 1)
					train.deleteWagonByID(id);
				else {
					cout << "The train cannot be deleted!\n";
					system("pause");
				};
				num = -1;
			}
			else if (num == 5) { num = -1; }
			else {
				system("cls");
				cout << "Wrong ID!\n";
				system("pause");
				num = id;
			}
		}
		else {
			system("cls");
			cout << "Wrong ID!\n";
			system("pause");
			num = -1;
		}
	}
}