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

    vector<pair<string, string>> students(studentCount);
    for (auto &[surname, name] : students)
        cin >> surname >> name;

    stable_sort(students.begin(), students.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });

    cout << students.size() << "\n";
    for (auto &[surname, name] : students)
        cout << surname << " " << name << "\n";
}