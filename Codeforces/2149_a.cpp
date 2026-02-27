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

    int zeroCount = 0, negativeCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        zeroCount += !value;
        negativeCount += value < 0;
    }

    cout << zeroCount + (negativeCount % 2 ? 2 : 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}