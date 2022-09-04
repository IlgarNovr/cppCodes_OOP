#include <iostream>
#include <conio.h>
using namespace std;
class Eded {
public:
    int suret;
    int mexrec;
    int tam;

    Eded(int s, int m) {
        suret = s;
        mexrec = m;
    }
    Eded() {
        suret = 0;
        mexrec = 0;
        tam = 0;
    }

    Eded Ixtisar(Eded Eded) {
        int k;
        if (Eded.suret >= Eded.mexrec) {
            k = Eded.suret;
        }
        else if (Eded.mexrec > Eded.suret) {
            k = Eded.mexrec;
        }

        for (int i = 1; i <= k; i++) {
            int s = Eded.suret;
            int m = Eded.mexrec;
            if (!(s % i) && !(m % i)) {
                Eded.suret /= i;
                Eded.mexrec /= i;
            }
        }

        if (Eded.suret > Eded.mexrec) {
            Eded.tam = Eded.suret / Eded.mexrec;
            Eded.suret = Eded.suret - Eded.mexrec * Eded.tam;

            if (Eded.suret % Eded.mexrec == 0) {
                Eded.mexrec = NULL;
                Eded.suret = NULL;
            }
        }
        return Eded;
    }

    Eded operator+(Eded k) {
        Eded temp;
        temp.suret = this->suret * k.mexrec + this->mexrec * k.suret;
        temp.mexrec = this->mexrec * k.mexrec;
        return Ixtisar(temp);
    }
    Eded operator-(Eded k) {
        Eded temp;
        temp.suret = this->suret * k.mexrec - this->mexrec * k.suret;
        temp.mexrec = this->mexrec * k.mexrec;
        return Ixtisar(temp);
    }
    Eded operator*(Eded k) {
        Eded temp;
        temp.suret = this->suret * k.suret;
        temp.mexrec = this->mexrec * k.mexrec;
        return Ixtisar(temp);
    }
    Eded operator/(Eded k) {
        Eded temp;
        temp.suret = this->suret * k.mexrec;
        temp.mexrec = this->mexrec * k.suret;
        return Ixtisar(temp);
    }

    ~Eded() {}
};

void cleanArr(char arr[]) {
    for (int i = 0; i < 5; i++)
    {
        arr[i] = ' ';
    }
}

int main() {
    while (true) {
        system("cls");
        int s, m, s1, m1;
        cout << "\n\t| Birinci eded:: ";
        cout << "\n\t| Suret: ";
        cin >> s;
        cout << "\t| Mexrec: ";
        cin >> m;
        if (!m) {
            system("cls");
            cout << "Mexrec sifir ola bilmez!\n";
            system("Pause");

            continue;
        }
        system("cls");
        cout << "\n\t| Ikinci eded: ";
        cout << "\n\t| Suret: ";
        cin >> s1;
        cout << "\t| Mexrec: ";
        cin >> m1;
        if (!m1) {
            system("cls");
            cout << "Mexrec sifir ola bilmez\n";
            system("Pause");
            continue;
        }
        system("cls");
        Eded x{ s,m };
        Eded y{ s1,m1 };
        Eded z;
        int arr[]{ 1,2,3,4,5 };
        enum key
        {
            UP = 72,
            DOWN = 80,
            ENTER = 13
        };
        char arr2[5]{ ' ',' ',' ',' ',' ' };
        int count = 5;
        char input = '_';
        int index = 0;

        while (true) {
            int j = 0;
            cout << "\t---------------------\n";
            for (int i = 0; i < 5; i++) {
                switch (arr[i]) {
                case 1:cout << "\t| 1. x + y " << arr2[j] << "\t    |\n";
                    j++;
                    break;
                case 2:cout << "\t| 2. x - y " << arr2[j] << "\t    |\n";
                    j++;
                    break;
                case 3:cout << "\t| 3. x * y  " << arr2[j] << "\t    |\n";
                    j++;
                    break;
                case 4:cout << "\t| 3. x : y " << arr2[j] << "\t    |\n";
                    j++;
                    break;
                case 5:cout << "\t| 5. Edit numbers " << arr2[j] << " |\n";
                    j++;
                    break;
                }
            }
            cout << "\t---------------------\n";

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
                cleanArr(arr2);
                arr2[index] = '<';
                system("cls");
            }
            else if (int(input) == ENTER) {
                system("cls");
                cout << "\n\n";
                if (index == 0) {
                    z = x + y;
                    cout << s << "/" << m << " + " << s1 << "/" << m1 << " = " << z.tam << "  " << z.suret << "/" << z.mexrec << endl;
                    system("Pause");
                    system("cls");
                }
                else if (index == 1) {
                    z = x - y;
                    cout << s << "/" << m << " - " << s1 << "/" << m1 << " = " << z.tam << "  " << z.suret << "/" << z.mexrec << endl;
                    system("Pause");
                    system("cls");
                }
                else if (index == 2) {
                    z = x * y;
                    cout << s << "/" << m << " * " << s1 << "/" << m1 << " = " << z.tam << "  " << z.suret << "/" << z.mexrec << endl;
                    system("Pause");
                    system("cls");
                }
                else if (index == 3) {
                    z = x / y;
                    cout << s << "/" << m << " : " << s1 << "/" << m1 << " = " << z.tam << "  " << z.suret << "/" << z.mexrec << endl;
                    system("Pause");
                    system("cls");
                }
                else {
                    break;
                }
            }
        }
    }
}