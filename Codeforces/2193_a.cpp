#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, targetSum, delta;
    cin >> size >> targetSum >> delta;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    cout << (targetSum >= sum && (targetSum - sum) % delta == 0 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}