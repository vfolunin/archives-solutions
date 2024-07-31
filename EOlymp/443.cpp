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

    int size, count;
    cin >> size >> count;

    vector<pair<string, int>> a(size);
    for (auto &[s, value] : a)
        cin >> s >> value;

    sort(a.begin(), a.end(), [](auto &lhs, auto &rhs) {
        return lhs.second < rhs.second;
    });

    sort(a.begin(), a.begin() + count);

    for (int i = 0; i < count; i++)
        cout << a[i].first << "\n";
}