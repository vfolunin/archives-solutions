#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    for (long long size = 1; size <= n; size++) {
        long long cells = size * size;
        long long totalPairs = cells * (cells - 1) / 2;
        long long attackingPairs = (size - 1) * (size - 2) * 4;
        cout << totalPairs - attackingPairs << "\n";
    }
}