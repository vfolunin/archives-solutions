#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, limit;
    cin >> size >> limit;

    long long sum = 0, maxValue = 0;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        sum += value;
        maxValue = max(maxValue, value);
    }

    cout << max((sum + limit - 1) / limit, maxValue) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}