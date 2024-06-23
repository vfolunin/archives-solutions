#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int maxValue = 0;
    for (int i = 0; i < 5; i++) {
        int value;
        cin >> value;
        maxValue = max(maxValue, value);
    }

    cout << "Case #" << test << ": " << maxValue << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}