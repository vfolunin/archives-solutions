#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
    string name;
    int height, weight;

    bool operator < (const Person &that) const {
        if (int dh = abs(height - 180), tdh = abs(that.height - 180); dh != tdh)
            return dh < tdh;
        if (weight < that.weight)
            return 75 < that.weight;
        if (weight > that.weight)
            return weight <= 75;
        return name < that.name;
    }

    friend istream &operator >> (istream &in, Person &p) {
        return in >> p.name >> p.height >> p.weight;
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
        cout << person.name << "\n";
}