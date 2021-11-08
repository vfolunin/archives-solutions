#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int totalTreeCount = 0;
    map<string, int> treeCount;

    while (1) {
        string name;
        getline(cin, name);
        if (name.empty())
            break;

        totalTreeCount++;
        treeCount[name]++;
    }

    if (test)
        cout << "\n";
    for (auto &[name, count] : treeCount)
        cout << name << " " << (double)count / totalTreeCount * 100 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();

    cout.precision(4);
    cout << fixed;
    for (int i = 0; i < n; i++)
        solve(i);
}