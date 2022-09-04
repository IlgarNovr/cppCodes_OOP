#include "Header.h"

int printStudent(const LinkedList& list, int index, char* arr) {
	Group* group = list.gHead;
	for (int i = 0; i < index; i++) {
		group = group->next;
	}
	int i = 0;
	Student* temp = group->sHead;
    cout << "Student:\n";
	while (temp) {
		cout << i + 1 << "." << temp->lname << " " << temp->fname << " " << temp->avPoint << " " << arr[i] << endl; i++;
		temp = temp->next;
	}
	cout << i + 1 << ".Add new Student " << arr[i] << endl; i++;
    cout << i + 1 << ".Add new Teacher " << arr[i] << endl; i++;
    cout << i + 1 << ".Return " << arr[i] << endl;
     cout << "\nTeacher:\n";
   Teacher* tmp = group->tHead;
   int j = 1;
    while (tmp) {
        cout << j << "." << tmp->lname << " " << tmp->fname << " " << endl; j++;
        tmp = tmp->next;
    }
    return i;
}
void addStudent(LinkedList& list,string lname,string fname,int index) {
	Group* group = list.gHead;
	for (int i = 0; i < index; i++) {
		group = group->next;
	}
	Student* temp = new Student;
	temp->next = NULL;
    temp->fname = fname;
    temp->lname = lname;
    if (!group->sHead) {
        group->sHead = temp;
    }
    else {
        Student* last = group->sHead;
        while (last->next)last = last->next;
        last->next = temp;
    }
	group->scount++;
}
int selectStudent(LinkedList& list, int ind) {
    int count = list.gHead->scount + 3;
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
       count = 1 + printStudent(list,ind, arrowAr);
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
            if (index == count - 3) {//Add new student
                Sleep(500);
                string fname, lname;
                cout << "Student first name: ";
                cin >> fname;
                cout << "Student last name: ";
                cin >> lname;
                addStudent(list,lname, fname, ind);
                count++;
            }
            else if (index == count - 2) {//Add new teacher
                system("cls");
                int in = selectTch(list, 1);
                if(in >=0)
                addTchToGrp(list, in, ind);
            }
            else if (index == count - 1)  return -2;//Return           
            else addPoint(list, index,ind);//Add Point
            system("cls");
        }
        else system("cls");
    }
}
void addPoint(LinkedList& list, int index,int ind) {
    Group* grp = list.gHead;
    for (int j = 0; j < ind; j++) grp = grp->next;
    int num;
    Student* tmp = grp->sHead;
    for (int j = 0; j < index; j++) tmp = tmp->next;
    while (true) {
        cout << "Return '0'\n";
        cout << "Student: " << tmp->fname << " " << tmp->lname << endl;
        cout << "Add point(1-12): ";
        cin >> num;
        if (num > 0 && num < 13) {
            break;
        }
        else if (num == 0)return;
        else {
            system("cls");
            cout << "Wrong number";
            Sleep(500);
        }
        system("cls");
    }
    tmp->count++;
    tmp->point += num;
    tmp->avPoint = float(tmp->point) / tmp->count;
}