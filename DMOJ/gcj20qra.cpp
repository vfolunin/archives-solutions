#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    int trace = 0;
    for (int i = 0; i < a.size(); i++)
        trace += a[i][i];

    int rows = 0;
    for (int y = 0; y < a.size(); y++) {
        unordered_set<int> values;
        for (int x = 0; x < a.size(); x++)
            values.insert(a[y][x]);
        rows += values.size() < a.size();
    }

    int cols = 0;
    for (int x = 0; x < a.size(); x++) {
        unordered_set<int> values;
        for (int y = 0; y < a.size(); y++)
            values.insert(a[y][x]);
        cols += values.size() < a.size();
    }

    cout << "Case #" << test << ": " << trace << " " << rows << " " << cols << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}