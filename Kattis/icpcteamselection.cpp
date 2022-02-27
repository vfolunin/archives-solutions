#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int teamCount;
    cin >> teamCount;

    vector<int> students(3 * teamCount);
    for (int &student : students)
        cin >> student;

    sort(students.rbegin(), students.rend());

    int res = 0;
    for (int i = 0; i < teamCount; i++)
        res += students[i * 2 + 1];

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}