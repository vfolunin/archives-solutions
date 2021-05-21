#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long size, shift;
    char direction;
    if (!(cin >> size >> shift >> direction))
        return 0;

    shift %= size;
    if (direction == 'R')
        shift = size - shift;

    cin.ignore();
    vector<string> a(3);
    for (string &row : a)
        getline(cin, row);

    a[1].pop_back();
    rotate(a[1].begin(), a[1].begin() + shift * 2, a[1].end());
    a[1].push_back('|');

    for (string &row : a)
        cout << row << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}