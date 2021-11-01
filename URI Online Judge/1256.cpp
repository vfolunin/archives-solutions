#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size, queryCount;
    cin >> size >> queryCount;

    vector<vector<int>> hashTable(size);
    
    for (int i = 0; i < queryCount; i++) {
        int val;
        cin >> val;
        hashTable[val % size].push_back(val);
    }

    if (test)
        cout << "\n";
    for (int i = 0; i < hashTable.size(); i++) {
        cout << i;
        for (int j = 0; j < hashTable[i].size(); j++)
            cout << " -> " << hashTable[i][j];
        cout << " -> \\\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}