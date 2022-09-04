#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Student {
public:
	string fname;
	string lname;
	float avPoint = 0;
	int point = 0;
	int count = 0;
	Student* next;
};
class Group;
class Teacher {
public:
	string fname;
	string lname;
	int numOfClss = 0;
	Group* grp = nullptr;
	Teacher* next;
};

class Group {
public:
	string gName;
	Teacher* tHead =nullptr;
	Student* sHead=nullptr;
	Group* next;
	int tcount = 0;
	int scount = 0;
};

class LinkedList {
public:
	Group* gHead = nullptr;
	Teacher* thead = nullptr;
	int gcount = 0;
	int tcnt = 0;
};

//Group
void cleanArr(char* arr, int num);
int selectList();
void addGroup(LinkedList& list, string name);
void printGroup(const LinkedList& list, char* arr);
int selectGroup(LinkedList& list);
int showGroup(LinkedList& list, int ind);
//Teacher
void addTchr(LinkedList& list, string fname, string lname);
void addTchToGrp(LinkedList& list, int tchInd, int grpInd);
int printAllTch(const LinkedList& list, char* arr,int cho);
Group* getGroup(LinkedList& list, int index);
Teacher* getTch(LinkedList& list, int index);
int selectTch(LinkedList& list,int cho);
int printGrpinTch(const LinkedList& list, int index, char* arr);

//Student
int printStudent(const LinkedList& list, int index, char* arr);
void addStudent(LinkedList& list, string fname, string lname, int index);
int selectStudent(LinkedList& list, int ind);
void addPoint(LinkedList& list, int index,int ind);