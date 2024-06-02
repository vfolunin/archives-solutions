#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Teacher {
    string surname, name, subject;
    int age, salary;

    friend istream &operator >> (istream &in, Teacher &t) {
        return in >> t.surname >> t.name >> t.age >> t.subject >> t.salary;
    }

    friend ostream &operator << (ostream &out, Teacher &t) {
        return out << t.surname << " " << t.name << " " << t.age << " " << t.subject << " " << t.salary;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Teacher> teachers;
    for (string type; cin >> type; )
        if (type == "Teacher")
            cin >> teachers.emplace_back();

    cout << *min_element(teachers.begin(), teachers.end(), [](Teacher &a, Teacher &b) {
        return a.age > b.age;
    }) << "\n";

    cout << *min_element(teachers.begin(), teachers.end(), [](Teacher &a, Teacher &b) {
        if (a.subject != b.subject)
            return a.subject == "Physics";
        return a.age > b.age;
    }) << "\n";

    cout << *min_element(teachers.begin(), teachers.end(), [](Teacher &a, Teacher &b) {
        return a.age < b.age;
    }) << "\n";

    cout << *min_element(teachers.begin(), teachers.end(), [](Teacher &a, Teacher &b) {
        if (a.subject != b.subject)
            return a.subject == "Math";
        return a.age < b.age;
    }) << "\n";
}