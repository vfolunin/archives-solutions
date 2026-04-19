#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int factor, size, mod;
    cin >> factor >> size >> mod;

    for (int i = 0; i < size; i++) {
        int sum = 0, maxValue = 0;
        for (int j = 0; 1; j++) {
            int value;
            cin >> value;

            if (value == -1)
                break;

            sum = (sum * factor + value) % mod;
            maxValue = max(maxValue, value);
        }

        cout << (!sum && maxValue < factor);
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}