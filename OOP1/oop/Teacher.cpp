#include "Header.h"


//Print List
int printAllTch(const LinkedList& list,char* arr,int cho) {
    Teacher* temp = list.thead;
	int i = 0;
    while (temp) {
        cout << i + 1 << "." << temp->lname << " " << temp->fname << " " << temp->numOfClss << " " << arr[i] << endl; i++;
        temp = temp->next;
    }
    if (cho == 0) 
        cout << i + 1 << ".Add New Teacher " << arr[i] << endl; i++;
    cout << i + 1 << ".Return " << arr[i];
    return i;
}

int printGrpinTch(const LinkedList& list, int index, char* arr) {
    Teacher* temp = list.thead;
    for (int j = 0; j < index; j++) temp = temp->next;
    Group* tmp = temp->grp;
    int i = 0;
    while (tmp) {
        cout << i + 1 << "." << tmp->gName << " " << arr[i] << endl; i++;
        tmp = tmp->next;
    }
    cout << i + 1 << ".Return " << arr[i] << endl;
    return i;
}

void addTchr(LinkedList& list,string lname,string fname) {
	Teacher* temp = new Teacher;
	temp->next = NULL;
	temp->fname = fname;
	temp->lname = lname;
	if (!list.thead) {
		list.thead = temp;
	}
	else {
		Teacher* last = list.thead;
		while (last->next)last = last->next;
		last->next = temp;
	}
    list.tcnt++;
}

void addTchToGrp(LinkedList& list, int tchInd,int grpInd) {
	Group* grp = getGroup(list, grpInd);
	Teacher* tch = getTch(list, tchInd);
	tch->numOfClss++;
    grp->tcount++;
    Group* tmp = new Group;
    tmp->gName = grp->gName;
    tmp->next = tch->grp;
    tch->grp = tmp;
	Teacher* temp = new Teacher;
	temp->fname = tch->fname;
	temp->lname = tch->lname;
	temp->numOfClss = tch->numOfClss;
	temp->next = grp->tHead;
	grp->tHead = temp;
}
Group* getGroup(LinkedList& list, int index) {
	Group* temp = list.gHead;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}
Teacher* getTch(LinkedList& list, int index) {
	Teacher* temp = list.thead;
	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	return temp;
}
int selectTch(LinkedList& list,int cho) {
    int a = 2;
    if (cho)a = 1;
    int count = list.tcnt + a;
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
        count = 1 + printAllTch(list, arrowAr, cho);
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
            if (cho == 0) {
                if (index == count - 2) {
                    string fname, lname;
                    cout << "Teacher name: ";
                    cin >> fname;
                    cout << "Teacher surname: ";
                    cin >> lname;
                    addTchr(list, lname, fname);
                }
                else if (index == count - 1)  return -1;
                else {
                    return index;
                }
            }
            else {
                if (index == count - 1)return -1;
                else return index;
            }
            system("cls");
        }
        else system("cls");
    }
    return 0;
}