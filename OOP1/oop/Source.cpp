#include <iostream>
#include "Header.h"
#include <Windows.h>

using namespace std;

int main() {
	LinkedList list;
	int index = 0;
	while (true) {
		if (index > -2)
			index = selectList();
		system("cls");
		if (index == 0|| index == -2) {
			index = selectGroup(list);
			system("cls");
			if (index < 0) continue;
			index = selectStudent(list, index);
		}
		else {
			index = selectTch(list,0);
			system("cls");
			if (index < 0) continue;
			index = showGroup(list, index);
		}
	}
}