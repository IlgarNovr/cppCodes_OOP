//class DoublyLinkedList {
//	Node* head;
//	Node* tail;
//public:
//	DoublyLinkedList() : head(), tail() {}
//
//	void AddBegin(const string&);
//	void AddBegin(const Node&);
//
//	void AddEnd(const string&);
//	void AddEnd(Node*&);
//
//
//	void AddBefore(const string&, const string&);
//	void AddBefore(const Node&, const string&);
//	void AddBefore(const Node&, const Node&);
//
//	void AddAfter(const string&, const string&);
//	void AddAfter(const Node&, const string&);
//	void AddAfter(const Node&, const Node&);
//
//	void DeleteBegin();
//	void DeleteEnd();
//	void DeleteByValue(const string&);
//
//	void ForwardTraverse();
//	void BackwardTraverse();
//};

#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	string data;
	Node* next;
	Node* prev;
	Node() :data(), next(), prev() {}
	Node(const string data) {
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};


class DoublyLinkedList {
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() :head(), tail() {}

	void AddBegin(const string&);
	void AddBegin(Node*&);

	void AddEnd(const string&);
	void AddEnd(Node*&);

	void AddBefore(const string&, const string&);
	void AddBefore(Node*&, const string&);
	void AddBefore(Node*&, Node*&);

	void AddAfter(const string&, const string&);
	void AddAfter(Node*&, const string&);
	void AddAfter(Node*&, Node*&);

	void DeleteBegin();
	void DeleteEnd();
	void DeleteByValue(const string&);

	void ForwardTraverse();
	void BackwardTraverse();
};

void DoublyLinkedList::AddBegin(const string& data) {
	auto newNode = new Node(data);
	if (!head) {
		head = newNode;
		tail = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}
void DoublyLinkedList::AddBegin(Node*& data) {
	if (!head) {
		head = data;
		tail = data;
		return;
	}
	data->next = head;
	head->prev = data;
	head = data;
}

void DoublyLinkedList::AddEnd(const string& data) {
	auto newNode = new Node(data);
	if (!head) {
		head = newNode;
		tail = newNode;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}
void DoublyLinkedList::AddEnd(Node*& node) {
	if (!head) {
		head = node;
		tail = node;
		return;
	}
	tail->next = node;
	node->prev = tail;
	tail = node;
}

void DoublyLinkedList::AddBefore(const string& x, const string& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (head->data == x) {
		AddBegin(data);
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->next->data == x)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "Not Found!!!\n";
		return;
	}
	auto newNode = new Node(data);
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
}
void DoublyLinkedList::AddBefore(Node*& node, const string& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (head == node) {
		AddBegin(data);
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->next == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "Not Found!!!\n";
		return;
	}
	auto newNode = new Node(data);
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
}
void DoublyLinkedList::AddBefore(Node*& node, Node*& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (head == node) {
		AddBegin(data);
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->next == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "Not Found!!!\n";
		return;
	}
	data->next = temp->next;
	data->prev = temp;
	temp->next->prev = data;
	temp->next = data;
}

void DoublyLinkedList::AddAfter(const string& x, const string& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (tail->data == x) {
		AddEnd(data);
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->data == x)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "Not Found!!!\n";
		return;
	}
	auto newNode = new Node(data);
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
}
void DoublyLinkedList::AddAfter(Node*& node, const string& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (tail == node) {
		AddEnd(data);
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "Not Found!!!\n";
		return;
	}
	auto newNode = new Node(data);
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
}
void DoublyLinkedList::AddAfter(Node*& node, Node*& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (tail == node) {
		AddEnd(data);
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "Not Found!!!\n";
		return;
	}
	data->next = temp->next;
	data->prev = temp;
	temp->next->prev = data;
	temp->next = data;
}

void DoublyLinkedList::DeleteBegin() {
	if (head) {
		head = head->next;
		head->prev = nullptr;
		return;
	}
	cout << "Is Empty!!!\n";
}
void DoublyLinkedList::DeleteEnd() {
	if (head) {
		tail = tail->prev;
		tail->next = nullptr;
		return;
	}
	cout << "Is Empty!!!\n";
}
void DoublyLinkedList::DeleteByValue(const string& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
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
		cout << "Data not found";
		return;
	}
	temp->next = temp->next->next;
	temp->next->prev = temp;
}

void DoublyLinkedList::ForwardTraverse() {
	auto temp = head;
	while (temp) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}
void DoublyLinkedList::BackwardTraverse() {
	auto temp = tail;
	while (temp) {
		cout << temp->data << endl;
		temp = temp->prev;
	}
}

int main() {
	DoublyLinkedList dlist;
	dlist.AddBegin("1");
	dlist.AddBegin("2");
	dlist.AddEnd("3");
	dlist.AddEnd("4");
	dlist.AddEnd("5");
	dlist.AddBegin("6");
	dlist.AddBegin("7");
	dlist.AddBegin("8");
	dlist.AddBefore("8", "A");
	dlist.AddAfter("1", "B");
	cout << "Forward:\n";
	dlist.ForwardTraverse();
	cout << "Backward:\n";
	dlist.BackwardTraverse();
}