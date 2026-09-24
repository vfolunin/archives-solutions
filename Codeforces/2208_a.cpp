#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    unordered_map<int, int> count;
    int maxCount = 0;
    for (int i = 0; i < size * size; i++) {
        int value;
        cin >> value;

        maxCount = max(maxCount, ++count[value]);
    }

    cout << (maxCount <= size * (size - 1) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}