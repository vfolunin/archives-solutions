#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    string s(size, ' ');
    for (char &c : s) {
        do {
            c = cin.get();
        } while (c == '\n');
    }

    vector<pair<string, int>> rotations;
    for (int i = 0; i < s.size(); i++) {
        rotations.push_back({ s, i });
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    sort(rotations.begin(), rotations.end());

    int row;
    string lastCol;
    for (int i = 0; i < rotations.size(); i++) {
        lastCol += rotations[i].first.back();
        if (rotations[i].second == 1)
            row = i;
    }

    if (test)
        cout << "\n";
    cout << row << "\n";
    for (int i = 0; i < lastCol.size(); i++) {
        cout << lastCol[i];
        if (i % 50 == 49 || i + 1 == lastCol.size())
            cout << "\n";
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