#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, a, b;
    cin >> size >> a >> b;

    if (b % a || size == 1 && a != b) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < size - 1; i++)
            cout << a << " ";
        cout << b << "\n";
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