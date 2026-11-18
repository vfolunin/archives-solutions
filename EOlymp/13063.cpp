#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long size;
    cin >> size;

    if (size * (size + 1) / 2 % (size + 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 2; i <= size; i++)
            cout << i << " ";
        cout << "1\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}