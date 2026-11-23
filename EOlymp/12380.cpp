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

    bool odd = 0, canSwap = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        int remainder = value % 2;
        odd ^= remainder;

        for (char c : to_string(value))
            canSwap |= c % 2 != remainder;
    }

    cout << (!odd || canSwap ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}