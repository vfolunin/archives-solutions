#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
    string name;
    int day, month, year;

    bool operator < (const Person &that) {
        if (year != that.year)
            return year < that.year;
        if (month != that.month)
            return month < that.month;
        return day < that.day;
    }

    friend istream &operator >> (istream &in, Person &p) {
        return in >> p.name >> p.day >> p.month >> p.year;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int personCount;
    cin >> personCount;

    vector<Person> persons(personCount);
    for (Person &person : persons)
        cin >> person;

    sort(persons.begin(), persons.end());

    cout << persons.back().name << "\n" << persons.front().name;
}