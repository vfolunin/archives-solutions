#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
    string name, surname;
    int year;

    bool operator < (const Person &that) const {
        if (surname != that.surname)
            return surname < that.surname;
        if (name != that.name)
            return name < that.name;
        return year > that.year;
    }

    friend istream &operator >> (istream &in, Person &p) {
        return in >> p.name >> p.surname >> p.year;
    }

    friend ostream &operator << (ostream &out, Person &p) {
        return out << p.name << " " << p.surname << " " << p.year;
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

    for (Person &person : persons)
        cout << person << "\n";
}