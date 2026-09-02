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

    int xorSum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        xorSum ^= value % 4;
    }

    cout << (xorSum ? "first\n" : "second\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}