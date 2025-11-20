#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(vector<int> &count) {
    static map<vector<int>, int> memo;
    if (memo.count(count))
        return memo[count];

    static vector<vector<int>> moves = {
        { 2, 1, 0, 2 },
        { 1, 1, 1, 1 },
        { 0, 0, 2, 1 },
        { 0, 3, 0, 0 },
        { 1, 0, 0, 1 }
    };

    for (vector<int> &move : moves) {
        vector<int> nextCount = count;
        bool ok = 1;
        for (int i = 0; i < nextCount.size(); i++) {
            if (nextCount[i] >= move[i])
                nextCount[i] -= move[i];
            else
                ok = 0;
        }
        if (ok && rec(nextCount) == 2)
            return memo[count] = 1;
    }

    return memo[count] = 2;
}

void solve() {
    vector<int> count(4);
    for (int &value : count)
        cin >> value;

    cout << (rec(count) == 1 ? "Patrick\n" : "Roland\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}