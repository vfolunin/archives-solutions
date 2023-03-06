#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
    string name, surname;
    int day, month, year;

    bool operator < (const Person &that) const {
        if (year != that.year)
            return year < that.year;
        if (month != that.month)
            return month < that.month;
        return day < that.day;
    }

    bool operator == (const Person &that) const {
        return year == that.year && month == that.month && day == that.day;
    }
};

istream &operator >> (istream &in, Person &p) {
    char dot;
    return in >> p.name >> p.surname >> p.day >> dot >> p.month >> dot >> p.year;
}

ostream &operator << (ostream &out, Person &p) {
    out << p.name << " " << p.surname << " ";
    out << setw(2) << setfill('0') << p.day << ".";
    out << setw(2) << setfill('0') << p.month << ".";
    return out << p.year;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<Person> persons(size);
    for (Person &person : persons)
        cin >> person;

    Person oldest = *min_element(persons.begin(), persons.end());
    int oldestCount = count(persons.begin(), persons.end(), oldest);

    if (oldestCount == 1)
        cout << oldest;
    else
        cout << oldestCount;
}