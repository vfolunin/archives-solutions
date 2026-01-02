#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int typeCount;
    cin >> typeCount;

    unordered_map<string, int> type;
    for (int i = 0; i < typeCount; i++) {
        string s;
        cin >> s;

        type[s] = i;
    }

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    vector<int> order(a.size());
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        return type[a[lhs]] < type[a[rhs]];
    });

    for (int i : order)
        cout << i + 1 << "\n";
}