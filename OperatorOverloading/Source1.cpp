//Student age, score, name, bonus(min = 0)
//(<, >, <= , >= , != , == )
//.Increment, decrement elave edin(posfix ve prefix).
//bu emeliyyatlar telebebin bonusuna tesir elesin.minimum bonus 0 dir
//, eger bonus 0 sa decrement olsa sabit 0 qalsin.

#include <iostream>
#include <Windows.h>
#include <assert.h>
using namespace std;

class Student {
private:
    string name;
    int age;
    int score;
    int bonus;
public:
    void setName(string name) {
        this->name = name;
    }
    void setAge(int age) {
        assert(age >= 18, "ERROR -18");
        this->age = age;
    }
    void setScore(int score) {
        assert(score > -1 && score < 13, "ERROR Score");
        this->score = score;
    }
    void setBonus(int bonus) {
        assert(bonus > -1, "ERROR Bonus");
        this->bonus = bonus;
    }
    string getName()const {
        return name;
    }
    int getAge()const {
        return age;
    }
    int getScore()const {
        return score;
    }
    int getBonus()const {
        return bonus;
    }


    int operator++(int) {
        return bonus++;
    }
    int operator++() {
        return bonus++;
    }
    int operator--(int) {
        bonus--;
        if (bonus == -1) {
            bonus = 0;
        }
        return bonus;
    }
    int operator--() {
        bonus--;
        if (bonus == -1) {
            bonus = 0;
        }
        return bonus;
    }
    bool operator<(const Student& person) {
        if (score < person.score) {
            return true;
        }
        return false;
    }
    bool operator<=(const Student& person) {
        if (score <= person.score) {
            return true;
        }
        return false;
    }
    bool operator>(const Student& person) {
        if (score > person.score) {
            return true;
        }
        return false;
    }

    bool operator>=(const Student& person) {
        if (score >= person.score) {
            return true;
        }
        return false;
    }
    bool operator==(const Student& person) {
        if (score == person.score) {
            return true;
        }
        return false;
    }
    bool operator!=(const Student& person) {
        if (score != person.score) {
            return true;
        }
        return false;
    }
    Student() {
        age = 18;
        score = 0;
        bonus = 0;
        name = "Filankes";
    }
    Student(int age, int score, int bonus, string name) {
        setAge(age);
        setScore(score);
        setBonus(bonus);
        setName(name);
    }
    Student(const Student& st) {
        setAge(st.age);
        setScore(st.score);
        setBonus(st.bonus);
        setName(st.name);
    }
    Student& operator=(const Student& st) {
        setAge(st.age);
        setScore(st.score);
        setBonus(st.bonus);
        setName(st.name);
    }
};

int main() {
    Student person;
    person.setScore(1);
    cout << "Bonus: " << person.getBonus() << endl;
    person--;//bonus 0 olduqda deyismir
    cout << "Decrement: " << person.getBonus() << endl;
    person++;
    cout << "Increment: " << person.getBonus() << endl;
}