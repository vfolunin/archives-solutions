#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int peopleCount, treeCount;
    cin >> peopleCount >> treeCount;
    cin.ignore();

    vector<set<int>> heardTrees(peopleCount);
    while (1) {
        string line;
        getline(cin, line);

        if (line.empty())
            break;

        stringstream ss(line);
        int pId, tId;
        ss >> pId >> tId;
        heardTrees[pId - 1].insert(tId - 1);
    }

    cout << set<set<int>>(heardTrees.begin(), heardTrees.end()).size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}