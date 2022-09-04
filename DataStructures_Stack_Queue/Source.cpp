#include <assert.h>
#include <iostream>
#include <string>
using namespace std;
template<typename T>
#define MAX 5

class Queue {
	T* arr;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue() {
		arr = new T[MAX];
		capacity = MAX;
		front = 0;
		rear = -1;
		count = 0;
	}
	void Enqueue(T value) {
		arr[++rear] = value;
		count++;
	}
	void Dequeue() {
		T* temp = new T[capacity];
		for (int i = 0; i < capacity - 1; i++) { temp[i] = arr[i + 1]; }
		delete[] arr;
		arr = temp;
		temp = nullptr;
		count--;
		rear--;
	}

	T Peak() { return arr[front]; }
	bool isEmpty()const { return count == 0; }
	bool isFull()const { return count == capacity; }
	~Queue() { delete[] arr; }
};
class Worker {
	string name;
	string surname;
	int age;
	int pageCount;
public:
	void setName(string name) { this->name = name; }
	void setSurname(string surname) { this->surname = surname; }
	void setAge(int age) {
		assert(age > 0, "ERROR");
		this->age = age;
	}
	void setPage(int page) {
		assert(page > 0, "ERROR");
		this->pageCount = page;
	}

	string getName() { return name; }
	string getSurname() { return surname; }
	int getAge() { return age; }
	int getPage() { return pageCount; }

	Worker() {
		name = "-";
		surname = "-";
		age = 1;
		pageCount = 1;
	}
};
class Printer {
	Queue<Worker> workerQueue;
public:
	void addPrint(Worker& worker) { workerQueue.Enqueue(worker); }
	void start() {
		while (!workerQueue.isEmpty()) {
			int page = workerQueue.Peak().getPage();
			while (page) {
				cout << workerQueue.Peak().getName() << " " << workerQueue.Peak().getSurname() << " " << page-- << " files printing\n";
			}
			workerQueue.Dequeue();
		}
		cout << "All file printed successfully.";
	}
};

void main() {
	Printer printer;
	Worker worker;
	worker.setAge(45);
	worker.setName("Qabil");
	worker.setSurname("Memmedov");
	worker.setPage(5);
	printer.addPrint(worker);
	printer.start();
}