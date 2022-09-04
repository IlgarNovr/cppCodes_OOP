#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	~Node() {
		delete next;
	}
};

class LinkedList {
	Node* head;
	int count;
public:
	LinkedList() {
		head = NULL;
		count = 0;
	}
	~LinkedList() {
		delete head;
	}
	int getCount()const {
		return count;
	}
	//ADD
	void addFront(int data) {
		Node* temp = new Node();
		temp->data = data;
		temp->next = head;
		head = temp;
		temp = nullptr;
		count++;
	}
	void addBack(int data) {
		Node* temp = new Node;
		temp->data = data;
		if (!head) {
			head = temp;
		}
		else {
			Node* last = new Node;
			last = head;
			while (last->next) last = last->next;
			last->next = temp;
		}
		temp = nullptr;
		count++;
	}
	//FIND
	Node* findIndex(int index) {
		Node* temp = head;
		for (int i = 0; i < index; i++) { temp = temp->next; }
		return temp;
	}
	//DELETE
	void deleteFirst() {
		if (count > 0) {
			head = head->next;
			count--;
		}
		else {
			cout << "Is empty!\n";
		}
	}
	void deleteLast() {
		if (count > 0) {
			Node* temp = new Node;
			temp = head;
			while (temp->next->next)temp = temp->next;
			delete(temp->next);
			temp->next = NULL;
			count--;
		}
		else {
			cout << "Is empty!\n";
		}
	}
	void deleteIndex(int index) {
		if (count > 0) {
			if (index < count && index> 0) {
				Node* temp = head;
				Node* temp1;
				for (int i = 0; i < index - 1; i++) { temp = temp->next; }
				temp1 = temp->next;
				temp->next = temp1->next;
			}
			else if (index == 0) { deleteFirst(); }
			else {
				cout << "Error!!!\n";
			}
		}
		else {
			cout << "Error!!!\n";
		}
	}
	//PRINT
	void print() {
		if (count > 0) {
			Node* temp = new Node();
			temp = head;
			while (temp) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
			temp = nullptr;
		}
	}
};
int main() {
	LinkedList list;
	cout << "Add front : ";
	list.addFront(1);
	list.addFront(2);
	list.print();
	cout << "Add back : ";
	list.addBack(9);
	list.addBack(8);
	list.print();
	cout << "Find index : ";
	cout << list.findIndex(1)->data;
	cout << "\nDelete first : ";
	list.deleteFirst();
	list.print();
	cout << "Delete last : ";
	list.deleteLast();
	list.print();
	cout << "Delete index : ";
	list.deleteIndex(0);
	list.print();
}