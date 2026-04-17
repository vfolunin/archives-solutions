#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    int prevValue, value = -1, zeroCount = 0, hasLiar = 0;
    for (int i = 0; i < size; i++) {
        prevValue = value;
        cin >> value;

        zeroCount += !value;
        hasLiar |= !prevValue && !value;
    }

    hasLiar |= !zeroCount;

    cout << (hasLiar ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}