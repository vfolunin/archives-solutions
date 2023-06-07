#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Person {
    string surname, name;
    int score;

    bool operator < (const Person &that) const {
        return surname < that.surname;
    }

    friend istream &operator >> (istream &in, Person &p) {
        return in >> p.surname >> p.name >> p.score;
    }

    friend ostream &operator << (ostream &out, Person &p) {
        return out << p.name[0] << ". " << p.surname;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int threshold;
    cin >> threshold;

    vector<Person> persons;
    for (Person person; cin >> person; )
        if (person.score > threshold)
            persons.push_back(person);

    sort(persons.begin(), persons.end());

    cout << persons.size() << "\n";
    for (int i = 0; i < persons.size(); i++)
        cout << i + 1 << ") " << persons[i] << "\n";
}