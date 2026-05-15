#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, value;
    cin >> size >> value;

    int sum = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
    }

    cout << (sum % 2 || size * value % 2 == 0 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}