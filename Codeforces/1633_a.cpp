#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int value;
    cin >> value;

    if (value % 7 == 0) {
        cout << value << "\n";
        return;
    }

    value = value / 10 * 10;
    while (value % 7)
        value++;

    cout << value << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}