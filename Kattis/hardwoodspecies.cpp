#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
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

    for (auto &[name, count] : treeCount)
        cout << name << " " << fixed << (double)count / totalTreeCount * 100 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}