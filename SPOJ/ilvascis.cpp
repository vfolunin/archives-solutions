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

    vector<pair<string, int>> a(size);
    for (auto &[name, age] : a)
        cin >> name >> age;

    sort(a.begin(), a.end(), [](auto &lhs, auto &rhs) {
        return lhs.second > rhs.second;
    });

    cout << "Case #" << test << ":\n";
    for (auto &[name, _] : a)
        cout << name << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}