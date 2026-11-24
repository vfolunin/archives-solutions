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

    long long sum = 0, curSum = 0, minSum = 0;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        sum += value;
        curSum = min(curSum + value, value);
        minSum = min(minSum, curSum);
    }

    cout << sum - minSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}