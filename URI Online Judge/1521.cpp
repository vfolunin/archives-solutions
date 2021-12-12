#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int studentCount;
    cin >> studentCount;

    if (!studentCount)
        return 0;

    vector<int> nextStudent(studentCount);
    for (int &ns : nextStudent) {
        cin >> ns;
        ns--;
    }

    int student;
    cin >> student;
    student--;

    while (student != nextStudent[student])
        student = nextStudent[student];

    cout << student + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}