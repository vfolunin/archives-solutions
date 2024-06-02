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

    for (Teacher &teacher : teachers)
        cout << teacher << "\n";

    cout << teachers.size() << "\n";

    for (Teacher &teacher : teachers)
        if (teacher.subject == "Math")
            cout << teacher << "\n";

    cout << count_if(teachers.begin(), teachers.end(), [](Teacher &teacher) {
        return teacher.subject == "Physics";
    });
}