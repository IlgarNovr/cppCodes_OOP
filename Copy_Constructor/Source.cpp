#include <iostream>
#include<string.h>
using namespace std;

class String {
public:
	char* str;
	int len;

	String(char* s) {
		this->str = s;
		for (len = 0; str[len] != '\0';)
		{
			len++;
		}
	}

	void Append(String s) {
		int a = len + s.len + 1;
		char* temp = new char[a];
		for (int i = 0; i < this->len; i++)
		{
			temp[i] = str[i];
		}
		int d = 0;
		for (int j = this->len; j < a; j++)
		{
			temp[j] = s.str[d];
			d++;
		}
		delete[] str;
		this->str = temp;
		this->len = a;
	}

	void Insert(int index, String s) {
		int a = len + s.len + 1;
		char* temp = new char[a];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = str[i];
		}
		int d = 0;
		for (size_t i = index; i < index + s.len; i++)
		{
			temp[i] = s.str[d];
			d++;
		}
		for (size_t i = index + s.len; i < a; i++)
		{
			temp[i] = str[index];
			index++;
		}
		delete[] str;
		this->str = temp;
		this->len = a;
	}

	int Lenght() {
		return len;
	}

	void Clear() {
		delete[] str;
		str = nullptr;
		len = NULL;;
	}

	int FindFirst(char a) {
		int index = 0;
		for (size_t index = 0; index < len + 1; index++)
		{
			if (str[index] == a) {
				return index;
				break;
			}
		}
	}

	int FindLast(char a) {
		int index = 0;
		for (size_t index = len; index > 0; index--)
		{
			if (str[index] == a) {
				return index;
				break;
			}
		}
	}

	char* operator+(String s) {
		int a = len + s.len + 1;
		char* temp = new char[a];
		for (int i = 0; i < this->len; i++)
		{
			temp[i] = str[i];
		}
		int d = 0;
		for (int j = this->len; j < a; j++)
		{
			temp[j] = s.str[d];
			d++;
		}
		return temp;
	}

	char* operator+=(String s) {
		int a = len + s.len + 1;
		char* temp = new char[a];
		for (int i = 0; i < this->len; i++)
		{
			temp[i] = str[i];
		}
		int d = 0;
		for (int j = this->len; j < a; j++)
		{
			temp[j] = s.str[d];
			d++;
		}
		delete[] str;
		this->str = temp;
		this->len = a;
		return temp;
	}

	char* operator=(String s) {
		delete[] str;
		this->str = s.str;
		this->len = s.len;;
		return s.str;
	}

	String() {
		str = nullptr;
		len = 0;
	};

	~String() {};
};

void main() {
	String st(new char[6]{ "Salam" });
	String st2(new char[8]{ "Necesen" });

	//Append
	//st.Append(st2);
	//cout << st.str << endl;

	//Insert
	//st.Insert(2,st2);
	//cout << st.str << endl;

	//Lenght
	//cout << st.Lenght() << endl;

	//Clear
	//st.Clear();

	//FindFirst
	//cout << st.FindFirst('a') << endl;

	//FindLast
	//cout << st.FindLast('a') << endl;

	//Operator+
	//cout << st + st2 << endl;

	//Operator+=
	//st += st2;
	//cout << st.str << endl;


	//Operator=
	//st=st2;
	//cout << st.str << endl;
}