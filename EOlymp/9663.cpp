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

    int sum = 0;
    for (Teacher &teacher : teachers)
        sum += teacher.salary;
    cout << sum << "\n";

    int mathSum = 0;
    for (Teacher &teacher : teachers)
        if (teacher.subject == "Math")
            mathSum += teacher.salary;
    cout << mathSum << "\n";

    cout << fixed << (double)sum / teachers.size() << "\n";

    int physicsSum = 0, physicsCount = 0;
    for (Teacher &teacher : teachers) {
        if (teacher.subject == "Physics") {
            physicsSum += teacher.salary;
            physicsCount++;
        }
    }
    cout << fixed << (double)physicsSum / physicsCount << "\n";
}