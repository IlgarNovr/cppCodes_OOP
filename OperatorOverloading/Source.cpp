//1. Time class yaradin(saat ve deqiqe fieldleri olsun)</
//2. Increment, decrement elave edin(posfix ve prefix).</
//Increment ve decrement ilk novbede deqiqelere tesir edir</
//3. Time obyektlerini muqayise etmek uchun novbeti operatorlari</
//overload edin(<, >, <= , >= , != , == )
//4. Emeliyyatlarin neticesini cap edin

#include <iostream>
#include <Windows.h>
#include <assert.h>
using namespace std;
class Time {
private:
    int saat;
    int deqiqe;
    int saniye;
public:
    void SetSaat(const int hour) {
        assert(hour > -1 && hour < 24, "ERROR404\n");
        saat = hour;
    }
    void SetDeqiqe(const int min) {
        assert(min > -1 && min < 60, "ERROR404\n");
        deqiqe = min;
    }
    void SetSaniye(const int sec) {
        assert(sec > -1 && sec < 60, "ERROR404\n");
        saniye = sec;
    }
    int GetSaat() const {
        return saat;
    }
    int GetDeqiqe() const {
        return deqiqe;
    }
    int GetSainye() const {
        return saniye;
    }
    //With parametr
    Time& operator++(int) {
        saniye++;
        if (saniye == 60) {
            saniye = 0;
            deqiqe++;
        }
        if (deqiqe == 60) {
            deqiqe = 0;
            saat++;
        }
        if (saat == 24) {
            saniye = 0;
            deqiqe = 0;
            saat = 0;
        }
        return *this;
    }
    Time& operator--(int) {
        saniye--;
        if (saniye == -1) {
            saniye = 59;
            deqiqe--;
        }
        if (deqiqe == -1) {
            deqiqe = 59;
            saat--;
        }
        if (saat == -1) {
            saniye = 59;
            deqiqe = 59;
            saat = 23;
        }
        return *this;
    }
    //Default
    Time& operator++() {
        saniye++;
        if (saniye == 60) {
            saniye = 0;
            deqiqe++;
        }
        if (deqiqe == 60) {
            deqiqe = 0;
            saat++;
        }
        if (saat == 24) {
            saniye = 0;
            deqiqe = 0;
            saat = 0;
        }
        return *this;
    }
    Time& operator--() {
        saniye--;
        if (saniye == -1) {
            saniye = 59;
            deqiqe--;
        }
        if (deqiqe == -1) {
            deqiqe = 59;
            saat--;
        }
        if (saat == -1) {
            saniye = 59;
            deqiqe = 59;
            saat = 23;
        }
        return *this;
    }
    //<
    bool operator<(const Time& time) {
        int sum = saat * 3600 + deqiqe * 60 + saniye;
        int sum2 = time.saat * 3600 + time.deqiqe * 60 + time.saniye;
        if (sum < sum2) {
            return true;
        }
        return false;
    }
    //<=
    bool operator<=(const Time& time) {
        int sum = saat * 3600 + deqiqe * 60 + saniye;
        int sum2 = time.saat * 3600 + time.deqiqe * 60 + time.saniye;
        if (sum < sum2) {
            return true;
        }
        return false;
    }
    //>
    bool operator>(const Time& time) {
        int sum = saat * 3600 + deqiqe * 60 + saniye;
        int sum2 = time.saat * 3600 + time.deqiqe * 60 + time.saniye;
        if (sum > sum2) {
            return true;
        }
        return false;
    }
    //>=
    bool operator>=(const Time& time) {
        int sum = saat * 3600 + deqiqe * 60 + saniye;
        int sum2 = time.saat * 3600 + time.deqiqe * 60 + time.saniye;
        if (sum > sum2) {
            return true;
        }
        return false;
    }
    //==
    bool operator==(const Time& time) {
        int sum = saat * 3600 + deqiqe * 60 + saniye;
        int sum2 = time.saat * 3600 + time.deqiqe * 60 + time.saniye;
        if (sum == sum2) {
            return true;
        }
        return false;
    }
    //!=
    bool operator!=(const Time& time) {
        int sum = saat * 3600 + deqiqe * 60 + saniye;
        int sum2 = time.saat * 3600 + time.deqiqe * 60 + time.saniye;
        if (sum != sum2) {
            return true;
        }
        return false;
    }

    Time() {
        saat = 0;
        deqiqe = 0;
        saniye = 0;
    }
    Time(int hour, int min, int sec) {
        SetSaat(hour);
        SetDeqiqe(min);
        SetSaniye(sec);
    }
    Time(const Time& time) {
        SetSaat(time.saat);
        SetDeqiqe(time.deqiqe);
        SetSaniye(time.saniye);
    }

    friend ostream& operator<<(ostream& zero, const Time& time)
    {
        if (time.saat <= 9) {
            zero << 0;
        }
        zero << time.saat << ":";
        if (time.deqiqe <= 9) {
            zero << 0;
        }
        zero << time.deqiqe << ":";
        if (time.saniye <= 9) {
            zero << 0;
        }
        zero << time.saniye;
        return zero;
    }
};
int main() {
    Time incretime, decretime;
    incretime.SetSaniye(0);
    incretime.SetDeqiqe(0);
    incretime.SetSaat(0);
    decretime.SetSaniye(0);
    decretime.SetDeqiqe(0);
    decretime.SetSaat(0);
    while (true) {
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t/------------\\\n";
        cout << "\t\t\t\t\t\t\t|  " << incretime << "  |\n";
        cout << "\t\t\t\t\t\t\t|  " << decretime << "  |\n";
        cout << "\t\t\t\t\t\t\t\\------------/";
        incretime--;
        decretime++;
        Sleep(1000);
        system("cls");
    }
}

