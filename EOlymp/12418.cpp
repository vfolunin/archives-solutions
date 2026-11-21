#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long value, opCount;
    cin >> value >> opCount;

    for (int i = 0; i < opCount; i++) {
        if (value > 0)
            value *= 7;
        else
            value += 6;
    }

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