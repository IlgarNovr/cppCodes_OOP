#include "Header.h"

void addGroup(LinkedList& list, string name) {
    Group* temp = new Group;
    temp->next = NULL;
    temp->gName = name;
    if (!list.gHead) {
        list.gHead = temp;
    }
    else {
        Group* last = list.gHead;
        while (last->next) last = last->next;
        last->next = temp;
    }
    list.gcount++;
}
void printGroup(const LinkedList& list,char* arr) {
    Group* temp = list.gHead;
    int i = 0;
    while (temp) {
        cout << i + 1 << "." << temp->gName << " " << arr[i] << endl; i++;
        temp = temp->next;
    }
    cout << i + 1 << ".Add new group " << arr[i] << endl; i++;
    cout << i + 1 << ".Return " << arr[i] << endl; 
    
}
void cleanArr(char* arr, int num) {
    for (int i = 0; i < num; i++)
    {
        arr[i] = ' ';
    }
}
int selectList() {
    char input = '_';
    int index = 0;
    char arrowAr[2]{ '<' };
    int j = 0;
    enum key
    {
        ENTER = 13,
        UP = 72,
        DOWN = 80
    };
    while (true) {
        j = 0;
        cout << "Groups " << arrowAr[j] << endl; j++;
        cout << "Teacher " << arrowAr[j] << endl;
        input = _getch();
        if (int(input) == -32) {
            input = _getch();
            if (int(input) == UP) {
                index--;
                if (index == -1) {
                    index = 1;
                }
            }
            else if (int(input) == DOWN) {
                index++;
                if (index == 2) {
                    index = 0;
                }
            }
            cleanArr(arrowAr, 2);
            arrowAr[index] = '<';
            system("cls");
        }
        else if (int(input) == ENTER) {
            system("cls");
            return index;
        }
        else system("cls");

    }
}
int selectGroup(LinkedList& list) {
    int count = list.gcount + 2;
    char input = '_';
    int index = 0;
    char* arrowAr = new char[count] {'<'};
    enum key
    {
        ENTER = 13,
        UP = 72,
        DOWN = 80
    };
    while (true) {
        printGroup(list, arrowAr);
        input = _getch();
        if (int(input) == -32) {
            input = _getch();
            if (int(input) == UP) {
                index--;
                if (index == -1) {
                    index = count-1;
                }
            }
            else if (int(input) == DOWN) {
                index++;
                if (index == count) {
                    index = 0;
                }
            }
            cleanArr(arrowAr, count);
            arrowAr[index] = '<';
            system("cls");
        }
        else if (int(input) == ENTER) {
            system("cls");
            if (index == count - 2) {
                string name;
                cout << "Group name: ";
                cin >> name;
                addGroup(list, name);
                count++;
                system("cls");
            }
            else if (index == count - 1) return -1;
            else return index;
        }
        else system("cls");
    }
}
int showGroup(LinkedList& list, int ind) {
    int count = list.gHead->tcount + 1;
    char input = '_';
    int index = 0;
    char* arrowAr = new char[count] {'<'};
    enum key
    {
        ENTER = 13,
        UP = 72,
        DOWN = 80
    };
    while (true) {
        count = 1 + printGrpinTch(list, ind, arrowAr);
        input = _getch();
        if (int(input) == -32) {
            input = _getch();
            if (int(input) == UP) {
                index--;
                if (index == -1) {
                    index = count - 1;
                }
            }
            else if (int(input) == DOWN) {
                index++;
                if (index == count) {
                    index = 0;
                }
            }
            cleanArr(arrowAr, count);
            arrowAr[index] = '<';
            system("cls");
        }
        else if (int(input) == ENTER) {
            system("cls");
            if (index == count - 1)  return -3;
            else addPoint(list, index, ind);
            system("cls");
        }
        else system("cls");
    }
}