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

    vector<pair<string, int>> students(studentCount);

    for (int i = 0; i < studentCount; i++) {
        string surname, name;
        cin >> surname >> name;
        students[i].first = surname + " " + name;

        for (int j = 0; j < 3; j++) {
            int mark;
            cin >> mark;
            students[i].second += mark;
        }
    }

    stable_sort(students.begin(), students.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    for (auto &[name, mark] : students)
        cout << name << "\n";
}