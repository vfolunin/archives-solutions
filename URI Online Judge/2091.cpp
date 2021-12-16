#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    long long xorSum = 0;
    for (int i = 0; i < size; i++) {
        long long x;
        cin >> x;
        xorSum ^= x;
    }

    cout << xorSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}