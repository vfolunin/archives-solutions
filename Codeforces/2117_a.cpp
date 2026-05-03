#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, limit;
    cin >> size >> limit;

    int minPos = 1e9, maxPos = -1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value) {
            minPos = min(minPos, i);
            maxPos = max(maxPos, i);
        }
    }

    cout << (maxPos - minPos + 1 <= limit ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}