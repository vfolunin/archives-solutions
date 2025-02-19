#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<pair<int, int>> pairs(size);
    for (auto &[a, b] : pairs)
        cin >> a >> b;

    stable_sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    for (auto &[a, b] : pairs)
        cout << a << " " << b << "\n";
}