#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string name, buf;
    int enrollYear, birthYear, semesterCount;
    cin >> name >> enrollYear >> buf >> birthYear >> buf >> semesterCount;

    cout << name << " ";
    if (enrollYear >= 2010 || birthYear >= 1991)
        cout << "eligible\n";
    else if (semesterCount > 40)
        cout << "ineligible\n";
    else
        cout << "coach petitions\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}