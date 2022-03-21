#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int studentCount;
    cin >> studentCount;

    map<string, set<string>> courses;
    for (int i = 0; i < studentCount; i++) {
        string name, surname, course;
        cin >> name >> surname >> course;
        courses[course].insert(name + " " + surname);
    }

    for (auto &[course, students] : courses)
        cout << course << " " << students.size() << "\n";
}