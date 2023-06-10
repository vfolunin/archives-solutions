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

    vector<pair<int, string>> students;
    for (int i = 0; i < studentCount; i++) {
        string surname, name;
        int form, score;
        cin >> surname >> name >> form >> score;
        if (form == 50)
            students.push_back({ score, surname + " " + name });
    }

    stable_sort(students.begin(), students.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    if (students[0].first == students[2].first) {
        int res = 0;
        for (auto &[score, name] : students)
            res += score == students[0].first;

        cout << res;
    } else {
        cout << students[0].second << "\n";
        if (students[1].first > students[2].first)
            cout << students[1].second;
    }
}