//class SinglyLinkedList {
//	Node* head;
//public:
//	SinglyLinkedList() : head() {}
//
//	void AddBegin(const string&);
//	void AddBegin(const Node&);
//
//	void AddEnd(const string&);
//	void AddEnd(const Node&);
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
//	void Traverse();
//};


#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	string data;
	Node* next;
	Node() :data(), next() {}
	Node(const string data) {
		this->data = data;
		this->next = nullptr;
	}

};

class SinglyLinkedList {
	Node* head;
public:
	SinglyLinkedList() :head() {}
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

	void Traverse();
};


void SinglyLinkedList::AddBegin(const string& data) {
	auto newNode = new Node(data);
	newNode->next = head;
	head = newNode;
}
void SinglyLinkedList::AddBegin(Node*& node) {
	node->next = head;
	head = node;
}

void SinglyLinkedList::AddEnd(const string& data) {
	auto newNode = new Node(data);
	if (!head) {
		head = newNode;
		return;
	}
	auto temp = head;
	while (temp->next != NULL)temp = temp->next;
	temp->next = newNode;
}
void SinglyLinkedList::AddEnd(Node*& node) {
	if (!head) {
		head = node;
		return;
	}
	auto temp = head;
	while (temp->next) temp = temp->next;
	temp->next = node;
}

void SinglyLinkedList::AddBefore(const string& x, const string& data) {
	if (!head) {
		cout << "\nIs Empty!!!\n";
		return;
	}
	if (head->data == x) {
		auto newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->next->data == x)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "\nNot Found!!!\n";
	}
	else {
		auto newNode = new Node(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
void SinglyLinkedList::AddBefore(Node*& node, const string& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (head == node) {
		auto temp = new Node(data);
		temp->next = head;
		head = temp;
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->next == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "\nNot Found!!!\n";
	}
	else {
		auto newNode = new Node(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}
void SinglyLinkedList::AddBefore(Node*& node, Node*& data) {
	if (!head) {
		cout << "Is Empty!!!\n";
		return;
	}
	if (head == node) {
		data->next = head;
		head = data;
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->next == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		cout << "\nNot Found!!!\n";
	}
	else {
		data->next = temp->next;
		temp->next = data;
	}
}

void SinglyLinkedList::AddAfter(const string& x, const string& data) {
	if (!head) {
		cout << "\nIs Empty!!!\n";
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp->data == x)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		if (temp->data == x) {
			AddEnd(data);
			return;
		}
		cout << "\nNot Found!!!\n";
		return;
	}
	else {
		auto newNode = new Node(data);
		auto temp1 = temp->next;
		temp->next = newNode;
		newNode->next = temp1;
	}
}
void SinglyLinkedList::AddAfter(Node*& node, const string& data) {
	if (!head) {
		cout << "\nLinkedIs Empty!!!\n";
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		if (temp == node) {
			AddEnd(data);
			return;
		}
		cout << "\nNot Found!!!\n";
		return;
	}
	else {
		auto newNode = new Node(data);
		auto temp1 = temp->next;
		temp->next = newNode;
		newNode->next = temp1;
	}
}
void SinglyLinkedList::AddAfter(Node*& node, Node*& data) {
	if (!head) {
		cout << "\nLinkedIs Empty!!!\n";
		return;
	}
	auto temp = head;
	while (temp->next) {
		if (temp == node)
			break;
		temp = temp->next;
	}
	if (!temp->next) {
		if (temp == node) {
			AddEnd(data);
			return;
		}
		cout << "\nNot Found!!!\n";
		return;
	}
	else {
		auto temp1 = temp->next;
		temp->next = data;
		data->next = temp1;
	}
}

void SinglyLinkedList::DeleteBegin() {
	if (head) {
		head = head->next;
		return;
	}
	cout << "Is Empty!!!!\n";
}
void SinglyLinkedList::DeleteEnd() {
	if (head) {
		auto temp = head;
		while (temp->next->next)temp = temp->next;
		delete(temp->next);
		temp->next = NULL;
		return;
	}
	cout << "Is Empty!!!!\n";
}
void SinglyLinkedList::DeleteByValue(const string& data) {
	if (head) {
		if (head->data == data) {
			DeleteBegin();
			return;
		}
		auto temp = head;
		while (temp->next) {
			if (temp->next->data == data)
				break;
			temp = temp->next;
		}
		if (!temp->next) {
			cout << "Not Found!!\n";
			return;
		}
		auto temp1 = temp->next;
		temp->next = temp1->next;
	}
}

void SinglyLinkedList::Traverse() {
	auto temp = head;
	while (temp) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main() {
	SinglyLinkedList list;
	list.AddBegin("A");
	list.AddBegin("B");
	list.AddBegin("c");
	list.AddBegin("d");
	list.AddEnd("E");
	list.AddEnd("F");
	list.AddEnd("G");
	list.AddAfter("A", "1");
	list.AddBefore("B", "2");
	list.Traverse();
}
