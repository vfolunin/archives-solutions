#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a.first > b.first;
}

bool solve(int test) {
    int studentCount;
    if (!(cin >> studentCount))
        return 0;

    vector<pair<string, int>> students(studentCount);
    for (auto &[name, score] : students)
        cin >> name >> score;

    cout << "Instancia " << test << "\n";
    cout << min_element(students.begin(), students.end(), compare)->first << "\n";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}