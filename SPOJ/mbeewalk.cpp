#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    static const vector<int> hexWalkCount = {
        1, 0, 6, 12, 90,
        360, 2040, 10080, 54810, 290640,
        1588356, 8676360, 47977776, 266378112, 1488801600
    };

    cout << hexWalkCount[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}